#include <iostream>

using namespace std;
#include "myvector.h"

int main()
{
    Myvector vector1(2, 10);     //created a vector sized 2 with 2 as all of the initialized value
    Myvector vector2 = vector1; //kopier konstruktor
    int size = vector2.size();
    cout << size << " is the size of vector2" << std::endl;

    cout << "-------------------------------------------" << endl;

    int secondValue = vector2[1];
    cout << secondValue << " is the second value of vector2" << std::endl;

    cout << "-------------------------------------------" << endl;

    vector1.reserve(4);
    vector1.push_back(100);
    int thirdValue = vector1[2];    //0,1,2 so third value
    cout << thirdValue << " is the third value of vector2" << std::endl;

    cout << "-------------------------------------------" << endl;

    vector2.push_back(200);
    int value = vector2[2];
    cout << value << " is the third value of vector2" << std::endl;

    cout << "-------------------------------------------" << endl;

    Myvector vector3(1, 1);
    vector3 = vector1;  // This should invoke your copy assignment operator


    return 0;
}
