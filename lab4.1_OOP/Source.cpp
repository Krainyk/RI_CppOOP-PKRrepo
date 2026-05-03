#include "Figure.h"
#include <iostream>
using namespace std;

int main() {
    Figure* arr[4];

    arr[0] = new Parallelepiped(2, 3, 4);
    arr[1] = new Pyramid(3, 4, 6);
    arr[2] = new Tetrahedron(3);
    arr[3] = new Sphere(2);

    for (int i = 0; i < 4; i++) {
        cout << "Obem = " << arr[i]->volume() << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }

    return 0;
}