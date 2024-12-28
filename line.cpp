#include "line.h"
using std::cout;

Line::Line(int sx, int sy, int ex, int ey)  : start_x{sx}, start_y{sy}, end_x{ex}, end_y{ey}
{
}

void Line::set(int sx, int sy, int ex, int ey)
{
    start_x = sx;
    start_y = sy;
    end_x = ex;
    end_y = ey;
    cout << "Line set at point 1: " << sx << ", " << sy
         << " and point 2: " << ex << ", " << ey;
}

void Line::draw(Frame* frame) const
{
    int dx = abs(end_x - start_x);
    int dy = abs(end_y - start_y);
    int sx = (start_x < end_x) ? 1 : -1;  // Step direction for x
    int sy = (start_y < end_y) ? 1 : -1;  // Step direction for y
    int err = dx - dy;  // Initial error term

    int x = start_x;
    int y = start_y;

    while (true) {
        // Set the current point on the frame grid
        frame->put_point(x, y);

        // If we've reached the end point, break out of the loop
        if (x == end_x && y == end_y)
            break;

        int e2 = 2 * err;

        // Move in the x direction if necessary
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }

        // Move in the y direction if necessary
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void Line::move(int h, int v)
{

}
