#ifndef REPLACE_H
#define REPLACE_H

#include "Command.hpp"
#include "Color.hpp"
#include "Image.hpp"

namespace prog
{
    class Replace : public Command
    {
    private:
        Color targetColor;
        Color replacementColor;
        Color r1, r2;

    public:
        Replace();
        virtual ~Replace();
        
        Replace(const Color& r1, const Color& r2);
        Image* apply(Image* image) override;
        std::string toString() const override;
        
    };
}
#endif //REPLACE_H