#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>

using namespace std;

// =====================================================
// ENUMS
// =====================================================

enum class VehicleType {
    ECONOMY,
    SUV,
    LUXURY
};

enum class VehicleStatus {
    AVAILABLE,
    RESERVED,
    RENTED,
    MAINTENANCE
};

enum class ReservationStatus {
    PENDING,
    CONFIRMED,
    IN_PROGRESS,
    COMPLETED,
    CANCELLED
};

// =====================================================
// VEHICLE (ABSTRACT)
// =====================================================

class Vehicle {
protected:
    string registrationNumber;
    string model;
    VehicleType type;
    VehicleStatus status;
    double baseRentalPrice;

public:
    Vehicle(string regNo,
            string model,
            VehicleType type,
            double price)
        : registrationNumber(regNo),
          model(model),
          type(type),
          baseRentalPrice(price),
          status(VehicleStatus::AVAILABLE) {}

    virtual ~Vehicle() {}

    virtual double calculateRentalFee(int days) = 0;

    string getRegistrationNumber() const {
        return registrationNumber;
    }

    string getModel() const {
        return model;
    }

    VehicleStatus getStatus() const {
        return status;
    }

    void setStatus(VehicleStatus s) {
        status = s;
    }

    double getBaseRentalPrice() const {
        return baseRentalPrice;
    }
};

// =====================================================
// CONCRETE VEHICLES
// =====================================================

class EconomyVehicle : public Vehicle {
public:
    EconomyVehicle(string regNo,
                   string model,
                   double price)
        : Vehicle(regNo, model,
                  VehicleType::ECONOMY, price) {}

    double calculateRentalFee(int days) override {
        return baseRentalPrice * days;
    }
};

class SUVVehicle : public Vehicle {
public:
    SUVVehicle(string regNo,
               string model,
               double price)
        : Vehicle(regNo, model,
                  VehicleType::SUV, price) {}

    double calculateRentalFee(int days) override {
        return baseRentalPrice * days * 1.5;
    }
};

class LuxuryVehicle : public Vehicle {
public:
    LuxuryVehicle(string regNo,
                  string model,
                  double price)
        : Vehicle(regNo, model,
                  VehicleType::LUXURY, price) {}

    double calculateRentalFee(int days) override {
        return (baseRentalPrice * days * 2.5) + 50;
    }
};

// =====================================================
// FACTORY PATTERN
// =====================================================

class VehicleFactory {
public:
    static shared_ptr<Vehicle> createVehicle(
        VehicleType type,
        string regNo,
        string model,
        double price) {

        switch (type) {
        case VehicleType::ECONOMY:
            return make_shared<EconomyVehicle>(
                regNo, model, price);

        case VehicleType::SUV:
            return make_shared<SUVVehicle>(
                regNo, model, price);

        case VehicleType::LUXURY:
            return make_shared<LuxuryVehicle>(
                regNo, model, price);

        default:
            return nullptr;
        }
    }
};

// =====================================================
// LOCATION
// =====================================================

class Location {
public:
    string address;
    string city;
    string state;
    string zipCode;

    Location(string address,
             string city,
             string state,
             string zip)
        : address(address),
          city(city),
          state(state),
          zipCode(zip) {}
};

// =====================================================
// RENTAL STORE
// =====================================================

class RentalStore {
private:
    int id;
    string name;
    Location location;

    unordered_map<string,
                  shared_ptr<Vehicle>> vehicles;

public:
    RentalStore(int id,
                string name,
                Location location)
        : id(id),
          name(name),
          location(location) {}

    int getId() const {
        return id;
    }

    void addVehicle(shared_ptr<Vehicle> vehicle) {
        vehicles[vehicle->getRegistrationNumber()]
            = vehicle;
    }

    shared_ptr<Vehicle>
    getVehicle(const string& regNo) {
        if (vehicles.count(regNo))
            return vehicles[regNo];
        return nullptr;
    }

    vector<shared_ptr<Vehicle>>
    getAvailableVehicles() {

        vector<shared_ptr<Vehicle>> result;

        for (auto& v : vehicles) {
            if (v.second->getStatus()
                == VehicleStatus::AVAILABLE)
                result.push_back(v.second);
        }

        return result;
    }
};

// =====================================================
// USER
// =====================================================

class User {
private:
    int id;
    string name;
    string email;

public:
    User(int id,
         string name,
         string email)
        : id(id),
          name(name),
          email(email) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }
};

// =====================================================
// RESERVATION
// =====================================================

class Reservation {
private:
    int id;
    User* user;

    shared_ptr<Vehicle> vehicle;

    ReservationStatus status;

    int rentalDays;
    double totalAmount;

public:
    Reservation(int id,
                User* user,
                shared_ptr<Vehicle> vehicle,
                int days)
        : id(id),
          user(user),
          vehicle(vehicle),
          rentalDays(days) {

        status = ReservationStatus::PENDING;

        totalAmount =
            vehicle->calculateRentalFee(days);
    }

    int getId() const {
        return id;
    }

    double getTotalAmount() const {
        return totalAmount;
    }

    void confirmReservation() {
        status = ReservationStatus::CONFIRMED;
        vehicle->setStatus(
            VehicleStatus::RESERVED);
    }

