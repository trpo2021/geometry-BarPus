#include "PerimeterArea.h"
#include <string>
#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

float Perimeter(float R)
{
    float P;
    P = 2 * M_PI * R;
    return P;
}

float Area(float R)
{
    float S;
    S = M_PI * R * R;
    return S;
}
