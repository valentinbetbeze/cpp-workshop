#include <iostream>

class Shape {
public:
    Shape() : x_(0), y_(0) { std::cout << "New shape created\n"; }
    Shape(int x, int y) : x_(x), y_(y) {
        std::cout << "New shape created (" << x_ << ", " << y_ << ")\n";
    }
    ~Shape(){};
    void print(void) const {
        std::cout << "I am a shape located at (" << x_ << ", " << y_ << ")\n";
    }
    void translate(int tx, int ty) {
        x_ += tx;
        y_ += ty;
    }

protected:
    int x_;
    int y_;
};

class Circle : public Shape {
public:
    Circle() : radius_(0) { std::cout << "New circle created\n"; }
    Circle(int x, int y) : Shape(x, y), radius_(0) {}
    Circle(int x, int y, int r) : Shape(x, y), radius_(r) {}
    void print(void) const {
        std::cout << "I am a circle located at (" << x_ << ", " << y_
                  << ") with a radius of " << radius_ << "\n";
    }

private:
    int radius_;
};

int main(void) {
    Circle c(2, 3, 5);
    c.print();
    return 0;
}
