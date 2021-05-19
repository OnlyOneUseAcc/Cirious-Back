#ifndef RAY2_NONREGULARDISPLAY_H
#define RAY2_NONREGULARDISPLAY_H


#include <vector>
#include "../../Objects/Coord/Coord.h"
#include "../../Objects/BinaryVector/BinaryVector.h"

class NonRegularDisplay {

private:
    std::vector<Coord> peaks;
    std::vector<BinaryVector> normals;

public:

    NonRegularDisplay(std::vector<Coord>& n_peaks);
    NonRegularDisplay() = default;
    void calculateNormals();
    void draw();
    friend class Scene;
};


#endif //RAY2_NONREGULARDISPLAY_H
