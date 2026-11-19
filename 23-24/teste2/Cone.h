#include <iostream>
#include <cmath>
#include "Solid3D.h"
using namespace std;

class Cone : public Solid3D{
    
    public:
    
    Cone(point c, double radius, double height) : Solid3D(c), radius_(radius), height_(height){};
    
    double radius() const { 
      return radius_;
    }

    double height() const{
      return height_;
    }

    virtual double volume() const{
      return (M_PI*(radius_*radius_)*height_)/3;
    }

    private:
    double radius_, height_;
};














int main(void){
    { const Cone c({0, 0, 0}, 1, 1);
      cout << c.center() << ' ' 
           << c.radius() << ' ' 
           << c.height() << ' ' 
           << c.volume() << endl; }

    { const Cone c({0.1, 2.3, 4.5}, 1.2, 3.4);
      cout << c.center() << ' ' 
           << c.radius() << ' ' 
           << c.height() << ' ' 
           << c.volume() << endl; }

    { const Solid3D& s = Cone({-1.2, -3.4, -5.6}, 1.2, 0.34);
      cout << s.center() << ' ' << s.volume() << endl; }

    { const Solid3D& s = Cone({12.3, 34.5, 56.7}, 12.3, 0.51);
      cout << s.center() << ' ' << s.volume() << endl; }

    return 0;
}