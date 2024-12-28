#include <iostream>
#include "frame.h"
#include "line.h"
#include "square.h"
#include "rechtangle.h"
#include "triangle.h"
using namespace std;

Frame* frameObj = new Frame;    //karena dia maunya Frame*

// const int wide{10};
// const int high{5};

void testLine() {
    Line line(1, 1, 4, 4);
}

void testSquare() {
    Square square(4, 4, 4);
    square.move(1,2);
    //square.draw(frameObj);
    square.draw(frameObj);

}

void testRechtangle() {
    Rechtangle rechtangle(2, 2, 4, 10);
    rechtangle.draw(frameObj);
}
void testTriangle() {
    Triangle t1(0, 0, 3, 0, 1, 2);  // Valid triangle
    t1.draw(frameObj);
}

void testAllShapes() {
    Square square(0, 0, 3);
    square.draw(frameObj);

    Rechtangle rechtangle(5, 5, 4, 10);
    rechtangle.draw(frameObj);

    Shape::show_all_shapes(frameObj);
}
int main()
{
    testAllShapes();

    frameObj->show();

    return 0;
}
