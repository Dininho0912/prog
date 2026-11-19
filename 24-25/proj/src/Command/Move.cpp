#include "Command/Move.hpp"

namespace prog {
    Move::Move(int dx, int dy) : Command("move"), dx(dx), dy(dy) {}

    Image* Move::apply(Image* image) {
        if(!image) return nullptr;

        int width = image -> width();
        int height = image -> height();
        Color fill = image -> at(0, 0);

        Image* result = new Image(width, height, fill);

        for (int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                int new_x = x + dx;
                int new_y = y + dy;

                if (new_x < width && new_y < height){
                    result -> at(new_x, new_y) = image -> at(x, y);
                }
            }
        }
        delete image;
        return result;
    }

    std::string Move::toString() const {
        return "move " + std::to_string(dx) + " " + std::to_string(dy);
    }
}