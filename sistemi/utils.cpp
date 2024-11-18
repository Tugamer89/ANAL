#include "utils.h"

Matrix::Matrix(ssize_t n, ssize_t m) {
    this->n = n;
    this->m = m;

    data = new Precision*[n];
    for (ssize_t i = 0; i < n; i++) {
        data[i] = new Precision[m];
        for (ssize_t j = 0; j < m; j++)
            data[i][j] = 0;
    }
}

Matrix Matrix::operator=(const Matrix& other) {
    n = other.n;
    m = other.m;
    data = new Precision*[n];
    for (ssize_t i = 0; i < n; i++) {
        data[i] = new Precision[m];
        for (ssize_t j = 0; j < m; j++)
            data[i][j] = other.data[i][j];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) {
    if  (n != other.n || m != other.m)
        throw std::invalid_argument("Matrices are not the same size");

    Matrix result(n, m);
    for (ssize_t i = 0; i < n; i++)
        for (ssize_t j = 0; j < m; j++)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix operator*(Precision scalar, const Matrix& matrix) {
    Matrix result(matrix.n, matrix.m);
    for (ssize_t i = 0; i < matrix.n; i++)
        for (ssize_t j = 0; j < matrix.m; j++)
            result.data[i][j] = scalar * matrix.data[i][j];
    return result;
}

void Matrix::print() {
    for (ssize_t i = 0; i < n; i++) {
        for (ssize_t j = 0; j < m; j++)
            std::cout << data[i][j] << " ";
     std::cout << std::endl;
    }
}

Precision Matrix::infiniteNorm() {
    Precision maxRow = 0;

    for(ssize_t i = 0; i < n; ++i) {
        Precision sum = 0;
        for(ssize_t j = 0; j < m; ++j)
            sum += abs(data[i][j]);
        maxRow = sum > maxRow ? sum : maxRow;
    }

    return maxRow;
}

void Matrix::swap_rows(ssize_t a, ssize_t b) {
    Precision* tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}

void LinearSystem::computeB() {
    // Moltiplicare A per un vettore di soli 1 e` uguale a sommare ogni elemento della stessa riga
    b = Matrix(A.n, 1);
    for (ssize_t i = 0; i < b.n; ++i)
        for (ssize_t j = 0; j < A.m; ++j)
            b.data[i][0] += A.data[i][j];

    db = Matrix(b.n, b.m);
    for (ssize_t i = 0; i < db.n; ++i)
        db.data[i][0] = pow(-1, i+1) * 0.01;
    db = b.infiniteNorm() * db;
}

void LinearSystem::computeX(Type tp) {
    const ssize_t n = A.n;

    Matrix real_A = A;
    Matrix real_b = b;
    if (tp == Type::ERROR)
        real_b = real_b + db;

    // Gaussian Elimination
    for (ssize_t k = 0; k < n-1; ++k) {
        ssize_t max_pivot = k;

        for (ssize_t i = k+1; i < n; ++i)
            if (fabs(real_A.data[i][k]) > fabs(real_A.data[max_pivot][k]))
                max_pivot = i;

        if (max_pivot != k) {
            real_A.swap_rows(k, max_pivot);
            real_b.swap_rows(k, max_pivot);
        }

        Precision pivot = real_A.data[k][k];
        
        if (pivot == 0)
            throw std::runtime_error("Pivot zero");

        for (ssize_t i = k+1; i < n; ++i) {
            Precision m = real_A.data[i][k] / pivot;
            if (m == 0)
                continue;
            
            for (ssize_t j = 0; j < n; ++j)
                real_A.data[i][j] -= m * real_A.data[k][j];
            real_b.data[i][0] -= m * real_b.data[k][0];
        }
    }


    // Back Substitution
    X = Matrix(n, 1);

    X.data[n-1][0] = real_b.data[n-1][0] / real_A.data[n-1][n-1];
    for (ssize_t i = n-2; i >= 0; --i) {
        Precision sum = 0;
        for (ssize_t j = i+1; j < n; ++j)
            sum += real_A.data[i][j] * X.data[j][0];
        X.data[i][0] = (real_b.data[i][0] - sum) / real_A.data[i][i];
    }
}

void initializeMatrixes(LinearSystem& A1, LinearSystem& A2, LinearSystem& P, LinearSystem& T) {
    // Matricola Tuillier 5441316
    int d1 = 1, d0 = 6;
    int n = 10*(d1 + 1) + d0;

    A1.A = Matrix(4, 4);
    A2.A = Matrix(4, 4);
    P.A = Matrix(10, 10);
    T.A = Matrix(n, n);

    // Popolare A1
    Precision initA1[A1.A.n][A1.A.m] = {
        {3, 1, -1, 0},
        {0, 7, -3, 0},
        {0, -3, 9, -2},
        {0, 0, 4, -10}
    };

    for (ssize_t i = 0; i < A1.A.n; ++i)
        for (ssize_t j = 0; j < A1.A.m; ++j)
            A1.A.data[i][j] = initA1[i][j];

    // Popolare A2
    Precision initA2[A2.A.n][A2.A.m] = {
        {2, 4, -2, 0},
        {1, 3, 0, 1},
        {3, -1, 1, 2},
        {0, -1, 2, 1}
    };

    for (ssize_t i = 0; i < A2.A.n; ++i)
        for (ssize_t j = 0; j < A2.A.m; ++j)
            A2.A.data[i][j] = initA2[i][j];

    // Popolare P
    for (ssize_t i = 0; i < P.A.n; ++i)
        for (ssize_t j = 0; j < P.A.m; ++j)
            P.A.data[i][j] = tgamma(i + j + 1) / (tgamma(i + 1) * tgamma(j + 1)); //tgamma(n) = (n-1)!

    // Popolare T
    for (ssize_t i = 0; i < n; ++i) {
        for (ssize_t j = 0; j < n; ++j) {
            if (i == j)
                T.A.data[i][j] = 2;
            else if (abs(i - j) == 1)
                T.A.data[i][j] = -1;
            else
                T.A.data[i][j] = 0;
        }
    }

    // Popolare le b
    A1.computeB();
    A2.computeB();
    P.computeB();
    T.computeB();
}
