#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
using std::cout;
using std::endl;
template<class T> class Myvector
{
public:
    Myvector() : sz{0}, space{0}, elem{nullptr}{}
    //zB: Myvector vec(2, 3) //vec will have 2 elements and initialized to 3
    Myvector(int s, T inializeValue) : sz{s}, space{s}, elem{ new T[s]{} }
    {
        for (int i = 0; i < s; ++i) {
            elem[i] = inializeValue; // Initialize all elements to default_value
        }

        cout << "Myvector created" << endl;
    }

    Myvector(const Myvector& otherVector) : sz(otherVector.sz), space(otherVector.space), elem(nullptr)
    {
        elem = new T[space];

        for(int i = 0; i < sz; i++) {
            elem[i] = otherVector.elem[i];
        }
        cout << "Copy constructor called" << endl;
    }

    Myvector<T>& operator=(const Myvector<T>& otherVector) {
        // Check for self-assignment
        if (this == &otherVector) {
            return *this;
        }

        // Free the existing memory (if any)
        delete[] elem;

        // Allocate new memory and copy data
        sz = otherVector.sz;
        space = otherVector.space;
        elem = new T[space];

        for (int i = 0; i < sz; i++) {
            elem[i] = otherVector.elem[i];
        }
        cout << "overloaded operator = called" << endl;

        return *this; // Return the current object (this)
    }


    ~Myvector()
    {
        delete[] elem;

        cout << "Destructor called" << endl;
    }

    int size() const
    {
        return sz;

        cout << "Size called" << endl;
    }

    int capacity() const
    {
        return space;

        cout << "Capacity called" << endl;
    }

    T& operator[](int index) const
    {
        return elem[index];

        cout << "Operator overloading [] called" << endl;
    }

    T& at(int index) const
    {
        return elem[index];

        cout << "at index() called" << endl;
    }

    void reserve(int spaceToReserveInt)
    {
        //int intArr = new int[3]

        //when space is already as big as the spaceToReserve, then return nothing or skip the function
        if (spaceToReserveInt <= space) return;

        //newVector is now the pointer to the new vector row: 0000|0001|00002 it points to 0000
        T* newVector = new T[spaceToReserveInt];

        for(int i = 0; i < sz; i++) {
            newVector[i] = elem[i]; //copy all element to newVector
        }

        delete[] elem;  //deallocate the elem space

        //T* elem, so elem is basically a pointer. now point it to the newVector which is also a pointer to the newly made array
        elem = newVector;

        space = spaceToReserveInt;  //change the space

        cout << "Reserve called" << endl;
    }
    void resize(int newSize, T value) {
        if (newSize < sz) {
            // If new size is smaller, just reduce the logical size.
            sz = newSize;
            return;
        }

        // If new size is larger, ensure sufficient capacity
        if (newSize > space)
            reserve(newSize); // Expand capacity if necessary.

        // Initialize new elements with `value`
        for (int i = sz; i < newSize; ++i) {
            elem[i] = value;
        }

        // Update logical size
        sz = newSize;

        cout << "Resize called" << endl;
    }
    void push_back(const T& value) {
        // Check if there's enough capacity
        if (sz == space) {
            // Double the capacity if full, or initialize to 1 if empty
            reserve(space == 0 ? 1 : 2 * space);
            cout << "Space doubled" << endl;

        }

        // Add the new element
        elem[sz] = value;

        // Increment the logical sizes
        ++sz;

        cout << "Push back called" << endl;
    }
private:
    int sz;       // Anzahl Elemente
    int space;    // Anzahl Elemente plus weiterer Platz
    T* elem; // Zeiger auf die Elemente

};
#endif // MYVECTOR_H
