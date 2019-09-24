//
// Created by robin on 17.09.19.
//

#ifndef TESTING_THREADPOOL_H
#define TESTING_THREADPOOL_H

#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <iostream>
#include <future>

class ThreadPool {

private:
    const size_t numThreads;
    std::vector<std::thread> threads;
    std::deque<std::function<void()>> work;
    std::mutex myMutex;
    std::condition_variable condVar;
    bool stop;

    void idleLoop();

public:

    ThreadPool(size_t numThreads);

    ThreadPool(const ThreadPool &other) = delete;

    ThreadPool &operator=(const ThreadPool &other) = delete;

    ~ThreadPool() {
        shutdown();
    }

    template<typename F, typename...Args>
    auto submit(F &&func, Args &&... args) -> std::future<decltype(func(args...))> {
        std::lock_guard lock(myMutex);
        auto task = std::make_shared<std::packaged_task<decltype(func(args...))(Args...)>>(func);
        std::function<void()> wrapper = [&args..., task]() {
            task->operator()(std::forward<Args>(args)...);
        };
        work.emplace_back(wrapper);
        condVar.notify_one();
        return task->get_future();
    }

    size_t threadCount() const;

    void shutdown();

};


#endif //TESTING_THREADPOOL_H
