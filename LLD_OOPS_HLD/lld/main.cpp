#include "order_service.h"
#include "implementations.h"

int main() {
    EmailNotifier emailNotifier;
    DatabaseLogger databaseLogger;
    InventorySystem inventorySystem;

    OrderService orderService(
        &emailNotifier,
        &databaseLogger,
        &inventorySystem
    );
    orderService.placeOrder(1);
    return 0;
}
/**
 * 
 * 
 * Instead of passing the object Direclty to the constructor of OrderService,
 * we are doing like 
 * INotifier* notifier = new EmailNotifier();
 * and in the OrderService we have a field of type INotifier* notifier;
 * Then in the constructor of OrderService we do
 * OrderService::OrderService(INotifier* notifier, ...) : notifier(notifier) {}
 * This is called Dependency Injection.
 */
