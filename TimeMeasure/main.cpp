#include <iostream>
#include <chrono>
#include <thread>

int main(int argl, const char **argc) {

    //measuring elapsed time and dealing with points in time is very important
    //here are some examples how some of this can be achieved using std::chrono

    auto start = std::chrono::high_resolution_clock::now();
    //simulating some arbitrary computation
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> dur = end - start;
    time_t end_time = std::chrono::high_resolution_clock::to_time_t(end);
    std::cout << "Computation was finished at " << std::ctime(&end_time) << std::endl;
    std::cout << "The computation took: " << dur.count() << std::endl;

    return 0;
}
