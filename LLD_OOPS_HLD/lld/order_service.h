#ifndef ORDER_SERVICE_H
#define ORDER_SERVICE_H

#include "interfaces.h"

class OrderService {
private:
    INotifier* notifier;
    ILogger* logger;
    IInventory* inventory;
public:
    OrderService(
        INotifier* notifier,
        ILogger* logger,
        IInventory* inventory
    );
    void placeOrder(int orderId);
};



#endif
