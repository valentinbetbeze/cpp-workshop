#include <fstream>
#include <iostream>

int main(void) {
    std::string token;
    std::ofstream file_out("file.out");

    while (std::cin >> token) {
        file_out << token << ' ';
    }

    file_out << std::endl;
    file_out.close();

    return 0;
}
