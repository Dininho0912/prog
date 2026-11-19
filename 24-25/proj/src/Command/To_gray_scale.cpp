#include <Image.hpp>
#include <Color.hpp>
#include <string>
#include <cmath>
#include <Command.hpp>
#include <Command/To_gray_scale.hpp>
#include <sstream>

namespace prog {

    namespace command {
    to_gray_scale::to_gray_scale() : Command("to_gray_scale") {}
    to_gray_scale::~to_gray_scale() {}

    Image* to_gray_scale::apply(Image* img) {
     
        Image* result = new Image( img->width(),img->height(), Color(0, 0, 0));
        for (int y = 0; y < img -> height(); ++y) {
            for (int x = 0; x < img -> width(); ++x) {
                Color c = img->at(x, y);
                int g=(c.red()+c.green()+c.blue())/3;
                Color gray(g, g, g);
                    result->at(x, y) = gray;
            }
        }

        delete img;
        return result;
    }

      std::string to_gray_scale::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}    