#include "Command/V_mirror.hpp"

namespace prog {

    V_mirror::V_mirror() : Command("v_mirror") {}

    Image* V_mirror::apply(Image* image) {
        if(!image) return nullptr;

        int width = image -> width();
        int height = image -> height();

        for (int x = 0; x < width; ++x){
            for (int y = 0; y < height/2; ++y){
                int mirror_y = height - y - 1;

                Color temp = image -> at(x, y);
                image -> at(x, y) = image -> at(x, mirror_y);
                image -> at(x, mirror_y) = temp;
            }
        }
        return image;
    }
    std::string V_mirror::toString() const {
        return "v_mirror";
    }
}