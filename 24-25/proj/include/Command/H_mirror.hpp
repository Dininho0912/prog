#ifndef H_MIRROR_HPP
#define H_MIRROR_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog{
    class H_mirror : public Command {
        public:
            H_mirror();
            Image* apply(Image *image) override;
            std::string toString() const override;
    };
}

#endif // H_MIRROR_HPP