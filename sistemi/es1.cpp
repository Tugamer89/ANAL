#include "utils.h"

using namespace std;

int main() {
    LinearSystem A1, A2, P, T;
    initializeMatrixes(A1, A2, P, T);

    // Stampa le A
    cout << "A1:\n";
    A1.A.print();
    cout << "A2:\n";
    A2.A.print();
    cout << "P:\n";
    P.A.print();
    cout << "T:\n";
    T.A.print();
    cout << endl;

    cout << "Infite Norm of A1: " << A1.A.infiniteNorm() << endl;
    cout << "Infite Norm of A2: " << A2.A.infiniteNorm() << endl;
    cout << "Infite Norm of P:  " << P.A.infiniteNorm() << endl;
    cout << "Infite Norm of T:  " << T.A.infiniteNorm() << endl;
    
    return 0;
}