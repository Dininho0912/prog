#ifndef FILL_HPP
#define FILL_HPP

#include "Command.hpp"
#include "Color.hpp"
#include "Image.hpp"

namespace prog {
    class Fill : public Command {
        private:
            int x, y, width, height;
            Color fillColor;

        public:
            Fill(int x, int y, int width, int height, const Color& color);
            Image* apply(Image* image) override;
            std::string toString() const override;
    };
}

#endif // FILL_HPP