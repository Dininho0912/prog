#ifndef __svg_SVGElements_hpp__
#define __svg_SVGElements_hpp__

#include "Color.hpp"
#include "Point.hpp"
#include "PNGImage.hpp"

namespace svg {
    class SVGElement {
    public:
        SVGElement();
        virtual ~SVGElement();
        virtual void draw(PNGImage &img) const = 0;
    };

    void readSVG(const std::string &svg_file, Point &dimensions, std::vector<SVGElement *> &svg_elements);
    void convert(const std::string &svg_file, const std::string &png_file);

    class Ellipse : public SVGElement {
    public:
        Ellipse(const Color &fill, const Point &center, const Point &radius);
        void draw(PNGImage &img) const override;

    private:
        Color fill;
        Point center;
        Point radius;
    };

    class Circle : public SVGElement {
    public:
        Circle(const Color &fill, const Point &center, const Point &radius);
        void draw(PNGImage &img) const override;

    private:
        Color fill;
        Point center;
        Point radius;
    };

    class Polyline : public SVGElement {
    public:
        Polyline(const std::vector<Point>& points, const Color &fill);
        void draw(PNGImage &img) const override;

    private:
        std::vector<Point> points;
        Color fill;
    };

    class Line : public SVGElement {
    public:
        Line(const Color &fill, const Point &start, const Point &end);
        void draw(PNGImage &img) const override;

    private:
        Color fill;
        Point start;
        Point end;
    };

    class Polygon : public SVGElement {
    public:
        Polygon(const std::vector<Point>& points, const Color &fill);
        void draw(PNGImage &img) const override;

    private:
        std::vector<Point> points;
        Color fill;
    };

    class Rect : public SVGElement {
    public:
        Rect(const Color &fill, Point corner, int length, int height);
        void draw(PNGImage &img) const override;

    private:
        Color fill;
        Point corner;
        int length;
        int height;
    };

    class Group : public SVGElement {
    public:
        Group() {}
        virtual ~Group() {
            for (SVGElement* element : elements) {
                delete element;
            }
        }

        void draw(PNGImage &img) const override {
            for (SVGElement* element : elements) {
                element->draw(img);
            }
        }

        void add_el(SVGElement* element) {
            elements.push_back(element);
        }

    private:
        std::vector<SVGElement*> elements;
    };
}

#endif
