#include "Command/Add.hpp"
#include "PNG.hpp"

namespace prog {
    Add::Add(const std::string& filename, Color neutral, int x, int y)
        : Command(), filename(filename), neutral(neutral), x(x), y(y) {}

    Image* Add::apply(Image* image) {
        if(!image) return nullptr;

        Image* overlay = loadFromPNG(filename);
        if(!overlay) return image;

        int base_width = image->width();
        int base_height = image->height();
        int overlay_width = overlay->width();
        int overlay_height = overlay->height();

        for(int j = 0; j < overlay_height; j++){
            for(int i = 0; i < overlay_width; i++){
                int target_x = x + i;
                int target_y = y + j;

                if(target_x < 0 || target_x >= base_width || target_y < 0 || target_y >= base_height){
                    continue;
                }

                Color current = overlay -> at(i, j);
                if(current.red() == neutral.red() &&
                   current.green() == neutral.green() &&
                   current.blue() == neutral.blue()){
                    continue;
                }
                image -> at(target_x, target_y) = current;
            }
        }
        delete overlay;
        return image;
    }

    std::string Add::toString() const {
        return "add " + filename + " " + 
                std::to_string((int) neutral.red()) + " " + 
                std::to_string((int) neutral.green()) + " " + 
                std::to_string((int) neutral.blue()) + " " +
                std::to_string(x) + " " + std::to_string(y);
    }
}