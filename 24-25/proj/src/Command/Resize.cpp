#include "Command/Resize.hpp"

namespace prog {
    Resize::Resize(int x, int y, int w, int h) : Command("resize"), x(x), y(y),w(w),h(h) {}

    Image* Resize::apply(Image* image) {
        if(!image) return nullptr;
        int width = image->width();
        int height = image->height();
         // Use the color of the top-left pixel as the background
        Color background = image->at(0, 0);
        Image* result = new Image(w, h, background);
         for (int j = 0; j < h; ++j) {
            for (int i = 0; i < w; ++i) {
                if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) {
                    result->at(i, j) = image->at(x + i, y + j);
                }
                // else: leave as background color
            }
        }
        delete image; // Dispose of the original image
        return result; // Return the cropped image


        
        
       
    
    }

    std::string Resize::toString() const {
        return "Resize" + std::to_string(x) + " " + std::to_string(y) + " " +
               std::to_string(w) + " " + std::to_string(h);
    }
}
    
    


