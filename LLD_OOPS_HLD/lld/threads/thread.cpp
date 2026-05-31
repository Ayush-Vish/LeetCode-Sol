#include <iostream>
#include <thread>
#include <mutex>

std::mutex mu;

void printA() {
      std::lock_guard<std::mutex>lock(mu);
    std::cout << "Hello from A lorem ipsum dolor sit amet consectetur adipisicing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua lorem ipsum dolor sit amet consectetur adipisicing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua\n";
}

void printB() {
      std::lock_guard<std::mutex>lock(mu);
    std::cout << "Hello from B lorem ipsum dolor sit amet consectetur adipisicing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua \n";
}

int main() {
    std::thread t1(printA);
    std::thread t2(printB);
    t1.join();
    t2.join();
}
