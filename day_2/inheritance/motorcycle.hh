#include "motorvehicle.hh"
#include "twowheelvehicle.hh"

#include <iostream>

#define MOTORCYCLE_FUEL_START 13U

class Motorcycle : public MotorVehicle, public TwoWheelVehicle {
public:
    Motorcycle() : MotorVehicle("", MOTORCYCLE_FUEL_START) {}
    Motorcycle(const std::string &model)
        : MotorVehicle(model, MOTORCYCLE_FUEL_START) {}
    virtual void change_front_wheel(void) const override {
        std::cout << "Change front wheel\n";
    }
    virtual void change_back_wheel(void) const override {
        std::cout << "Change back wheel\n";
    }
};
