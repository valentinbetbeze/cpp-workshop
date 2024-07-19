#include <string>

class Vehicle {
public:
    Vehicle(const std::string &model) : model(model) {}
    virtual bool start(void) = 0;
    virtual void stop(void) const = 0;

protected:
    std::string model;
};
