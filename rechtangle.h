#ifndef RECHTANGLE_H
#define RECHTANGLE_H

#include "shape.h"
class Rechtangle : public Shape
{
public:
    Rechtangle() = delete; // kein Standardquadrat
    Rechtangle( int nwx, int nwy, int lenghtX, int lengthY ); // ein Konstruktor
    void draw( Frame* frame) const; // rein virtuelles shape::draw() ueberschreiben
    void move( int h, int v ); // rein virtuelles shape::move() ueberschreiben

    int getNw_x() const;

    int getNw_y() const;


    int getLenX() const;

    int getLenY() const;

private:
    int nw_x, nw_y, lenX, lenY;
};

#endif // RECHTANGLE_H
