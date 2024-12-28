#ifndef SHAPE_H
#define SHAPE_H
#include "frame.h"
class Shape
{
public:
    Shape() : prev{ last } { last = this; } // Standardkonstruktor
    static void show_all_shapes( Frame* );  // gibt alle Shape Objekte auf Frame* aus
    virtual void draw( Frame* target ) const = 0;   // rein virtuelle Methode
    virtual void move( int hor, int ver ) = 0;
    // etc.
private:
    // rein virtuelle Methode
    static Shape* last; // Zeiger auf die zuletzt erzeugte Figur (d.h. Listenanfang)
    Shape* prev;
};
    // Zeiger auf die zuvor erzeugte Figur
// (d.h. die naechste in der Liste)

#endif // SHAPE_H
