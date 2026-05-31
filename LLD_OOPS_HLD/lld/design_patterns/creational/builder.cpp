#include <iostream>
#include <memory>
#include <string>
using namespace std;
class Car {
      private:
      string engine;
      string body;
      string color;
      string transmission;
      string fuelType;
      string features;
      friend class CarBuilder;
      public:
      void print() {
            cout << "Engine: " << engine << endl;
            cout << "Body: " << body << endl;
            cout << "Color: " << color << endl;
            cout << "Transmission: " << transmission << endl;
            cout << "Fuel Type: " << fuelType << endl;
            cout << "Features: " << features << endl;
      }
};
// Used Friend Class for Encapsulation purposes.
// So that only CarBuilder can access the private members of Car.
// Other parts of the code cannot access the private members of Car. 

class CarBuilder{
      private:
      unique_ptr<Car> car;
      // Car* car;
      public:
      CarBuilder() {
            car = make_unique<Car>(); // car = new Car();
      }
      // We are returning the reference of the object
      // So that we can chain the function calls.
      // there is Difference in pointer and reference
      // in pointer we are returning the address of the object
      // in reference we are returning the reference of the object
      CarBuilder&setEngine(const string&engine){
            car->engine = engine;
            return *this;
      }
      CarBuilder&setBody(const string&body){
            car->body = body;
            return *this;
      }
      CarBuilder&setColor(const string&color){
            car->color = color;
            return *this;
      }
      CarBuilder&setTransmission(const string&transmission){
            car->transmission = transmission;
            return *this;
      }
      CarBuilder&setFuelType(const string&fuelType){
            car->fuelType = fuelType;
            return *this;
      }
      CarBuilder&setFeatures(const string&features){
            car->features = features;
            return *this;
      }
      unique_ptr<Car>build(){
            // So we Are using move 
            // since the unique_ptr is not copyable and we Cannot Transfer the Ownership of the object
            // we are using move to transfer the ownership of the object
            // to the caller of the build function
            return move(car);
      }
};


int main(){
      CarBuilder builder;
      unique_ptr<Car> car =builder.setEngine("V8")
                                    .setBody("Sedan")
                                    .setColor("Red")
                                    .setTransmission("Automatic")
                                    .setFuelType("Petrol")
                                    .setFeatures("Airbags")
                                    .build();
      car->print();
      return 0 ;

}
