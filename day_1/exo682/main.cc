#include "bst.hh"
#include <iostream>

int main(void) {
    Bst bst;

    bst.insert(5);
    bst.insert(9);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(10);
    bst.insert(1);
    bst.insert(8);

    bst.print();
    std::cout << "Min: " << bst.findMin() << std::endl;
    std::cout << "Max: " << bst.findMax() << std::endl;

    if (bst.erase(5)) {
        std::cout << "5 deleted" << std::endl;
    }
    if (bst.erase(1)) {
        std::cout << "1 deleted" << std::endl;
    }
    if (bst.erase(3)) {
        std::cout << "3 deleted" << std::endl;
    }
    if (bst.erase(11)) {
        std::cout << "11 deleted" << std::endl;
    }

    bst.print();
    std::cout << "Min: " << bst.findMin() << std::endl;
    std::cout << "Max: " << bst.findMax() << std::endl;
}
