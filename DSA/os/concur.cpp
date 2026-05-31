#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_safely(int id) {
    mtx.lock();
    std::cout << "Thread " << id << " is running\n";
    mtx.unlock();
}

int main() {
    std::thread t1(print_safely, 1);
    std::thread t2(print_safely, 2);
    t1.join();
    t2.join();
    std::thread t3([](){
      std::cout << "I amnder the wahter ";
    });
    std::thread t4([](){
      std::cout << "I amnder the wahter  212 ";
    });

    t3.join();
    t4.join();
}
