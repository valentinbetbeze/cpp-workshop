#include "motorcycle.hh"

int main(void) {
    Motorcycle bike("yamaha");
    bike.start();
    bike.cruise(5U);
    bike.fill(2U);
    bike.stop();
    return 0;
}
