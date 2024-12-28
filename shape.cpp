#include "shape.h"

// Definition of the static member `last`
Shape* Shape::last = nullptr;

void Shape::show_all_shapes(Frame* frame) {
    // Start from the last created shape
    Shape* current = last;

    // Traverse the linked list of shapes
    while (current != nullptr) {
        current->draw(frame); // Call the draw method of each shape
        current = current->prev; // Move to the previous shape in the list
    }
}

