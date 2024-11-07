#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


    void swap_rows(float **matrix, size_t a, size_t b) {
    float *tmp = matrix[a];
    matrix[a] = matrix[b];
    matrix[b] = tmp;
}

int main() {
    int d1 = 1, d0 = 6; //ultime cifre matricola Tuillier S5441316
    int n = 10*(d1 + 1) + d0;
    float** A1 = new float*[4];
    float** A2 = new float*[4];

    //popolare A1
    float A1arr[4][4] = {
        {3, 1, -1, 0}, {0, 7, -3, 0}, {0, -3, 9, -2}, {0, 0, 4, -10}
    };

    for (int i = 0; i < 4; ++i) {
        A1[i] = new float[4];
        for (int j = 0; j < 4; ++j)
            A1[i][j] = A1arr[i][j];
    }

    //popolare A2
    float A2arr[4][4] = {
        {2, 4, -2, 0}, {1, 3, 0, 1}, {3, -1, 1, 2}, {0, -1, 2, 1}
    };

    for (int i = 0; i < 4; ++i) {
        A2[i] = new float[4];
        for (int j = 0; j < 4; ++j)
            A2[i][j] = A2arr[i][j];
    }

    float** P = new float*[10];
    float** T = new float*[n];

    //popolare P
    for(int i = 0; i < 10; ++i)
    {
        P[i] = new float[10];
        for(int j = 0; j < 10; ++j)
            P[i][j] = tgamma(i + j - 1) / (tgamma(i) * tgamma(j)); //tgamma(n) = (n-1)!
    }

    //popolare T
    for (int i = 0; i < n; ++i)
    {
        T[i] = new float[n];
        for (int j = 0; j < n; ++j)
        {
            if(i == j)
                T[i][j] = 2;
            else if(abs(i - j) == 1)
                T[i][j] = -1;
            else
                T[i][j] = 0;
        }
    }

    float **A, **b, **X;
    size_t n, dim_A, dim_b;

    // Ask for size and matrix
    printf("Enter size of matrix (n): ");
    scanf("%zu", &n);
    create_matrix(&A, n, n);
    create_matrix(&b, n, 1);
    create_matrix(&X, n, 1);
    
    printf("\nEnter matrix A:\n");
    popolate_matrix(A, n, n);
    printf("\nEnter matrix b:\n");
    popolate_matrix(b, n, 1);

    printf("\nSteps:\n");

    // Gaussian elimination
    for (size_t k = 0; k < n-1; ++k) {
        size_t max_pivot = k;

        for (size_t i = k+1; i < n; ++i)
            if (fabs(A[i][k]) > fabs(A[max_pivot][k]))
                max_pivot = i;

        if (max_pivot != k) {
            printf("Swapping R%zu with R%zu\n", k+1, max_pivot+1);
            swap_rows(A, k, max_pivot);
            swap_rows(b, k, max_pivot);
        }

        float pivot = A[k][k];
        
        if (pivot == 0) {
            printf("Matrix is singular\n");
            return 1;
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

    printf("\n");

    // Back subsitution
    X[n-1][0] = b[n-1][0] / A[n-1][n-1];
    for (long long i = n-2; i >= 0; --i) {
        float sum = 0;
        for (size_t j = i+1; j < n; ++j)
            sum += A[i][j] * X[j][0];
        X[i][0] = (b[i][0] - sum) / A[i][i];
    }

    // Print A & b reduced
    printf("A:\n");
    print_matrix(A, n, n);

    printf("b:\n");
    print_matrix(b, n, 1);

    printf("X:\n");
    print_matrix(X, n, 1);

    return 0;
}
