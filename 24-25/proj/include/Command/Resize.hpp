#ifndef RESIZE_HPP
#define RESIZE_HPP

#include "Command.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    class Resize : public Command {
        public:
            Resize(int x, int y, int w, int h);
            Image* apply(Image *image) override;
            std::string toString() const override;

        private:
            int x;
            int y;
            int w;
            int h;
    };
}

#endif //RESIZE_HPP