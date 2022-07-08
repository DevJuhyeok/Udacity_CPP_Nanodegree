#include <iostream>
#include <random>
#include "TrafficLight.h"
#include <future>

/* Implementation of class "MessageQueue" */


template <typename T>
T MessageQueue<T>::receive()
{
    // FP.5a : The method receive should use std::unique_lock<std::mutex> and _condition.wait() 
    // to wait for and receive new messages and pull them from the queue using move semantics. 
    // The received object should then be returned by the receive function. 
    
    std::unique_lock<std::mutex> lck(_mutex);
    _condition.wait(lck, [this]{return !_queue.empty();});

    T msg = std::move(_queue.front());
    _queue.pop_front();

    return msg;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    // FP.4a : The method send should use the mechanisms std::lock_guard<std::mutex> 
    // as well as _condition.notify_one() to add a new message to the queue and afterwards send a notification.
    
    // lock 
    std::lock_guard<std::mutex> lck(_mutex); 

    _queue.emplace_back(msg); // add message to Queue
    _condition.notify_one(); // add a new message to the queue and afterwards send notification.
}


/* Implementation of class "TrafficLight" */


TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen()
{
    // FP.5b : add the implementation of the method waitForGreen, in which an infinite while-loop 
    // runs and repeatedly calls the receive function on the message queue. 
    // Once it receives TrafficLightPhase::green, the method returns.

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        auto msg = _messageQueue.receive();
        if(msg == green){
            return;
        }
    }
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::simulate()
{
    // FP.2b : Finally, the private method „cycleThroughPhases“ should be started in a thread when the public method „simulate“ is called. To do this, use the thread queue in the base class. 
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}

// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases()
{
    // FP.2a : Implement the function with an infinite loop that measures the time between two loop cycles 
    // and toggles the current phase of the traffic light between red and green and sends an update method 
    // to the message queue using move semantics. The cycle duration should be a random value between 4 and 6 seconds. 
    // Also, the while-loop should use std::this_thread::sleep_for to wait 1ms between two cycles. 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(4,6); // make random seed using random lib,, it use milliseconds value

    int cycle_duration = dist(gen);
    
    auto prev_time = std::chrono::system_clock::now();

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        auto current_time = std::chrono::system_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - prev_time); // end time - start time
        int duration_count = elapsed_time.count();

        if(duration_count >= cycle_duration)
        {
            // toggle for phase
            if (_currentPhase == red) _currentPhase = green;
            else _currentPhase = red;

            _messageQueue.send(std::move(_currentPhase));

            // update previous time to use next loop
            prev_time = std::chrono::system_clock::now();
            cycle_duration = dist(gen);
        }

        
    }

}

