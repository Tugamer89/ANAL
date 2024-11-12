#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double infiteNorm(float** matrix, int size) {
    double maxRow = 0.0;

    for(size_t i = 0; i < size; ++i) {
        double sum = 0.0;
        for(size_t j = 0; j < size; ++j)
            sum += abs(matrix[i][j]);
        maxRow = max(sum, maxRow);
    }

    return maxRow;
}

float** compute_b(float **A, size_t n) {
    float **b = new float*[n];
    for (size_t i = 0; i < n; ++i) {
        b[i] = new float[1];
        b[i][0] = 0;

        for (size_t j = 0; j < n; ++j)
            b[i][0] += A[i][j];
    }

    return b;
}

float** compute_pertb(float **b, size_t n)
{
    float **pert_b = new float*[n];
    double infNorm = infiteNorm(b, n);
    for (size_t i = 0; i < n; ++i) {
        b[i][0] = infNorm * (pow(-1, i+1)*0,01);
    }

    return pert_b;
}

int main() {

    float** A1 = new float*[4];
    
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
    
    float** bA1 = compute_b(A1, 4);
    float** pert_bA1 = compute_pertb(bA1, 4);

    return 0;
}
