#include <cassert>
#include <iostream>

#include "order_service.h"
#include "interfaces.h"
class MockNotifier : public INotifier {
public:
    bool sendCalled = false;
    std::string lastMessage;

    void send(const std::string& msg) override {
        sendCalled = true;
        lastMessage = msg;
    }
};

class MockLogger : public ILogger {
public:
    bool logCalled = false;
    std::string lastLog;

    void log(const std::string& msg) override {
        logCalled = true;
        lastLog = msg;
    }
};

class MockInventory : public IInventory {
public:
    bool updateCalled = false;
    int lastOrderId = -1;

    void updateStock(int orderId) override {
        updateCalled = true;
        lastOrderId = orderId;
    }
};

int main() {
    // Arrange
    MockNotifier notifier;
    MockLogger logger;
    MockInventory inventory;

    OrderService service(&notifier, &logger, &inventory);

    // Act
    service.placeOrder(101);

    // Assert
    assert(inventory.updateCalled);
    assert(inventory.lastOrderId == 101);

    assert(notifier.sendCalled);
    assert(notifier.lastMessage == "Order placed");

    assert(logger.logCalled);
    assert(logger.lastLog == "Order placed");

    std::cout << "✅ Unit test passed\n";
    return 0;
}
