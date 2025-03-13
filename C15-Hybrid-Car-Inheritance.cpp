// C15-Hybrid-Car-Inheritance.cpp 
/*
This code demonstrates how a HybridCar can utilize functionalities 
from both a traditional fuel-based car and an electric vehicle, 
showcasing the use of multiple inheritance in C++
*/
#include <iostream>
using namespace std;

// Base class 1: Car
class Car {
public:
    void drive() {
        cout << "Car => Driving using fuel engine" << endl;
    }
};

// Base class 2: Electric Vehicle
class ElectricVehicle {
public:
    void chargeBattery() {
        cout << "eVe => Charging the electric battery" << endl;
    }
};

// Derived class: HybridCar inherits from both Car and ElectricVehicle
class HybridCar : public Car, public ElectricVehicle {
public:
    void hybridMode() {
        cout << "Hyb => Switching to hybrid mode" << endl;
    }
};

int main() {
    HybridCar myCar;

    myCar.drive();          // Inherited from Car
    myCar.chargeBattery();  // Inherited from ElectricVehicle
    myCar.hybridMode();     // Defined in HybridCar

    return 0;
}
