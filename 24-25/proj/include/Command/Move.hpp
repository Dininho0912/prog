#ifndef MOVE_HPP
#define MOVE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    class Move : public Command {
        public:
            Move(int dx, int dy);
            Image* apply(Image* image) override;
            std::string toString() const override;

        private:
            int dx;
            int dy;            
    };
}

#endif // MOVE_HPP