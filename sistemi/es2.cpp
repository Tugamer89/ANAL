#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void print_matrix(float **matrix, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            printf("%f ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

float** compute_b(float **A, size_t n) {
    // Moltiplicare A per un vettore di soli 1 e` uguale a sommare ogni elemento della stessa riga
    float **b = new float*[n];
    for (size_t i = 0; i < n; ++i) {
        b[i] = new float[1];
        b[i][0] = 0;

        for (size_t j = 0; j < n; ++j)
            b[i][0] += A[i][j];
    }

    return b;
}

void swap_rows(float **matrix, size_t a, size_t b) {
    float *tmp = matrix[a];
    matrix[a] = matrix[b];
    matrix[b] = tmp;
}

bool gaussian_elimination(float**& A, float**& b, size_t n) {
    for (size_t k = 0; k < n-1; ++k) {
        size_t max_pivot = k;

        for (size_t i = k+1; i < n; ++i)
            if (fabs(A[i][k]) > fabs(A[max_pivot][k]))
                max_pivot = i;

        if (max_pivot != k) {
            fprintf(stderr, "Swapping R%zu with R%zu\n", k+1, max_pivot+1);
            swap_rows(A, k, max_pivot);
            swap_rows(b, k, max_pivot);
        }

        float pivot = A[k][k];
        
        if (pivot == 0) {
            printf("Matrix is singular\n");
            return false;
        }

        for (size_t i = k+1; i < n; ++i) {
            float m = A[i][k] / pivot;
            if (m == 0)
                continue;
            printf("R%zu - %lf*R%zu\n", i+1, m, k+1);
            for (size_t j = 0; j < n; ++j)
                A[i][j] -= m * A[k][j];
            b[i][0] -= m * b[k][0];
        }
    }

    return true;
}

float** back_substitution(float **A, float **b, size_t n) {
    float **X = new float*[n];
    for (size_t i = 0; i < n; ++i) {
        X[i] = new float[1];
        X[i][0] = 0;
    }

    X[n-1][0] = b[n-1][0] / A[n-1][n-1];
    for (ssize_t i = n-2; i >= 0; --i) {
        float sum = 0;
        for (size_t j = i+1; j < n; ++j)
            sum += A[i][j] * X[j][0];
        X[i][0] = (b[i][0] - sum) / A[i][i];
    }

    return X;
}

int main() {
    // Matricola Tuillier 5441316
    int d1 = 1, d0 = 6;
    int n = 10*(d1 + 1) + d0;

    float** A1 = new float*[4];
    float** A2 = new float*[4];
    float** P = new float*[10];
    float** T = new float*[n];

    // Popolare A1
    float initA1[4][4] = {
        {3, 1, -1, 0},
        {0, 7, -3, 0},
        {0, -3, 9, -2},
        {0, 0, 4, -10}
    };

    for (size_t i = 0; i < 4; ++i) {
        A1[i] = new float[4];
        for (size_t j = 0; j < 4; ++j)
            A1[i][j] = initA1[i][j];
    }

    // Popolare A2
    float initA2[4][4] = {
        {2, 4, -2, 0},
        {1, 3, 0, 1},
        {3, -1, 1, 2},
        {0, -1, 2, 1}
    };

    for (size_t i = 0; i < 4; ++i) {
        A2[i] = new float[4];
        for (size_t j = 0; j < 4; ++j)
            A2[i][j] = initA2[i][j];
    }

    // Popolare P
    for(size_t i = 0; i < 10; ++i) {
        P[i] = new float[10];
        for(size_t j = 0; j < 10; ++j)
            P[i][j] = tgamma(i + j + 1) / (tgamma(i + 1) * tgamma(j + 1)); //tgamma(n) = (n-1)!
    }

    // Popolare T
    for (ssize_t i = 0; i < n; ++i) {
        T[i] = new float[n];
        for (ssize_t j = 0; j < n; ++j) {
            if (i == j)
                T[i][j] = 2;
            else if (abs(i - j) == 1)
                T[i][j] = -1;
            else
                T[i][j] = 0;
        }
    }

    // Stampa le A
    printf("A1:\n");
    print_matrix(A1, 4, 4);
    printf("A2:\n");
    print_matrix(A2, 4, 4);
    printf("P:\n");
    print_matrix(P, 10, 10);
    printf("T:\n");
    print_matrix(T, n, n);
    printf("\n\n");

    // Poplare le b
    float **bA1 = compute_b(A1, 4);
    float **bA2 = compute_b(A2, 4);
    float **bP = compute_b(P, 10);
    float **bT = compute_b(T, n);

    // Stampa le b
    printf("bA1:\n");
    print_matrix(bA1, 4, 1);
    printf("bA2:\n");
    print_matrix(bA2, 4, 1);
    printf("bP:\n");
    print_matrix(bP, 10, 1);
    printf("bT:\n");
    print_matrix(bT, n, 1);
    printf("\n\n");

    // Popolare le X
    float **XA1 = back_substitution(A1, bA1, 4);
    float **XA2 = back_substitution(A2, bA2, 4);
    float **XP = back_substitution(P, bP, 10);
    float **XT = back_substitution(T, bT, n);

    // Stampa le X
    printf("XA1:\n");
    print_matrix(XA1, 4, 1);
    printf("XA2:\n");
    print_matrix(XA2, 4, 1);
    printf("XP:\n");
    print_matrix(XP, 10, 1);
    printf("XT:\n");
    print_matrix(XT, n, 1);
    printf("\n\n");

    return 0;
}
