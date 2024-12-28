#include "triangle.h"
#include "line.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : x1{x1}, y1{y1}, x2{x2}, y2{y2}, x3{x3}, y3{y3} {
    if (!is_valid_triangle(x1, y1, x2, y2, x3, y3)) {
        throw std::invalid_argument("Invalid triangle vertices.");
    }
}

// Helper: Check if three points form a valid triangle
bool Triangle::is_valid_triangle(int x1, int y1, int x2, int y2, int x3, int y3) const {
    double a = std::hypot(x2 - x1, y2 - y1);
    double b = std::hypot(x3 - x2, y3 - y2);
    double c = std::hypot(x3 - x1, y3 - y1);

    return (a + b > c) && (b + c > a) && (a + c > b);
}
Triangle::Triangle(int hor, int ver, int len1, int len2, int len3) {
    // Sort lengths so that a >= b >= c
    int lengths[] = {len1, len2, len3};
    std::sort(lengths, lengths + 3, std::greater<int>());
    int a = lengths[0], b = lengths[1], c = lengths[2];

    // p1 (hor, ver), p2 (hor + a, ver)
    x1 = hor; y1 = ver;
    x2 = hor + a; y2 = ver;

    // Calculate p3
    calculate_third_vertex(hor, ver, a, b, c);
}

// Helper: Calculate third vertex
void Triangle::calculate_third_vertex(int hor, int ver, int a, int b, int c) {
    // Using Pythagoras: y3 = sqrt(b^2 - c_x^2), where c_x = a - b (horizontal offset)
    int c_x = a - (b * b - c * c + a * a) / (2 * a);
    int c_y = static_cast<int>(std::sqrt(b * b - c_x * c_x));

    x3 = x1 + c_x;
    y3 = y1 + c_y;
}
void Triangle::draw(Frame* frame) const {
    Line line1(x1, y1, x2, y2);
    Line line2(x2, y2, x3, y3);
    Line line3(x3, y3, x1, y1);

    line1.draw(frame);
    line2.draw(frame);
    line3.draw(frame);
}
void Triangle::move(int hor, int ver) {
    x1 += hor; y1 += ver;
    x2 += hor; y2 += ver;
    x3 += hor; y3 += ver;
}
