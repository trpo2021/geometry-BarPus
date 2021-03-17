#include "CircleRadius.h"
#include "PerimeterArea.h"
#include "isGoodCircle.h"
#include <cstring>
#include <iostream>
#include <regex>
using namespace std;

int main()
{
    float R;
    string Figure;
    cout << "Input Figure" << endl;
    getline(cin, Figure);
    if (isGoodCircle(Figure)) {
        R = CircleRadius(Figure);
        Perimeter(R);
        Area(R);
    } else
        cout << "the Figure is set incorrectly";
    return 0;
}
