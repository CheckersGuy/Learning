//
// Created by robin on 17.10.19.
//

#ifndef TESTING_SAVELIST_H
#define TESTING_SAVELIST_H

#include <memory>
#include <mutex>

template<typename T>
class SaveList {

private:

    struct Node {
        std::mutex mutex;
        std::unique_ptr<Node> next;
        T data;

        Node(T value) : data(value) {}

        Node() = default;
    };

    //Rest of the implementation goes here
    Node head;

public:

    SaveList() = default;

    ~SaveList() = default;

    void push(T value) {
        //pushes the value on the list
        auto new_value = std::make_unique<Node>(value);
        std::lock_guard lock(head.mutex);
        new_value->next = std::move(head.next);
        head.next = std::move(new_value);
    }

    template<typename Function>
    void for_each(Function func) {
        Node *current = &head;
        std::unique_lock lock(head.mutex);
        while (auto next = current->next.get()) {
            std::unique_lock nLock(next->mutex);
            lock.unlock();
            func(next->data);
            current = next;
            lock = std::move(nLock);
        }

    }

    template<typename Predicate> std::optional<T> find_first(Predicate p ){
        Node* current=&head;
        std::unique_lock lock(head.mutex);
        while(const Node* next=current->next.get()){
            std::unique_lock nLock(current->mutex);
            lock.unlock();
            if(p(current->data)){
                return std::make_unique<T>(current->data);
            }
            current=next;
            lock=std::move(nLock);
        }
        return std::nullopt;
    }

    template<typename Predicate> void remove_if(Predicate p){
        Node* current=&head;
        std::unique_lock lock(head.mutex);
        while(Node* next=current->next.get()){
            std::unique_lock nLock(next->mutex);
            if(p(next->data)){
                auto node=std::move(current->next);
                current->next=std::move(node->next);
                nLock.unlock();
            }else{
                lock.unlock();
                current=next;
                lock=std::move(nLock);
            }
        }
    }

    bool isEmpty(){
        std::lock_guard(head.mutex);
        return head.next.get()== nullptr;
    }


};


#endif //TESTING_SAVELIST_H
