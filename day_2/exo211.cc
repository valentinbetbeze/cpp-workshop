#include <iostream>

class Count {
public:
    Count() { initialized++; }
    ~Count() { initialized--; }
    static int initialized;
    static void print(void) { std::cout << initialized << std::endl; }
};

int Count::initialized = 0;

int main(void) {
    Count::print(); // Should output 0
    Count A;

    {
        Count B;
        Count C;
        Count::print(); // Should output 3
        // B and C will be deleted when exiting this scope
    }

    Count::print(); // Should output 1
    return 0;
}
