#include <iostream>
#include "lib/include/lib.h"
#include "lib/src/lib.cpp"
using namespace std;

int main() {

    Node a, b;

    cout << "Node a \t";
    a.display();
    cout<< "Node b \t";
    b.display();

    a.updateValue(1,1);
    b.updateValue(4,5);

    cout << "Node a \t";
    a.display();
    cout<< "Node b \t";
    b.display();

    cout << "odleglosc to:" << pointsDistance(a,b);


    return 0;
}