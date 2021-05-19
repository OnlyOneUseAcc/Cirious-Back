//
// Created by Алексей on 19.05.2021.
//

#ifndef RAY2_SCENE_H
#define RAY2_SCENE_H


#include "../../Objects/Section.h"
#include "../NonRegularDisplay/NonRegularDisplay.h"

class Scene {

private:
    NonRegularDisplay display;
    std::vector<Section> sections;

public:
    Scene() = default;
    void setDisplay(const NonRegularDisplay& display);
    void addSection(Section newSection);
    void runCut();
    void drawOnDisplay();
};


#endif //RAY2_SCENE_H
