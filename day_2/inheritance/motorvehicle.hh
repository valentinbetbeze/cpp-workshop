#include "engine.hh"
#include "vehicle.hh"

class MotorVehicle : public Vehicle {
public:
    MotorVehicle(const std::string &model, unsigned int fuel)
        : Vehicle(model), engine(fuel) {}
    virtual bool start(void) override { return engine.start(); }
    virtual void stop(void) const override { engine.stop(); }
    void cruise(unsigned int fuel) { engine.consume(fuel); }
    void fill(unsigned int fuel) { engine.fill(fuel); }

private:
    Engine engine;
};
