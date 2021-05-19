#include "NonRegularDisplay.h"
#include "../../vstub/VSTUB.H"

NonRegularDisplay::NonRegularDisplay(std::vector<Coord> &peaks)
        : peaks(peaks) {
                 calculateNormals();
}

void NonRegularDisplay::calculateNormals() {
    for (auto it = peaks.begin(); it != peaks.end(); ++it) {
        if (it + 1 == peaks.end()) {
            normals.emplace_back(peaks[0].getY() - it->getY(),
                                           -(peaks[0].getX() - it->getX()));
        }
        else {
            normals.emplace_back((it + 1)->getY() - it->getY(),
                                           -((it + 1)->getX() - it->getX()));
        }
    }
}

void NonRegularDisplay::draw() {
    for (auto it = peaks.begin(); it != peaks.end(); ++it) {
        if (it + 1 == peaks.end()) {
            std::drawline(it->getX(), it->getY(), peaks[0].getX(), peaks[0].getY());
        }
        else std::drawline(it->getX(), it->getY(), (it+1)->getX(), (it+1)->getY());

    }
}