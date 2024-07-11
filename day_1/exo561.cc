
class Point {

public:
    Point(const int &x, const int &y) {
        x_ = x;
        y_ = y;
    }
    void display(void) const {};
    void move(int x, int y){};

private:
    int x_;
    int y_;
};

int main(void) {
    Point a(1, 2);
    const Point b(3, 4);

    a.display();
    a.move(1, 2);

    b.display();
    b.move(3, 4); // <-- will not compile
}
