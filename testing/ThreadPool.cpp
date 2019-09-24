//
// Created by robin on 17.09.19.
//

#include "ThreadPool.h"


ThreadPool::ThreadPool(size_t numThreads) : numThreads(numThreads), stop(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        threads.emplace_back(std::thread(&ThreadPool::idleLoop, this));
    }
}

void ThreadPool::idleLoop() {
    while (true) {
        std::unique_lock lock(myMutex);
        condVar.wait(lock, [this]() { return !work.empty() || stop; });
        if (stop)
            break;
        auto task = work.front();
        work.pop_front();
        lock.unlock();
        task();
    }
}

void ThreadPool::shutdown() {
    stop = true;
    condVar.notify_all();
    for (auto &th : threads) {
        th.join();
    }
}




size_t ThreadPool::threadCount() const {
    return numThreads;
}