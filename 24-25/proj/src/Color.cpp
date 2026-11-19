#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::Color() : r(0), g(0), b(0) {
    }

    Color::Color(const Color &c) : r(c.r), g(c.g), b(c.b) {
    }

    Color::Color(rgb_value red, rgb_value green, rgb_value blue)  : r(red), g(green), b(blue)  {
    }

    rgb_value Color::red() const {
        return r;
    }

    rgb_value Color::green() const {
        return g;
    }

    rgb_value Color::blue() const {
        return b;
    }

    rgb_value &Color::red() {
        return r;
    }

    rgb_value &Color::green() {
        return g;
    }

    rgb_value &Color::blue() {
        return b;
    }
}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = static_cast<prog::rgb_value>(r);
    c.green() = static_cast<prog::rgb_value>(g);
    c.blue() = static_cast<prog::rgb_value>(b);
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << static_cast<int>(c.red()) << ":"
           << static_cast<int>(c.green()) << ":"
           << static_cast<int>(c.blue());
    return output;
}

bool operator==(const prog::Color &lhs, const prog::Color &rhs){
    return lhs.red() == rhs.red() &&
            lhs.green() == rhs.green() &&
            lhs.blue() == rhs.blue();
}

