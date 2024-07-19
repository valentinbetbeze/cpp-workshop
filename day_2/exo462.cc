#include <iostream>

class Shape {
public:
    Shape() : x_(0), y_(0) {}
    Shape(int x, int y) : x_(x), y_(y) {}
    ~Shape(){};
    virtual void print(void) const = 0;
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
    Circle() : radius_(0) {}
    Circle(int x, int y) : Shape(x, y), radius_(0) {}
    Circle(int x, int y, int r) : Shape(x, y), radius_(r) {}
    void print(void) const override {
        std::cout << "I am a circle located at (" << x_ << ", " << y_
                  << ") with a radius of " << radius_ << "\n";
    }

private:
    int radius_;
};

class Square : public Shape {
public:
    Square() : width_(0) {}
    Square(int x, int y) : Shape(x, y), width_(0) {}
    Square(int x, int y, int w) : Shape(x, y), width_(w) {}
    void print(void) const override {
        std::cout << "I am a square located at (" << x_ << ", " << y_
                  << ") with a side of " << width_ << "\n";
    }

private:
    int width_;
};

int main(void) {

    Square square(3, 3, 3);
    Circle circle(4, 4, 4);

    Shape *sq = &square;
    Shape *c = &circle;

    sq->print();
    c->print();

    return 0;
}
