#include <iostream>

void swap(int &a, int &b);

int main(void) {
    int a = 10;
    int b = 30;

    int &ref_a = a;
    int &ref_b = b;

    swap(ref_a, ref_b);

    std::cout << ref_a << std::endl;
    std::cout << ref_b << std::endl;

    return 0;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
