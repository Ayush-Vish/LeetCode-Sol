#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdexcept>

using namespace std;

/**
 * 
 * Intervireeer: Can you solve the parking lot problem?
 * 
 * ok So here is my understainding of the problem.
 * 
 * - the system manages different Vehicles
 * - each vehicle will entry and exit the parking lot at different times
 * - the cost will be calculated based on the time the vehicle spends in the parking lot
 * - different Vehicle types will have Different slots 
 * - 
 *
 * Clarification of the Requirements:
 * - Support for different types of vehicles (e.g., cars, motorcycles, trucks).
 * - allow mutiple payments methods (e.g., cash, credit card, mobile payment).
 * - real-time tracking of available parking spaces.
 * - Dynamic slot allocation based on vehicle type and availability.
 * 
 * Identification of the Main Components:
 * - Vehicle class -> represt the vehicle and its attributes (e.g., license plate, entry time, exit time).
 * - ParkingLot class -> contains the logic for managing parking spaces, calculating costs, and handling payments.
 * - Payment Class-> to handle different payment methods and transactions.
 * - Slot class -> to represent individual parking spaces and their availability.
 * 
 * 
 * 
 */

/**
 * ok now which Design Pattern I will use 
 * 
 * - for Payment I will use Strategy Pattern to allow for different payment methods.
 * - Singlton pattern for the ParkingLot class to ensure there is only one instance managing the parking spaces.
 * - Factory pattern for creating different types of vehicles and slots based on the requirements.
 * - Strgaty pattern for different Pricing strategies based on the vehicle type and duration of parking can be hourly, 
 * daily, or flat rate.
 * - Observer Pattern for real-time tracking of available parking spaces, where the ParkingLot class can notify observers (e.g., a display system) about changes in slot availability.
 * 
 * 
 */

// ==========================================
// STRATEGY PATTERN: Payment Strategies
// ==========================================

class PaymentStrategy {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentStrategy() = default;
};

class CashPayment : public PaymentStrategy {
public:
    void processPayment(double amount) override {
        cout << "Processing cash payment of $" << amount << "\n";
    }
};

class UPIPayment : public PaymentStrategy {
public:
    void processPayment(double amount) override {
        cout << "Processing UPI payment of $" << amount << "\n";
    }
};

class Payment {
    PaymentStrategy* strategy;
public:
    Payment(PaymentStrategy* strategy) : strategy(strategy) {}
    
    void processPayment(double amount) {
        this->strategy->processPayment(amount);
    }
};  

// ==========================================
// STRATEGY PATTERN: Pricing Strategies
// ==========================================

class PricingStrategy {
public:
    virtual double calculateCost(string vehicleType, int duration, string pricingType) = 0;
    virtual ~PricingStrategy() = default;
};

class PremiumPricing : public PricingStrategy {
public:
    double calculateCost(string vehicleType, int duration, string pricingType) override {
        cout << "Calculating premium pricing for vehicle type: " << vehicleType << "\n";
        return duration * 20.0; // Example premium rate: $20/hr
    }
};

class HourlyPricing : public PricingStrategy {
public:
    double calculateCost(string vehicleType, int duration, string pricingType) override {
        cout << "Calculating hourly pricing for vehicle type: " << vehicleType << "\n";
        return duration * 10.0; // Example hourly rate: $10/hr
    }
};

// ==========================================
// ENTITIES: Vehicles
// ==========================================

class Vehicle {
public:
    string licensePlate;
    string type; // e.g., car, motorcycle, truck
    time_t entryTime;
    time_t exitTime;
    PricingStrategy* pricingStrategy;

    Vehicle(string type, string licensePlate, PricingStrategy* pricingStrategy) {
        this->type = type;
        this->licensePlate = licensePlate;
        this->entryTime = time(0); // current time
        this->pricingStrategy = pricingStrategy;
    }
    
    virtual ~Vehicle() = default;

    double calculateCost(int duration, string pricingType) {
        return pricingStrategy->calculateCost(this->type, duration, pricingType);
    }
};

class Truck : public Vehicle {
public:
    Truck(string licensePlate, PricingStrategy* pricingStrategy) 
        : Vehicle("truck", licensePlate, pricingStrategy) {}
};

class Motorcycle : public Vehicle {
public:    
    Motorcycle(string licensePlate, PricingStrategy* pricingStrategy) 
        : Vehicle("motorcycle", licensePlate, pricingStrategy) {}
};

class Car : public Vehicle {
public:    
    Car(string licensePlate, PricingStrategy* pricingStrategy) 
        : Vehicle("car", licensePlate, pricingStrategy) {}
};

// ==========================================
// ENTITIES: Slots
// ==========================================

class Slot {
public:
    string type; // e.g., car, motorcycle, truck
    bool isAvailable;
    int slotNumber;
    Vehicle* parkedVehicle;

    Slot(string type, bool isAvailable, int slotNumber) 
        : type(type), isAvailable(isAvailable), slotNumber(slotNumber), parkedVehicle(nullptr) {}
    
    virtual ~Slot() = default;

    bool isSlotAvailable() const {
        return isAvailable;
    }

    void parkVehicle(Vehicle* vehicle) {
        if (isAvailable) {
            parkedVehicle = vehicle;
            isAvailable = false;
        } else {
            cout << "Slot is not available\n";
        }
    }

    void removeVehicle() {
        if (!isAvailable) {
            parkedVehicle = nullptr;
            isAvailable = true; 
        } else {
            cout << "Slot is already empty\n";
        }
    }
};

class CarSlot : public Slot {
public:    
    CarSlot(int slotNumber) : Slot("car", true, slotNumber) {}
};

