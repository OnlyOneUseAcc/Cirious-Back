#ifndef RAY2_COORD_H
#define RAY2_COORD_H


class Coord {
private:
    float x;
    float y;

public:
    Coord();
    Coord(float x, float y);

    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);

    friend Coord operator-(Coord left, Coord right);
    friend Coord operator+(Coord left, Coord right);
    friend Coord operator*(Coord left, float right);


};


#endif //RAY2_COORD_H
