#include "Matrix.h"

void Matrix::allocateMemory(int r, int c) {
    rows = r;
    cols = c;
    if (r <= 0 || c <= 0) {
        data = nullptr;
        return;
    }
    data = new float* [rows];
    for (int i = 0; i < rows; i++)
        data[i] = new float[cols] {0};
}

void Matrix::freeMemory() {
    if (data) {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
		data = nullptr;
    }
}

Matrix::Matrix() : data(nullptr), rows(0), cols(0) {}

Matrix::Matrix(int n) {
    allocateMemory(n, n);
}

Matrix::Matrix(int r, int c) {
    allocateMemory(r, c);
}

Matrix::Matrix(const Matrix& m) {
    allocateMemory(m.rows, m.cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = m.data[i][j];
}

Matrix::~Matrix() {
    if (data != nullptr)
        freeMemory();
}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }

Matrix& Matrix::operator=(const Matrix& m) {
    if (this != &m) {
        if (data != nullptr)
            freeMemory();

        allocateMemory(m.rows, m.cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = m.data[i][j];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& m) const {
    if (rows != m.rows || cols != m.cols) {
        cout << "Помилка: різні розміри\n";
        exit(1);
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] + m.data[i][j];
    return result;
}

Matrix Matrix::operator-(const Matrix& m) const {
    if (rows != m.rows || cols != m.cols) {
        cout << "Помилка: різні розміри\n";
        exit(1);
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] - m.data[i][j];

    return result;
}

Matrix& Matrix::operator+=(const Matrix& m) {
	*this = *this + m;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
    if (rows != m.rows || cols != m.cols) {
        cout << "Помилка: різні розміри\n";
        exit(1);
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] -= m.data[i][j];

    return *this;
}

Matrix& Matrix::operator*=(float k) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] *= k;

    return *this;
}

istream& operator>>(istream& in, Matrix& m) {
	if (!m.data) return in;
    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < m.rows; i++)
        for (int j = 0; j < m.cols; j++)
            in >> m.data[i][j];
    return in;
}

ostream& operator<<(ostream& out, const Matrix& m) {
    if (!m.data) {
        out << "Порожня матриця";
        return out;
    }
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++)
            out << m.data[i][j] << "\t";
        out << endl;
    }
    return out;
}