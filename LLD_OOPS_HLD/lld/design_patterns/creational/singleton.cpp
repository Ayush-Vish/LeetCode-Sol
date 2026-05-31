#include <iostream>
#include <string>
#include <chrono>
#include <ctime> // Required to convert chrono to readable time

using namespace std;

class Logger {
private:
    Logger() {
        cout << "Logger initialized" << endl;
    }

public:
    // Corrected Deletions
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const string& msg) {
      time_t now = time(0);
      char* dt = ctime(&now);
      cout << "[LOG] " << dt << " -> " << msg << endl;
  }
};

int main() {
    Logger& logger = Logger::getInstance();
    logger.log("Application started");

    Logger& logger1 = Logger::getInstance();
    logger1.log("User action captured");

    // Address check to prove it's the same instance
    cout << "Logger 0 address: " << &logger << endl;
    cout << "Logger 1 address: " << &logger1 << endl;

    return 0;
}
