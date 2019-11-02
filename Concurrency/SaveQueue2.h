//
// Created by robin on 09.10.19.
//

#ifndef TESTING_SAVEQUEUE2_H
#define TESTING_SAVEQUEUE2_H

#include <optional>
#include <mutex>
#include <condition_variable>

template<typename T>
class SaveQueue {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;

        Node(T data) : data(data) {}

        Node() = default;
    };

    std::unique_ptr<Node> head;
    Node *tail;
    mutable std::mutex tailMutex;
    mutable std::mutex headMutex;
    std::condition_variable condVar;


    Node *getTail() const {
        std::lock_guard lock(tailMutex);
        return tail;
    }

    std::unique_ptr<Node> popHead() {
        auto old_head = std::move(head);
        head = std::move(old_head->next);
        return old_head;
    }

    std::unique_lock<std::mutex> wait_for_data() {
        std::unique_lock lock(headMutex);
        condVar.wait(lock, [&]() {
            return head.get() != getTail();
        });
        return std::move(lock);
    }

    std::unique_ptr<Node> try_pop_head() {
        std::lock_guard lock(headMutex);
        if (head.get() == getTail())
            return nullptr;
        return popHead();
    }

    std::unique_ptr<Node> wait_pop_head() {
        std::unique_lock lock(wait_for_data());
        return popHead();
    }

public:

    SaveQueue(const SaveQueue &) = delete;

    SaveQueue &operator=(const SaveQueue &) = delete;

    SaveQueue(SaveQueue &&) = delete;

    SaveQueue() : head(std::make_unique<Node>()), tail(head.get()) {}


    void push(T value) {
        auto dummy = std::make_unique<Node>(value);
        std::lock_guard lock(tailMutex);
        Node *newtail = dummy.get();
        tail->data = value;
        tail->next = std::move(dummy);
        tail = newtail;
        condVar.notify_one();
    }

    std::optional<T> tryPop() {
        auto head = try_pop_head();
        return (head.get() != nullptr) ? std::make_optional(head->data) : std::nullopt;
    }

    T wait_and_pop() {
        auto old_head = wait_pop_head();
        return old_head->data.value();
    }


    bool empty() const {
        std::lock_guard lock(headMutex);
        return head.get() == getTail();
    }


};


#endif //TESTING_SAVEQUEUE2_H
