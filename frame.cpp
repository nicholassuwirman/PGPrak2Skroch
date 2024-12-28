#include "frame.h"
using std::cout;
using std::endl;

Frame::Frame() : frm{} {
    reset(); // Initialize all elements to ' '

}

void Frame::reset()
{
    for (auto &row : frm) {
        row.fill(' '); // Fill all rows with blank spaces
    }
}

void Frame::put_point(int x, int y)
{
    frm.at(x).at(y) = '*';
    cout << "Point added at (" << x << ", " << y << ")" << endl;

}

void Frame::show()
{

    for(int y = 0; y < high; y++) {
        for(int x = 0; x < wide; x++) {

            cout << frm.at(y).at(x);

        }
        cout << endl;

    }

}

bool Frame::on_frame(int x, int y) const
{
    if(x >= wide)
        return false;
    if(y > high)
        return false;
}
