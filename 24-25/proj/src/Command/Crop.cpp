#include "Command/Crop.hpp"

namespace prog {
    Crop::Crop(int x, int y, int w, int h) : Command("crop"), x(x), y(y),w(w),h(h) {}

    Image* Crop::apply(Image* image) {
        if(!image) return nullptr;
        int width = image->width();
        int height = image->height();
        if (x < 0 || y < 0 || x + w > width || y + h > height) {
            return image; // Return the original image if the crop is out of bounds
        }
        Image* result = new Image(w, h, Color(0, 0, 0));
        for (int j = 0; j < h; ++j) {
            for (int i = 0; i < w; ++i) {
                result->at(i, j) = image->at(x + i, y + j);
            }
        }
        delete image; // Dispose of the original image
        return result; // Return the cropped image


        
        
       
    }

    std::string Crop::toString() const {
        return "Crop" + std::to_string(x) + " " + std::to_string(y) + " " +
               std::to_string(w) + " " + std::to_string(h);
    }
}