#include <cstring>
#include <iostream>
#include <regex>
using namespace std;

float Perimeter(float R)
{
    float P, pi = 3.14;
    P = 2 * pi * R;
    cout << "Perimeter =" << P << endl;
    return P;
}

float Area(float R)
{
    float S, pi = 3.14;
    S = pi * R * R;
    cout << "Area =" << S << endl;
    return S;
}
