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

    // Stampa le b
    cout << "bA1:\n";
    A1.b.print();
    cout << "bA2:\n";
    A2.b.print();
    cout << "bP:\n";
    P.b.print();
    cout << "bT:\n";
    T.b.print();
    cout << endl;

    // Eliminazione Gaussiana + Back Substitution con pivoting parziale
    A1.computeX();
    A2.computeX();
    P.computeX();
    T.computeX();

    // Stampa le X
    cout << "XA1:\n";
    A1.X.print();
    cout << "XA2:\n";
    A2.X.print();
    cout << "XP:\n";
    P.X.print();
    cout << "XT:\n";
    T.X.print();
    cout << endl;

    return 0;
}
