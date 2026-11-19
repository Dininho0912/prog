#ifndef TO_GRAY_SCALE_HPP
#define TO_GRAY_SCALE_HPP



#include "Command.hpp"
#include "Image.hpp"
namespace prog {
    namespace command {
        class to_gray_scale : public Command {
        public:
    /**
     * @brief Constructor for the Invert class.
     */
   to_gray_scale ();

    /**
     * @brief Destructor for the Invert class.
     */
    virtual ~to_gray_scale();

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
#endif //TO_GRAY_SCALE_H