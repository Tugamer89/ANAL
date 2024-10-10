#include <iostream>
#include <math.h>

using namespace std;

double function(double x, unsigned int N) {
    double res = 0;

    for (unsigned int n = 0; n <= N; ++n)
        res += pow(x, n) / tgamma(n+1);
    return res;
}

void printErr(double f, double fN, double x) {
    double errAss = fabs(fN - f);
    double errRel = fabs(errAss / f);

    cout << "f(" << x << ")  = " << f << "\t\terrAss = " << errAss << endl;
    cout << "fN(" << x << ") = " << fN << " \t\terrRel = " << errRel << endl;
    cout << endl;
}

int main() {
    double points[] = {0.5, 30, -0.5, -30};
    unsigned int Ns[] = {3, 10, 50, 100, 150};

    for (double x : points) {
        for (unsigned int N : Ns) {
            cout << "N: " << N << endl;
            double f = exp(x);
            double fN = function(x, N);
        
            cout << "ALG1" << endl;
            printErr(f, fN, x);

            if (x < 0) {
                f = 1/exp(-x);
                fN = 1/function(-x, N);
            
                cout << "ALG2" << endl;
                printErr(f, fN, x);
            }

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
