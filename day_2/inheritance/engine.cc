#include "engine.hh"
#include <iostream>

bool Engine::start(void) {
    if (fuel > 0) {
        fuel--;
        std::cout << "Engine started with " << fuel << " units of fuel\n";
        return true;
    }
    return false;
}
void Engine::consume(unsigned int consumed) {
    if (fuel > 0) {
        if (consumed > fuel) {
            consumed = fuel;
        }
        fuel -= consumed;
        std::cout << "Engine uses " << consumed << " fuel units\n";
    }
}
void Engine::stop(void) const { std::cout << "Stop Engine\n"; }
void Engine::fill(int fuel) {
    Engine::fuel += fuel;
    std::cout << "Engine filled with " << fuel << " fuel units\n";
}
