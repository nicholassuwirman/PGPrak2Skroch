#include "rechtangle.h"



Rechtangle::Rechtangle(int nwx, int nwy, int lenghtX, int lengthY) : nw_x(nwx), nw_y(nwy), lenX(lenghtX), lenY(lengthY)
{

}

void Rechtangle::draw(Frame *frame) const
{
    int incrementX = nw_x;
    int incrementy = nw_y;

    while(incrementX < lenX + nw_x - 1) {
        incrementX++;
        frame->put_point(incrementX, incrementy);
    }
    while(incrementy < lenY + nw_y - 1) {
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

void Rechtangle::move(int h, int v)
{
    nw_x -= h;
    nw_y -= v;
}

int Rechtangle::getNw_x() const
{
    return nw_x;
}

int Rechtangle::getNw_y() const
{
    return nw_y;
}

int Rechtangle::getLenX() const
{
    return lenX;
}

int Rechtangle::getLenY() const
{
    return lenY;
}


