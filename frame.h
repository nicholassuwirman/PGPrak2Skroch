#ifndef FRAME_H
#define FRAME_H
#include <iostream>
#include <array>
const int wide{20}; // globale Konstante: 55 Zeichen pro Zeile
const int high{10}; // globale Konstante: 34 Zeilen pro Frame

class Frame
{
public:
    enum color { black = ' ', white = '*' };
    Frame();
    // oder: Frame() = default;
    void reset();
    void put_point( int x, int y);
    void show() ;
    // Frame leeren, d.h. alle Punkte auf black
    // ein Punkt im Frame auf white
    // Frame auf die Konsole ausgeben
    bool on_frame( int x, int y) const; // "Clipping"
private:
    std::array< std::array<char,wide>, high > frm;
};

#endif // FRAME_H
