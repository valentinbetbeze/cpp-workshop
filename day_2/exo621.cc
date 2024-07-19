#include <cstring>
#include <iostream>

static void dummy_function(void);

class VTableTested {
public:
    VTableTested(int value) : i(value) {}
    virtual void print_i(void) const {
        std::cout << "The value of i is: " << i << "\n";
    }
    virtual void print_2i(void) const {
        std::cout << "The value of 2 * i is: " << 2 * i << "\n";
    }

private:
    int i;
};

class VTableAccessor {
public:
    virtual void call_method(VTableTested *vt, int i) {
        long **vtable = *(long ***)vt;
        ((void (*)(VTableTested *))vtable[i])(vt);
    }
    typedef void (*v_ptr)(void);
    virtual void replace_method(VTableTested *&vt, int i, v_ptr new_meth) {
        // Get the original virtual table location (_vptr)
        long **vtable = *(long ***)vt;

        /* The original virtual table is placed in a non-writable memory section
        Make a virtual table clone in a writable memory section (heap) */
        long **new_vtable = new long *[2U];
        std::memcpy(new_vtable, vtable, 2U * sizeof(long *));

        // Replace the ith method in the cloned virtual table
        new_vtable[i] = (long *)new_meth;

        // Set the VTableTested virtual pointer to the cloned virtual table
        *(long ***)vt = new_vtable;
    }
};

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "Error: Argument missing" << std::endl;
        return 1;
    }

    int arg = atoi(argv[1]);
    VTableTested *vt = new VTableTested(42);
    VTableAccessor *vta = new VTableAccessor();

    std::cout << "Calling member functions of VTableTested:\n";
    std::cout << "print_i():\n";
    vt->print_i();
    std::cout << "print_2i()\n";
    vt->print_2i();
    std::cout << "\nAccessing vTable  member functions via VTableAccessor:\n";
    std::cout << "print_i()\n";
    vta->call_method(vt, 0);
    std::cout << "print_2i()\n";
    vta->call_method(vt, 1);

    std::cout << "Choose a member function to replace:\n";
    std::cout << "      0 - print_i()\n";
    std::cout << "      1 - print_2i()\n";
    std::cout << arg << "\n";

    std::cout << "///////////////////////////////////////////////////\n";
    std::cout << "Replacing vTable member functions at index " << arg << " "
              << ((arg == 0) ? "(print_i):\n"
                             : ((arg == 1) ? "(print_2i):\n" : "(unknown):\n"));
    vta->replace_method(vt, arg, dummy_function);
    std::cout << "///////////////////////////////////////////////////\n";

    std::cout << "\nCalling member functions of VTableTested:\n";
    std::cout << "print_i():\n";
    vt->print_i();
    std::cout << "print_2i()\n";
    vt->print_2i();
    std::cout << "\nAccessing vTable  member functions via VTableAccessor:\n";
    std::cout << "print_i()\n";
    vta->call_method(vt, 0);
    std::cout << "print_2i()\n";
    vta->call_method(vt, 1);

    std::cout << std::endl;

    delete[] * (long ***)vt;
    delete vt;
    delete vta;

    return 0;
}

static void dummy_function(void) {
    std::cout << "This member function has been replaced\n";
}
