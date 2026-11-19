#ifndef V_MIRROR_HPP
#define V_MIRROR_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog{
    class V_mirror : public Command {
        public:
            V_mirror();
            Image* apply(Image *image) override;
            std::string toString() const override;
    };
}

#endif // V_MIRROR_HPP