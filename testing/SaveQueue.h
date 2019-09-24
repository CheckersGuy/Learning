//
// Created by robin on 17.09.19.
//

#ifndef TESTING_SAVEQUEUE_H
#define TESTING_SAVEQUEUE_H


#include <optional>
#include <deque>
#include <condition_variable>

/*
 * The mutable specifier allows changing member variables even
 * when the surrounding object is declared const
 *
 *
 */

template<typename T>
class SaveQueue {

private:
    mutable std::mutex mutex;
    std::condition_variable condVar;
    std::deque<T> schlange;

public:
    std::optional<T> try_pop() {
        std::optional<T> result;
        std::lock_guard lock(mutex);
        if (!schlange.empty()) {
            result = schlange.front();
            schlange.pop_front();
        }
        return result;
    }

    std::optional<T> wait_and_pop() {
        std::optional<T> result;
        std::unique_lock lock(mutex);
        condVar.wait(lock, [this]() {
            return !schlange.empty();
        });
        result = schlange.front();
        schlange.pop_front();
        return result;
    }

    bool empty() const {
        std::lock_guard lock(mutex);
        return schlange.empty();
    }

    size_t size() const {
        std::lock_guard lock(mutex);
        return schlange.size();
    }
    //type cant be deduced since it's already declared
    void push(T&& val) {
        std::lock_guard lock(mutex);
        schlange.push_back(val);
        condVar.notify_one();
    }

    void push(T& val) {
        std::lock_guard lock(mutex);
        schlange.push_back(val);
        condVar.notify_one();
    }



};


#endif //TESTING_SAVEQUEUE_H
