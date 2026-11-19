#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    class Slide : public Command {
        public:
            Slide(int dx, int dy);
            Image* apply(Image *image) override;
            std::string toString() const override;

        private:
            int dx;
            int dy;
    };
}

#endif //SLIDE_HPP