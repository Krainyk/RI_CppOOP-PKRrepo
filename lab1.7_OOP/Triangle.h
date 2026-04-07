#pragma once
class Point {
private:
		double x, y;
public:
	void Init(double x0, double y0);

	double getX() const { return x; }
	double getY() const { return y; }

	void moveX(double dx) { x += dx; }
	void moveY(double dy) { y += dy; }

	double distanceToOrigin() const;
	double distanceTo(const Point& p) const;

	void toPolar() const;
	bool equals(const Point& p) const;
	void Display() const;
};

class Triangle {
private:
	Point P1, P2, P3;
    double side(const Point& a, const Point& b) const;
public:
	void Init(Point a, Point b, Point c);
	double get_a() const { return side(P2, P3); }
	double get_b() const { return side(P1, P3); }
	double get_c() const { return side(P1, P2); }

	double perimeter() const;
	double area() const;

	double heightA() const { return 2 * area() / get_a(); }
	double heightB() const { return 2 * area() / get_b(); }
	double heightC() const { return 2 * area() / get_c(); }

	void type() const;
	
	double get_A() const;
	double get_B() const;
	double get_C() const;

	void Display() const;
};