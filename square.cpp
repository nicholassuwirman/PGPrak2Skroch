#include "square.h"


Square::Square(int nwx, int nwy, int len) : nw_x(nwx), nw_y(nwy), len(len)
{

}

void Square::draw(Frame* frame) const
{
    int incrementX = nw_x;
    int incrementy = nw_y;

    while(incrementX < len + nw_x - 1) {
        incrementX++;
        frame->put_point(incrementX, incrementy);
    }
    while(incrementy < len*2 + nw_y - 1) {
        incrementy++;
        frame->put_point(incrementX, incrementy);
    }
    while(incrementX > nw_x) {
        incrementX--;
        frame->put_point(incrementX, incrementy);
    }
    while(incrementy > nw_y) {
        incrementy--;
        frame->put_point(incrementX, incrementy);
    }
}

void Square::move(int h, int v)
{
    nw_x -= h;
    nw_y -= v;
}

int Square::getNw_x() const
{
    return nw_x;
}

int Square::getNw_y() const
{
    return nw_y;
}

int Square::getLen() const
{
    return len;
}
