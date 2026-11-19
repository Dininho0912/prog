#ifndef ADD_HPP
#define ADD_HPP

#include "Command.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include <string>


namespace prog {
    class Add : public Command {
        public:
            Add(const std::string& filename, Color neutral, int x, int y);
            Image* apply(Image* image) override;
            std::string toString() const override;

        private:
            std::string filename;
            Color neutral;
            int x;
            int y;
    };
}

#endif // ADD_HPP