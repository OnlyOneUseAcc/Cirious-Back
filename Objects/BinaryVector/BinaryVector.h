#ifndef RAY2_BINARYVECTOR_H
#define RAY2_BINARYVECTOR_H


#include "../Coord/Coord.h"

class BinaryVector {

private:
    Coord coord;

public:
    BinaryVector();
    BinaryVector(const Coord& coord);
    BinaryVector(float x, float y);

    const Coord &getCoord() const;
    void setCoord(const Coord &coord);

    friend BinaryVector operator+(BinaryVector left, BinaryVector right);
    friend float operator*(BinaryVector left, BinaryVector right);

};


#endif //RAY2_BINARYVECTOR_H
