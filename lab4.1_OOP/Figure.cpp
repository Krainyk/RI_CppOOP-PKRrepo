#include "Figure.h"
Parallelepiped::Parallelepiped(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
}

double Parallelepiped::volume() {
    return x * y * z;
}

Pyramid::Pyramid(double a, double b, double c) {
    x = a;
    y = b;
    h = c;
}

double Pyramid::volume() {
    return (x * y * h) / 3;
}

Tetrahedron::Tetrahedron(double side) {
    a = side;
}

double Tetrahedron::volume() {
    return (a * a * a * 1.414) / 12;
}

Sphere::Sphere(double radius) {
    r = radius;
}

double Sphere::volume() {
    return (4 * 3.14 * r * r * r) / 3;
}