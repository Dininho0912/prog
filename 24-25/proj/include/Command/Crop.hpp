#ifndef CROP_HPP
#define CROP_HPP

#include "Command.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    class Crop : public Command {
        public:
            Crop(int x, int y, int w, int h);
            Image* apply(Image *image) override;
            std::string toString() const override;

        private:
            int x;
            int y;
            int w;
            int h;
    };
}

#endif //CROP_HPP