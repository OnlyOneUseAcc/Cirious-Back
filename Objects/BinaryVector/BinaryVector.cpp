#include "BinaryVector.h"


BinaryVector::BinaryVector(float x, float y) {
    this->coord = Coord(x, y);
}

BinaryVector::BinaryVector(const Coord &coord) {
    this->coord = Coord();
    BinaryVector::coord.setX(coord.getX());
    BinaryVector::coord.setY(coord.getY());
}


const Coord &BinaryVector::getCoord() const {
    return coord;
}

void BinaryVector::setCoord(const Coord &coord) {
    BinaryVector::coord.setX(coord.getX());
    BinaryVector::coord.setY(coord.getY());

}

BinaryVector::BinaryVector() {
    this->coord = Coord();
}

BinaryVector operator+(BinaryVector left, BinaryVector right){
    return BinaryVector(left.getCoord() + right.getCoord());
}

float operator*(BinaryVector left, BinaryVector right) {
    return left.getCoord().getX() * right.getCoord().getX() +
        left.getCoord().getY() * right.getCoord().getY();
}
