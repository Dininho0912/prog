#include <iostream>
#include "Piece.h"
#include "Domino.h"

using namespace std;

const Piece& Domino::left()const{
    return pieces_.front();
}

const Piece& Domino::right()const{
    return pieces_.back(); 
}


bool Piece::can_be_left_to(const Piece& other) const{
    if(other.left_==Piece::right_){
        return true;
    }
    else { 
        return false;
    }
}

bool Piece::can_be_right_to(const Piece& other) const{
    if(other.right_==Piece::left_){
        return true;
    }
    else { 
        return false;
    }
}

bool Domino::place_left(const Piece& p){
    if(pieces_.empty() || p.can_be_left_to(pieces_.front())){
        Domino::pieces_.push_front(p);
        return true;
    }
    return false;
}

bool Domino::place_right(const Piece& p){
    if(pieces_.empty() || p.can_be_left_to(pieces_.back())){
        Domino::pieces_.push_back(p);
        return true;
    }
    return false;
}



int main(void){
    { Piece p (1, 2);
      cout << boolalpha 
           << p.can_be_left_to({2, 3}) << ' ' 
           << p.can_be_left_to({3, 2}) << ' ' 
           << p.can_be_right_to({3, 2}) << ' ' 
           << p.can_be_right_to({0, 1}) << '\n'; }


    { Domino d( { {1,2}, {2,0}, {0,6}, {6,6} } );
      cout << d.left().to_string() << ' '
           << d.right().to_string() << ' '
           << d.to_string() << '\n'; }

    
    { Domino d( { {1,2}, {2,0}, {0,6}, {6,6} } );
      cout << boolalpha
           << d.place_left({6,1})  << ' '
           << d.place_right({3,6}) << ' '
           << d.to_string() << '\n'; }

    
    { Domino d( { {1,2}, {2,3}, {3,3}, {3,4} } );
      cout << boolalpha
           << d.place_left({4,3})  << ' '
           << d.place_right({4,1}) << ' '
           << d.to_string() << '\n'; }


    { Domino d( { {1,2}, {2,3}, {3,3}, {3,6} } );
      cout << boolalpha
           << d.place_left({1,1})  << ' '
           << d.place_right({6,6}) << ' '
           << d.to_string() << '\n'; }

    return 0;
}