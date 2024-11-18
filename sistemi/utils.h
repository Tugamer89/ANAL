#pragma once
#include <iostream>
#include <math.h>

#ifdef SINGLE
typedef float Precision;
#else
typedef double Precision;
#endif

class Matrix {
public:
    ssize_t n = 0, m = 0;
    Precision** data = nullptr;

    Matrix() = default;
    Matrix(ssize_t n, ssize_t m);

    Matrix operator=(const Matrix& other);
    Matrix operator+(const Matrix& other);
    friend Matrix operator*(Precision scalar, const Matrix& matrix);

    void print();
    Precision infiniteNorm();
    void swap_rows(ssize_t a, ssize_t b);

private:
};

class LinearSystem {
public:
    enum class Type {NORMAL, ERROR};

    Matrix A, b, db, X;

    LinearSystem() = default;

    void computeB();
    void computeX(Type tp = Type::NORMAL);
private:
};

void initializeMatrixes(LinearSystem& A1, LinearSystem& A2, LinearSystem& P, LinearSystem& T);
