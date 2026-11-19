#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Floatable.h"
#include <string>
using namespace std;

class Submarine : public Floatable{
public:
    Submarine(int id, double mass, const string captain) : Floatable(id, mass), captain_(captain){}

    ~Submarine(){}

    string captain() const{
        return captain_;
    }

    double buoyancy() const override{
        const double gravity = 9.81;
        const double density = 1025.0;
        return mass() * gravity * density;
    }

private:
    string captain_;
};

#endif //SUBMARINE_H