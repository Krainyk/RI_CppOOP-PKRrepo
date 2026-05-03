#pragma once
class Figure {
public:
    virtual double volume() = 0;
};

class Parallelepiped : public Figure {
private:
    double x, y, z;

public:
    Parallelepiped(double a, double b, double c);

    double volume() override;
};

class Pyramid : public Figure {
private:
    double x, y, h;

public:
    Pyramid(double a, double b, double c);

    double volume() override;
};

class Tetrahedron : public Figure {
private:
    double a;

public:
    Tetrahedron(double side);

    double volume() override;
};

class Sphere : public Figure {
private:
    double r;

public:
    Sphere(double radius);

    double volume() override;
};