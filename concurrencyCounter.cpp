#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <stdexcept>

// Global synchronization primitives
std::mutex mtx;                 // Mutex lock for critical section
std::condition_variable cv;     // Condition variable for thread synchronization
bool countUpFinished = false;   // Flag to indicate when counting is finished

// Function to count up from 0 to 20
void countUp() {
    try {
        for (int i = 0; i <= 20; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulates work being done to demonstrate synchronization concept
            std::cout << "Counting up: " << i << std::endl;
        }
        {
            std::lock_guard<std::mutex> lock(mtx);  // Lock mutex to update the flag
            countUpFinished = true;
        }
        cv.notify_one();    // Notify the waiting thread that counting up is finished
    } catch (const std::exception& e) {
        std::cerr << "Exception in countUp: " << e.what() << std::endl; // Handle exceptions
    }
}

// Function to count down from 20 to 0
void countDown() {
    try {
        std::unique_lock<std::mutex> lock(mtx);         //Acquire mutex lock
        cv.wait(lock, [] { return countUpFinished;});   // Waits until countUp is finished
        for (int i = 20; i >= 0; --i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));    // Simulates work being done to demonstrate synchronization concept
            std::cout << "Counting down: " << i << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception in countDown: " << e.what() << std::endl;   // Hnadle exceptions
    }
}

int main() {
    try {
        // Create and start threads for counting up and down
        std::thread t1(countUp);
        std::thread t2(countDown);

        // Wait for both threads to finish
        t1.join();
        t2.join();
    } catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;    // Handle exceptions
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
