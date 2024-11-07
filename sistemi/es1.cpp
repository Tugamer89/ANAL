#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double infiteNorm(const vector<vector<double>>& matrix) {
    double maxRow = 0.0;

    for(size_t i = 0; i < matrix.size(); ++i) {
        double sum = 0.0;
        for(size_t j = 0; j < matrix[i].size(); ++j)
            sum += abs(matrix[i][j]);
        maxRow = max(sum, maxRow);
    }

    return maxRow;
}

int main() {
    // Matricola Tuillier 5441316
    int d1 = 1, d0 = 6;
    int n = 10*(d1 + 1) + d0;

    vector<vector<double>> A1 = {
        {3, 1, -1, 0},
        {0, 7, -3, 0},
        {0, -3, 9, -2},
        {0, 0, 4, -10}
    };

    vector<vector<double>> A2 = {
        {2, 4, -2, 0},
        {1, 3, 0, 1},
        {3, -1, 1, 2},
        {0, -1, 2, 1}
    };
    
    vector<vector<double>> P, T;

    // Popolare P
    for(size_t i = 0; i < 10; ++i) {
        P.push_back(vector<double>(10));
        for(size_t j = 0; j < 10; ++j)
            P[i][j] = tgamma(i + j + 1) / (tgamma(i + 1) * tgamma(j + 1)); // tgamma(n) = (n-1)!
    }

    // Popolare T
    for (ssize_t i = 0; i < n; ++i) {
        T.push_back(vector<double>(n));
        for (ssize_t j = 0; j < n; ++j) {
            if (i == j)
                T[i][j] = 2;
            else if (abs(i - j) == 1)
                T[i][j] = -1;
            else
                T[i][j] = 0;
        }
    }
    

    cout << "Infite Norm of A1: " << infiteNorm(A1) << endl;
    cout << "Infite Norm of A2: " << infiteNorm(A2) << endl;
    cout << "Infite Norm of P:  " << infiteNorm(P) << endl;
    cout << "Infite Norm of T:  " << infiteNorm(T) << endl;
    
    return 0;
}