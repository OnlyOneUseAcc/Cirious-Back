#ifndef RAY2_SECTION_H
#define RAY2_SECTION_H


#include "Coord/Coord.h"
#include "BinaryVector/BinaryVector.h"

class Section {
private:
    Coord top;

public:
    const Coord &getTop() const;
    const Coord &getBottom() const;
    const Coord &getTopDisplay() const;
    const Coord &getBottomDisplay() const;
    const BinaryVector &getDirection() const;
    float getTTop() const;
    float getTBottom() const;
    void setTTop(float tTop);
    void setTBottom(float tBottom);

private:
    Coord bottom;
    Coord topDisplay = Coord(-1, -1);
    Coord bottomDisplay = Coord(-1, -1);
    BinaryVector direction;
    float tTop = 1;

private:
    float tBottom = 0;

public:
    Section(Coord& n_top, Coord& n_bottom);
    Section(Coord&& n_top, Coord&& n_bottom);
    void calculateCoordDisplay();
    void draw();
    void drawOnDisplay();
};


#endif //RAY2_SECTION_H
