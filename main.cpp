#include <iostream>
#include <vector>
#include "vstub/VSTUB.H"
#include "Objects/Section.h"
#include "Views/NonRegularDisplay/NonRegularDisplay.h"
#include "Views/Scene/Scene.h"

namespace std {
    int main() {
        std::drawgrid();

        std::setcolor(210, 75, 190);
        std::vector<Coord> peaks = { Coord(100, 50), Coord(50, 150), Coord(100, 250), Coord(300, 250), Coord(350, 150), Coord(300, 50) };
        NonRegularDisplay display(peaks); //задаем дисплей
        display.draw();

        Section line1(Coord(50, 75), Coord(400, 275)); //задаем отрезки
        Section line2(Coord(50, 200), Coord(400, 200));

        Scene scene; //задаем сцену
        scene.setDisplay(display); //устанавливаем дисплей в сцену
        scene.addSection(line1); //добавляем отрезки в сцену
        scene.addSection(line2);
        scene.runCut(); //запускаем алгоритм Кируса-Бека
        scene.drawOnDisplay(); //отрисовываем

        std::TFlush();
        std::vgetchar();

        return 0;
    }
}