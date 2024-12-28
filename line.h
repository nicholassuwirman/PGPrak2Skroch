#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape
{
public:
    Line() = delete; // keine Standardlinie
    Line( int sx, int sy, int ex, int ey ); // ein Konstruktor
    void set( int sx, int sy, int ex, int ey);
    void draw( Frame* frame) const; // rein virtuelles shape::draw() ueberschreiben
    void move( int h, int v ); // rein virtuelles shape::move() ueberschreiben

private:
    int start_x, start_y, end_x, end_y;
};

#endif // LINE_H
