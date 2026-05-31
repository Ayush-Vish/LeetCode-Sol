#ifndef INTERFACES_H
#define INTERFACES_H

#include <string>
class INotifier {
public:
    virtual void send(const std::string& mes) = 0;
    virtual ~INotifier() = default;
};

class ILogger {
public:
    virtual void log(const std::string& msg) = 0;
    virtual ~ILogger() = default;
};

class IInventory {
public:
    virtual void updateStock(int orderId) = 0;
    virtual ~IInventory() = default;
};

#endif
