#include "Scene.h"
#include "../../vstub/VSTUB.H"

void Scene::setDisplay(const NonRegularDisplay &display) {
    this->display = display;
}

void Scene::addSection(Section newSection) {
    sections.push_back(newSection);
}

void Scene::runCut() {
    for (auto & section : sections) {

        bool flagChange = true;

        for (int i = 0; i < display.peaks.size(); i++) {
            Coord f;
            if (i + 1 == display.peaks.size()) {
                f = Coord((display.peaks[i].getX() + display.peaks[0].getX()) / 2, (display.peaks[i].getY() + display.peaks[0].getY()) / 2);
            }
            else {
                f = Coord((display.peaks[i].getX() + display.peaks[i+1].getX()) / 2, (display.peaks[i].getY() + display.peaks[i+1].getY()) / 2);
            }
            BinaryVector w(section.getBottom() - f);
            if (section.getDirection() * display.normals[i] == 0) {
                if (w * display.normals[i] < 0) {
                    flagChange = false;
                    break;
                }
                else {
                    continue;
                }
            }
            else {
                float temp = -(w * display.normals[i]) / (section.getDirection() * display.normals[i]);
                if (section.getDirection() * display.normals[i] > 0) {
                    if (temp > 1) {
                        flagChange = false;
                        break;
                    }
                    else {
                        section.setTBottom(std::max(temp, section.getTBottom()));
                    }
                }
                else {
                    if (temp < 0) {
                        continue;
                    }
                    else {
                        section.setTTop(std::min(temp, section.getTTop()));
                        continue;
                    }
                }
            }
            if (section.getTTop() >= section.getTBottom() && flagChange) {
                section.calculateCoordDisplay();
            }
        }
    }

}

void Scene::drawOnDisplay() {
    display.draw();
    std::setcolor(0, 250, 0);

    for (int i = 0; i < sections.size(); ++i) {
        Section& section = sections[i];
        if (section.getTopDisplay().getX() == -1) {
            continue;
        }
        section.drawOnDisplay();

    }

}

