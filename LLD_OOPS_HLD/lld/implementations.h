#ifndef IMPLEMENTATIONS_H
#define IMPLEMENTATIONS_H
#include "interfaces.h"
#include <iostream>
class EmailNotifier : public INotifier {
public:
    void send(const std::string& mes) override {
        std::cout << "Sending Email: " << mes << std::endl;
    }
};

class DatabaseLogger : public ILogger {
public:
    void log(const std::string& msg) override {
        std::cout << "Logging to Database: " << msg << std::endl;
    }   
};
class InventorySystem : public IInventory {
public:
    void updateStock(int orderId) override {
        std::cout << "[Inventory] Updated for order " << orderId << std::endl;
    }
};



#endif
