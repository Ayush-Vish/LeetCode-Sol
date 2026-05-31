#include "order_service.h"
OrderService::OrderService(
    INotifier* notifier,
    ILogger* logger,
    IInventory* inventory
) : notifier(notifier), logger(logger), inventory(inventory) {}

void OrderService::placeOrder(int orderId) {
    inventory->updateStock(orderId);
    notifier->send("Order placed");
    logger->log("Order placed");
}
