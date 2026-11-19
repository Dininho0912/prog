#include <iostream>

class Point {
public:
    Point() : x_(0), y_(0) {} // Default constructor
    Point(int x, int y) : x_(x), y_(y) {} // Parameterized constructor
    Point(const Point& p) : x_(p.x_), y_(p.y_) {} // Copy constructor

    int get_x() const { return x_; } // Get x coordinate
    int get_y() const { return y_; } // Get y coordinate

    Point& operator=(const Point& p) { // Assignment operator
        x_ = p.x_;
        y_ = p.y_;
        return *this;
    }

    Point operator+(const Point& p) const { // Sum operator
        return Point(x_ + p.x_, y_ + p.y_);
    }

    Point& operator+=(const Point& p) { // Composed assignment and sum operator
        x_ += p.x_;
        y_ += p.y_;
        return *this;
    }

    Point operator*(int v) const { // Right multiplication by scalar operator
        return Point(x_ * v, y_ * v);
    }

private:
    int x_, y_;
};

Point operator*(int x, const Point& p) { // Left multiplication by scalar operator
    return Point(x * p.get_x(), x * p.get_y());
}

std::ostream& operator<<(std::ostream& os, const Point& p) { // Output stream operator
    os << "(" << p.get_x() << "," << p.get_y() << ")";
    return os;
}
