#include "Section.h"
#include "../vstub/VSTUB.H"

Section::Section(Coord &n_top, Coord &n_bottom):top(n_top), bottom(n_bottom)
{
    direction.setCoord(Coord(top.getX() - bottom.getX(),
                             top.getY() - bottom.getY()));
}

void Section::calculateCoordDisplay() {
    topDisplay = bottom + (top - bottom) * tTop;
    bottomDisplay = bottom + (top - bottom) * tBottom;
}

void Section::draw() {
    std::drawline(top.getX(), top.getY(), bottom.getX(), bottom.getY());
}

void Section::drawOnDisplay() {
    std::drawline(topDisplay.getX(), topDisplay.getY(), bottomDisplay.getX(), bottomDisplay.getY());

}

const Coord &Section::getTop() const {
    return top;
}

const Coord &Section::getBottom() const {
    return bottom;
}

const Coord &Section::getTopDisplay() const {
    return topDisplay;
}

const Coord &Section::getBottomDisplay() const {
    return bottomDisplay;
}

const BinaryVector &Section::getDirection() const {
    return direction;
}

float Section::getTTop() const {
    return tTop;
}

float Section::getTBottom() const {
    return tBottom;
}

void Section::setTTop(float tTop) {
    Section::tTop = tTop;
}

void Section::setTBottom(float tBottom) {
    Section::tBottom = tBottom;
}

Section::Section(Coord &&n_top, Coord &&n_bottom) :top(n_top), bottom(n_bottom)
{
    direction.setCoord(Coord(top.getX() - bottom.getX(), top.getY() - bottom.getY()));
}
