#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int d = 1;
 
    const float fOne = 1.0;
    const double dOne = 1.0;

    while (fOne + powf(2, -d) > 1.0)
        ++d;
    float fEps = powf(2, -(--d));

    cout << "FLOAT" << endl;
    cout << "eps = " << fEps << endl;
    cout << "d = " << d << endl;
    cout << endl;

    d = 1;
    while (dOne + pow(2, -d) > 1.0)
        ++d;
    double dEps = pow(2, -(--d));

    cout << "DOUBLE" << endl;
    cout << "eps = " << dEps << endl;
    cout << "d = " << d << endl;
    cout << endl;

    return 0;
}
