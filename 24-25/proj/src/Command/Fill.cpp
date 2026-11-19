#include "Command/Fill.hpp"
#include <sstream>

namespace prog {
    Fill::Fill(int x, int y, int width, int height, const Color& color)
        : Command("fill"), x(x), y(y), width(width), height(height), fillColor(color) {}

    Image* Fill::apply(Image* image) {
        if (!image) return nullptr;

        int imgWidth = image->width();
        int imgHeight = image->height();

        for(int j = y; j < y + height; ++j){
            if(j < 0 || j >= imgHeight) continue; // Out of bounds{

            for(int i = x; i < x + width; ++i){
                if(i < 0 || i >= imgWidth) continue; // Out of bounds

                image -> at(i, j) = fillColor; // Fill the pixel with the color
            }
        }
        return image;
    }

    std::string Fill::toString() const {
        return "fill" + std::to_string(x) + " " + std::to_string(y) + " " +
                std::to_string(width) + " " + std::to_string(height) + " " +
                std::to_string((int)fillColor.red()) + " " +
                std::to_string((int)fillColor.green()) + " " +
                std::to_string((int)fillColor.blue());
    }
}