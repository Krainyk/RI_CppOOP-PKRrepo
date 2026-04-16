#pragma once
#include <iostream>
using namespace std;

class Matrix {
private:
    float** data;
    int rows;
    int cols;

    void allocateMemory(int r, int c);
    void freeMemory();

public:
    Matrix();                 
    Matrix(int n);            
    Matrix(int r, int c);      
    Matrix(const Matrix& m);   
    ~Matrix();                 

    int getRows() const;
    int getCols() const;

    Matrix& operator=(const Matrix& m);

    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;

    Matrix& operator+=(const Matrix& m);
    Matrix& operator-=(const Matrix& m);

    Matrix& operator*=(float k); 

    friend istream& operator>>(istream& in, Matrix& m);
    friend ostream& operator<<(ostream& out, const Matrix& m);
};
