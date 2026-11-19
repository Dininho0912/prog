#include "Command/Slide.hpp"

namespace prog {
    Slide::Slide(int dx, int dy) : Command("slide"), dx(dx), dy(dy) {}

    Image* Slide::apply(Image* image) {
        if(!image) return nullptr;

        int width = image->width();
        int height = image->height();
        Image* result = new Image(width, height, image -> at(0, 0));

        for(int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                int new_x = (x + dx) % width;
                int new_y = (y + dy) % height;

                result -> at(new_x, new_y) = image -> at(x, y);
            }
        }
        delete image;
        return result;
    }

    std::string Slide::toString() const {
        return "Slide" + std::to_string(dx) + ", " + std::to_string(dy);
    }
}