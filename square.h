#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
class Square : public Shape
{
public:
    Square() = delete; // kein Standardquadrat
    Square( int nwx, int nwy, int len ); // ein Konstruktor
    void draw( Frame* frame) const; // rein virtuelles shape::draw() ueberschreiben
    void move( int h, int v ); // rein virtuelles shape::move() ueberschreiben

    int getNw_x() const;

    int getNw_y() const;

    int getLen() const;

private:
    int nw_x, nw_y, len;
};

#endif // SQUARE_H
