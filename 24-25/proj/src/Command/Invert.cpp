#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        Invert::Invert() : Command("invert") {}
        Invert::~Invert() {}

        Image* Invert::apply(Image* img) {
            // Create a new image with the same dimensions
            Image* result = new Image( img->width(),img->height(), Color(0, 0, 0));
            for (int y = 0; y < img->height(); ++y) {
                for (int x = 0; x < img->width(); ++x) {
                    Color c = img->at(x, y);
                    Color inverted(255 - c.red(), 255 - c.green(), 255 - c.blue());
                    result->at(x, y) = inverted;
                }
            }
            // Dispose of the given image, as in Blank::apply
            delete img;
            return result;
        }

        std::string Invert::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
