#include "Coord.h"

Coord::Coord() = default;

Coord::Coord(float x, float y) {
    this->x = x;
    this->y = y;
}

float Coord::getX() const {
    return x;
}

void Coord::setX(float x) {
    Coord::x = x;
}

float Coord::getY() const {
    return y;
}

void Coord::setY(float y) {
    Coord::y = y;
}

Coord operator+(Coord left, Coord right) {
    return Coord(left.x + right.x, left.y + right.y);
}

Coord operator-(Coord left, Coord right) {
    return Coord(left.x - right.x, left.y - right.y);
}

Coord operator*(Coord left, float right) {
    return Coord(left.x * right, left.y * right);
}
