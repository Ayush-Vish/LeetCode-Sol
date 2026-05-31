// #include <iostream>
// #include <string>

// // Concrete classes are exposed directly to the client
// class Car {
// public:
//     void drive() { std::cout << "Driving a Car." << std::endl; }
// };

// class Truck {
// public:
//     void drive() { std::cout << "Driving a heavy Truck." << std::endl; }
// };

// int main() {
//     std::string vehicleType = "Car";
    
//     // PROBLEM: Client code is cluttered with creation logic (if-else).
//     // If we add "Bike", we must change this code.
//     // We are managing memory manually (raw pointers).
    
//     if (vehicleType == "Car") {
//         Car* myCar = new Car();
//         myCar->drive();
//         delete myCar;
//     } 
//     else if (vehicleType == "Truck") {
//         Truck* myTruck = new Truck();
//         myTruck->drive();
//         delete myTruck;
//     }

//     return 0;
// }


#include <iostream>
#include <memory>  // For smart pointers
#include <string>
using namespace std;

// 1. Interface (Abstract Product)
class IVehicle {
public:
    virtual void drive() = 0;
    virtual ~IVehicle() = default;
};

// 2. Concrete Products
class Car : public IVehicle {
public:
    void drive() override { std::cout << "Driving a Car." << std::endl; }
};

class Truck : public IVehicle {
public:
    void drive() override { std::cout << "Driving a heavy Truck." << std::endl; }
};

class Bike : public IVehicle { // Easy to add new types now
public:
    void drive() override { std::cout << "Riding a Bike." << std::endl; }
};

// 3. The Factory
class VehicleFactory {
public:
    // Returns a smart pointer (auto-deletes memory)
    static std::unique_ptr<IVehicle> createVehicle(const std::string& type) {
        if (type == "Car") {
            return std::unique_ptr<IVehicle>(new Car());
        } else if (type == "Truck") {
            return std::make_unique<Truck>();
        } else if (type == "Bike") {
            return std::make_unique<Bike>();
        }
        return nullptr;
    }
};

int main() {        
    
    auto v1 = VehicleFactory::createVehicle("Car");
    if(v1) v1->drive();

    auto v2 = VehicleFactory::createVehicle("Bike");
    if(v2) v2->drive();

    return 0;
}
