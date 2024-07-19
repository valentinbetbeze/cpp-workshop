#include <iostream>
#include <memory>
#include <string>

class B {
public:
    B() { data = ""; }
    B(std::string data) : data(data) {}
    std::string get_data(void) { return data; }
    void print(void) const { std::cout << data << std::endl; }
    void modify(const std::shared_ptr<B> &obj, const std::string &text) {
        obj.get()->data = text;
    }

private:
    std::string data;
};

int main(void) {
    std::shared_ptr<B> ptr = std::make_shared<B>("hello, ");
    ptr.get()->print();
    ptr.get()->modify(ptr, "world!");
    ptr.get()->print();
    return 0;
}
