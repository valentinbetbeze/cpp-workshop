#include <fstream>
#include <iostream>

int main(void) {
    std::ifstream file_in;
    std::string token;
    int count = 0;

    // Open file
    file_in.open("file.in");
    if (file_in.is_open() != true) {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }

    // Count the number of words
    while (file_in >> token) {
        count++;
    }

    // Output the number of words
    std::cout << count << std::endl;

    return 0;
}
