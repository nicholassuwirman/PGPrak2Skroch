#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <cmath>
#include <algorithm> // For std::sort

class Triangle : public Shape {
public:
    // Constructor with three vertex coordinates
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

    // Constructor with reference point and three side lengths
    Triangle(int hor, int ver, int len1, int len2, int len3);

    // Draw the triangle on a Frame
    void draw(Frame* frame) const override;

    // Move the triangle
    void move(int hor, int ver) override;

private:
    int x1, y1, x2, y2, x3, y3; // Coordinates of the triangle's vertices

    // Helper to check if three points form a valid triangle
    bool is_valid_triangle(int x1, int y1, int x2, int y2, int x3, int y3) const;

    // Helper to calculate third vertex given two points and lengths
    void calculate_third_vertex(int hor, int ver, int a, int b, int c);
};

#endif // TRIANGLE_H
