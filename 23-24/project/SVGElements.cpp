#include "SVGElements.hpp"

namespace svg {
    // Construtor padrão para SVGElement.
    SVGElement::SVGElement() {}
    
    // Destrutor virtual para SVGElement.
    SVGElement::~SVGElement() {}

    // Construtor para Ellipse
    Ellipse::Ellipse(const Color &fill, const Point &center, const Point &radius) : fill(fill), center(center), radius(radius) {}
    void Ellipse::draw(PNGImage &img) const {
        img.draw_ellipse(center, radius, fill);
    }

    // Construtor para Circle
    Circle::Circle(const Color &fill, const Point &center, const Point &radius)
        : fill(fill), center(center), radius(radius) {}
    void Circle::draw(PNGImage &img) const {
        img.draw_ellipse(center, radius, fill);
    }

    // Construtor para Polyline
    Polyline::Polyline(const std::vector<Point>& points, const Color &fill)
        : points(points), fill(fill) {}
    void Polyline::draw(PNGImage &img) const {
        img.draw_polygon(points, fill);
    }

    // Construtor para Line
    Line::Line(const Color &fill, const Point &start, const Point &end)
        : fill(fill), start(start), end(end) {}
    void Line::draw(PNGImage &img) const {
        img.draw_line(start, end, fill);
    }

    // Construtor para Polygon
    Polygon::Polygon(const std::vector<Point>& points, const Color &fill)
        : points(points), fill(fill) {}
    void Polygon::draw(PNGImage &img) const {
        img.draw_polygon(points, fill);
    }

    // Construtor para Rect
    Rect::Rect(const Color &fill, const Point corner, int length, int height)
        : fill(fill), corner(corner), length(length), height(height) {}
    void Rect::draw(PNGImage &img) const {
        std::vector<Point> points = {
            corner,
            Point{corner.x + length, corner.y},
            Point{corner.x + length, corner.y + height},
            Point{corner.x, corner.y + height}
        };
        img.draw_polygon(points, fill);
    }
}