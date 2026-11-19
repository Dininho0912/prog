#ifndef INVERT_HPP
#define INVERT_HPP

#include "Command.hpp"
#include "Image.hpp" // Include the Image class definition

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
    /**
     * @brief Constructor for the Invert class.
     */
    Invert();

    /**
     * @brief Destructor for the Invert class.
     */
    virtual ~Invert();

    /**
     * @brief Applies the invert transformation to the image.
     * @param img The image to be inverted.
     * @return A pointer to the transformed image.
     */
    Image* apply(Image* img) override;
    std::string toString() const override;
        };
    };
};

#endif // INVERT_HPP