class MotorcycleSlot : public Slot {
public:    
    MotorcycleSlot(int slotNumber) : Slot("motorcycle", true, slotNumber) {}
};

// ==========================================
// PARKING LOT SYSTEM
// ==========================================

class ParkingLot {
public:
    vector<Slot*> slots; // Fixed object slicing by using pointers

    ParkingLot() {}
    ParkingLot(vector<Slot*> slots) : slots(slots) {}
    
    Slot* findAvailableSlot(string vehicleType) {
        for (auto slot : slots) {
            if (slot->type == vehicleType && slot->isSlotAvailable()) {
                return slot;
            }
        }
        return nullptr; // No available slot found
    }
    
    Slot* parkVehicle(Vehicle* vehicle) {
        Slot* availableSlot = findAvailableSlot(vehicle->type);
        if (availableSlot != nullptr) {
            availableSlot->parkVehicle(vehicle);
            cout << "Successfully parked " << vehicle->type << " (" << vehicle->licensePlate << ") at slot number: " << availableSlot->slotNumber << "\n";
            return availableSlot;
        } else {
            cout << "No available slot for vehicle type: " << vehicle->type << "\n";
            return nullptr;
        }
    }

    void removeVehicle(int slotNumber) {
        for (auto slot : slots) {
            if (slot->slotNumber == slotNumber) {
                slot->removeVehicle();
                cout << "Vehicle removed from slot number: " << slotNumber << "\n";
                return;
            }
        }
        cout << "Slot number " << slotNumber << " not found.\n";
    }
};

// ==========================================
// FACTORY PATTERN: Vehicle Factory
// ==========================================

class wVehicleFactory {
public:
    static Vehicle* createVehicle(string type, string licensePlate, PricingStrategy* pricingStrategy) {
        if (type == "car") {
            return new Car(licensePlate, pricingStrategy);
        } else if (type == "motorcycle") {
            return new Motorcycle(licensePlate, pricingStrategy);
        } else if (type == "truck") {
            return new Truck(licensePlate, pricingStrategy);
        } else {
            throw invalid_argument("Invalid vehicle type");
        }
    }
};

// ==========================================
// SINGLETON PATTERN: ParkingLotSingleton
// ==========================================

class ParkingLotSingleton {
private:
    static ParkingLotSingleton* instance;
    ParkingLot parkingLot;
    
    // Private constructor to prevent instantiation
    ParkingLotSingleton() {} 

public:
    static ParkingLotSingleton* getInstance() {
        if (instance == nullptr) {
            instance = new ParkingLotSingleton();
        }
        return instance;
    }

    void setParkingLot(ParkingLot pl) {
        this->parkingLot = pl;
    }

    ParkingLot& getParkingLot() {
        return parkingLot;
    }
};

// Initialize static member
ParkingLotSingleton* ParkingLotSingleton::instance = nullptr;

// ==========================================
// MAIN IMPLEMENTATION
// ==========================================

int main() {
    // 1. Initialize Slots
    vector<Slot*> slots;
    slots.push_back(new CarSlot(1));
    slots.push_back(new CarSlot(2));
    slots.push_back(new CarSlot(3));
    slots.push_back(new MotorcycleSlot(4)); // Added a moto slot for testing
    
    // 2. Initialize ParkingLot via Singleton
    ParkingLot parkingLot(slots);
    ParkingLotSingleton* systemManager = ParkingLotSingleton::getInstance();
    systemManager->setParkingLot(parkingLot);

    // 3. Initialize Pricing Strategies
    PricingStrategy* hourlyPricing = new HourlyPricing();
    PricingStrategy* premiumPricing = new PremiumPricing();

    // 4. Create Vehicles Using Factory
    Vehicle* car1 = VehicleFactory::createVehicle("car", "ABC123", hourlyPricing);
    Vehicle* car2 = VehicleFactory::createVehicle("car", "XYZ789", premiumPricing);
    Vehicle* motorcycle1 = VehicleFactory::createVehicle("motorcycle", "MOTO456", hourlyPricing);
    
    // 5. Park Vehicles
    cout << "\n--- Parking Process ---\n";
    Slot* slot1 = systemManager->getParkingLot().parkVehicle(car1);
    Slot* slot2 = systemManager->getParkingLot().parkVehicle(car2);
    Slot* slot3 = systemManager->getParkingLot().parkVehicle(motorcycle1); 

    // 6. Checkout and Payment System
    if(slot1 != nullptr) {
        cout << "\n--- Checkout Process for Car 1 ---\n";
        cout << "Select the payment method for car1 (1 for Cash, 2 for UPI): ";
        int paymentMethod;
        cin >> paymentMethod;

        PaymentStrategy* selectedStrategy = nullptr;
        if (paymentMethod == 1) {
            selectedStrategy = new CashPayment();
        } else if (paymentMethod == 2) {
            selectedStrategy = new UPIPayment();
        } else {
            cout << "Invalid payment method. Defaulting to Cash.\n";
            selectedStrategy = new CashPayment();
        }

        Payment* paymentSystem = new Payment(selectedStrategy);
        
        // Calculate Cost
        double carFee = car1->calculateCost(2, "hourly"); // Simulating 2 hours parked
        
        // Process Payment
        paymentSystem->processPayment(carFee);
        
        // Free up slot
        systemManager->getParkingLot().removeVehicle(slot1->slotNumber);
        
        // Clean up payment memory
        delete selectedStrategy;
        delete paymentSystem;
    }

    // Cleanup System memory (Best Practice)
    for (Slot* slot : slots) delete slot;
    delete car1;
    delete car2;
    delete motorcycle1;
    delete hourlyPricing;
    delete premiumPricing;

    return 0;
}
