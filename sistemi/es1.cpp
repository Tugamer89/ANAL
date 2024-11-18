#include "utils.h"

using namespace std;

int main() {
    LinearSystem A1, A2, P, T;
    initializeMatrixes(A1, A2, P, T);

    cout << "Infite Norm of A1: " << A1.A.infiniteNorm() << endl;
    cout << "Infite Norm of A2: " << A2.A.infiniteNorm() << endl;
    cout << "Infite Norm of P:  " << P.A.infiniteNorm() << endl;
    cout << "Infite Norm of T:  " << T.A.infiniteNorm() << endl;
    
    return 0;
}