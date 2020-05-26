//
// Created by root on 04.02.20.
//

#ifndef TESTING_EVENTHANDLER_H
#define TESTING_EVENTHANDLER_H


//A simple class which will execute functions (with no return time)
//at a specific point in time

#include <cstdint>
#include <functional>
#include <thread>
#include <atomic>

struct Event{
    uint64_t time_stamp;
    std::function<void()> function;
    void operator()(){
        function();
    }
};

class EventHandler {

private:
    std::vector<Event> events;
    std::thread native_thread;
    std::atomic<bool> stop{false};
    static constexpr uint64_t response_time =100;
public:


    void idleLoop(){
        while(true){
            if(stop.load())
                break;

            //getting the top entry, starting another thread and execute


            std::this_thread::sleep_for(std::chrono::milliseconds(response_time));
        }
    }

    template<typename... Args, typename Function> void submit(Function func, Args&&... args,uint64_t time_stamp){
        //Will be using a heap to only check the top entry
        Event event;

        std::function<void()> wrapper=[&args...,func](){
            func(std::forward<Args>(args)...);
        };
        event.function=wrapper;
        events.emplace_back(event);
    }




};


#endif //TESTING_EVENTHANDLER_H
