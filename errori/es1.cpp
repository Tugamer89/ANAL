#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int d0 = 3;
    int d1 = 2;

    double b = (d1 + 1) * pow(10, 20);
    double c = -b;

    for (int i = 0; i <= 6; ++i) {
        double a = (d0 + 1) * pow(10, i);
    
        double r1 = (a + b) + c;
        double r2 = a + (b + c);

        cout << "i = " << i << endl;
        cout << "r1 = " << r1 << endl;
        cout << "r2 = " << r2 << endl << endl;
    }

    return 0;
}
