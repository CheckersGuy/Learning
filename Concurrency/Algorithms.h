//
// Created by root on 30.01.20.
//

#ifndef TESTING_ALGORITHMS_H
#define TESTING_ALGORITHMS_H


//A couple of parallel-algorithms

#include <iterator>
#include <thread>
#include <vector>
#include <future>
#include <algorithm>


template<typename Iter, typename Function>
void parallel_for(Iter begin, Iter end, Function func, size_t num_threads = std::thread::hardware_concurrency()) {
    struct thread_waiter {
        std::vector<std::thread> &threads;


        ~thread_waiter() {
            for (auto &th : threads)
                th.join();
        }
    };
    num_threads = num_threads - 1u;

    auto data_size = std::distance(begin, end);
    if (data_size == 0)
        return;
    auto block_size = data_size / (num_threads + 1);
    num_threads = (block_size == 0) ? data_size - 1 : num_threads;
    block_size = (block_size == 0) ? 1 : block_size;
    std::vector<std::thread> threads;
    std::vector<std::future<void>> futures;
    thread_waiter waiter{threads};
    auto begin_block = begin;
    for (auto i = 0; i < num_threads; ++i) {
        auto end_block = begin_block;
        std::advance(end_block, block_size);

        std::packaged_task<void()> task([=]() {
            std::for_each(begin_block, end_block, func);
        });
        futures.emplace_back(task.get_future());
        threads.emplace_back(std::thread(std::move(task)));
        begin_block = end_block;
    }
    std::for_each(begin_block, end, func);
    for (auto &fu : futures) {
        fu.get();
    }
}

template<typename Iter, typename Compare>
Iter parallel_find_if(Iter begin, Iter end, Compare comp, size_t num_threads = std::thread::hardware_concurrency()) {
    struct thread_waiter {
        std::vector<std::thread> &threads;


        ~thread_waiter() {
            for (auto &th : threads)
                th.join();
        }
    };
    if (begin == end)
        return end;


    std::promise<Iter> result;
    auto future = result.get_future();
    std::atomic<bool> found_entry{false};

    auto lambda = [&result, &found_entry, comp](auto b, auto e) {
        try {
            for (auto it = b; it != e && !found_entry.load(); it++) {
                if (comp(*it)) {
                    result.set_value(it);
                    found_entry = true;
                    break;
                }
            }
        } catch (...) {
            try {
                result.set_exception(std::current_exception());
            } catch (...) {}
        }
    };
    num_threads = num_threads - 1u;
    auto data_size = std::distance(begin, end);
    auto block_size = data_size / (num_threads + 1);
    num_threads = (block_size == 0) ? data_size - 1 : num_threads;
    block_size = (block_size == 0) ? 1 : block_size;

    std::vector<std::thread> workers;
    thread_waiter waiter{workers};
    auto begin_block = begin;
    for (auto i = 0; i < num_threads; ++i) {
        auto end_block = begin_block;
        std::advance(end_block, block_size);
        workers.emplace_back(std::thread(lambda, begin_block, end_block));
        begin_block = end_block;
    }
    lambda(begin_block, end);
    return future.get();

}

#endif //TESTING_ALGORITHMS_H
