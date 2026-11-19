#include "Command/H_mirror.hpp"

namespace prog {
    
    H_mirror::H_mirror() : Command("h_mirror") {}

    Image* H_mirror::apply(Image* image) {
        if(!image) return nullptr;

        int width = image -> width();
        int height = image -> height();

        for (int y = 0; y < height; ++y){
            for (int x = 0; x < width/2; ++x){
                int mirror_x = width - x - 1;

                Color temp = image -> at(x, y);
                image -> at(x, y) = image -> at(mirror_x, y);
                image -> at(mirror_x, y) = temp;
            }
        }
        return image;
    }
    std::string H_mirror::toString() const {
        return "h_mirror";
    }
}