    void startRental() {
        status =
            ReservationStatus::IN_PROGRESS;

        vehicle->setStatus(
            VehicleStatus::RENTED);
    }

    void completeRental() {
        status =
            ReservationStatus::COMPLETED;

        vehicle->setStatus(
            VehicleStatus::AVAILABLE);
    }

    void cancelReservation() {
        status =
            ReservationStatus::CANCELLED;

        vehicle->setStatus(
            VehicleStatus::AVAILABLE);
    }
};

// =====================================================
// RESERVATION MANAGER
// =====================================================

class ReservationManager {
private:
    unordered_map<int,
                  shared_ptr<Reservation>>
        reservations;

    int nextId = 1;

public:
    shared_ptr<Reservation>
    createReservation(
        User* user,
        shared_ptr<Vehicle> vehicle,
        int days) {

        auto reservation =
            make_shared<Reservation>(
                nextId++,
                user,
                vehicle,
                days);

        reservations[
            reservation->getId()] = reservation;

        return reservation;
    }

    shared_ptr<Reservation>
    getReservation(int id) {

        if (reservations.count(id))
            return reservations[id];

        return nullptr;
    }
};

// =====================================================
// PAYMENT STRATEGY PATTERN
// =====================================================

class PaymentStrategy {
public:
    virtual ~PaymentStrategy() {}
    virtual void processPayment(
        double amount) = 0;
};

class CreditCardPayment
    : public PaymentStrategy {
public:
    void processPayment(
        double amount) override {

        cout << "Credit Card Payment: $"
             << amount << endl;
    }
};

class CashPayment
    : public PaymentStrategy {
public:
    void processPayment(
        double amount) override {

        cout << "Cash Payment: $"
             << amount << endl;
    }
};

class PayPalPayment
    : public PaymentStrategy {
public:
    void processPayment(
        double amount) override {

        cout << "PayPal Payment: $"
             << amount << endl;
    }
};

class PaymentProcessor {
public:
    bool processPayment(
        double amount,
        PaymentStrategy* strategy) {

        strategy->processPayment(amount);
        return true;
    }
};

// =====================================================
// SINGLETON RENTAL SYSTEM
// =====================================================

class RentalSystem {
private:
    static RentalSystem* instance;

    vector<shared_ptr<RentalStore>> stores;

    unordered_map<int,
                  shared_ptr<User>>
        users;

    ReservationManager reservationManager;
    PaymentProcessor paymentProcessor;

    RentalSystem() {}

public:
    static RentalSystem* getInstance() {

        if (instance == nullptr)
            instance = new RentalSystem();

        return instance;
    }

    void addStore(
        shared_ptr<RentalStore> store) {

        stores.push_back(store);
    }

    void registerUser(
        shared_ptr<User> user) {

        users[user->getId()] = user;
    }

    shared_ptr<Reservation>
    createReservation(
        int userId,
        shared_ptr<Vehicle> vehicle,
        int days) {

        if (!users.count(userId))
            return nullptr;

        return reservationManager
            .createReservation(
                users[userId].get(),
                vehicle,
                days);
    }

    bool processPayment(
        int reservationId,
        PaymentStrategy* strategy) {

        auto reservation =
            reservationManager
                .getReservation(
                    reservationId);

        if (!reservation)
            return false;

        paymentProcessor.processPayment(
            reservation->getTotalAmount(),
            strategy);

        reservation
            ->confirmReservation();

        return true;
    }

    void startRental(int id) {

        auto reservation =
            reservationManager
                .getReservation(id);

        if (reservation)
            reservation->startRental();
    }

    void completeRental(int id) {

        auto reservation =
            reservationManager
                .getReservation(id);

        if (reservation)
            reservation->completeRental();
    }
};

RentalSystem* RentalSystem::instance =
    nullptr;

// =====================================================
// MAIN
// =====================================================

int main() {

    RentalSystem* system =
        RentalSystem::getInstance();

    auto store =
        make_shared<RentalStore>(
            1,
            "Downtown Rentals",
            Location(
                "123 Main Street",
                "New York",
                "NY",
                "10001"));

    system->addStore(store);

    auto car1 =
        VehicleFactory::createVehicle(
            VehicleType::ECONOMY,
            "EC001",
            "Toyota Corolla",
            50);

    auto car2 =
        VehicleFactory::createVehicle(
            VehicleType::LUXURY,
            "LX001",
            "Mercedes",
            200);

    store->addVehicle(car1);
    store->addVehicle(car2);

    auto user =
        make_shared<User>(
            101,
            "Ayush",
            "ayush@gmail.com");

    system->registerUser(user);

    auto reservation =
        system->createReservation(
            user->getId(),
            car1,
            5);

    cout << "Reservation Created\n";
    cout << "Reservation ID : "
         << reservation->getId()
         << endl;

    cout << "Amount : "
         << reservation->getTotalAmount()
         << endl;

    CreditCardPayment payment;

    system->processPayment(
        reservation->getId(),
        &payment);

    cout << "\nRental Started\n";
    system->startRental(
        reservation->getId());

    cout << "Rental Completed\n";
    system->completeRental(
        reservation->getId());

    return 0;
}
