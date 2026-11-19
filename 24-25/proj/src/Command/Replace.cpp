#include "Image.hpp"
#include "Color.hpp"
#include "Command.hpp"
#include "Command/Replace.hpp"
#include "string"
#include <cmath>

namespace prog {
    Replace::Replace() : Command("replace") {}
    Replace::~Replace() {}
    
    Replace::Replace(const Color& r1, const Color& r2)
        : targetColor(r1), replacementColor(r2) {}
    
    Image* Replace::apply(Image* image) {
        if(!image) return nullptr;

        for(int y = 0; y < image->height(); ++y) {
            for(int x = 0; x < image->width(); ++x) {
                Color currentColor = image->at(x, y);
                if(currentColor == targetColor) {
                    image -> at(x, y) = replacementColor;
                }
            }
        }

            return image;
    }
        
    std::string Replace::toString() const {
        return "replace " + std::to_string((int)targetColor.red()) + " "
                          + std::to_string((int)targetColor.green()) + " "
                          + std::to_string((int)targetColor.blue()) + " "
                          + std::to_string((int)replacementColor.red()) + " "
                          + std::to_string((int)replacementColor.green()) + " "
                          + std::to_string((int)replacementColor.blue());
        }
        
}