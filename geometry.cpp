#include <cstring>
#include <iostream>
#include <regex>
using namespace std;

float CircleRadius(string Figure)
{
    float R;
    if ((strstr(Figure.c_str(), "circle "))
        || (strstr(Figure.c_str(), "circle("))) {
        cmatch result;
        regex regular(
                "([\\w\\s]+)"
                "(\\()"
                "([\\s]*)"
                "([0-9]+)"
                "([\\s]*)"
                "([0-9]+)"
                "([\\s]*)"
                "(\\,)"
                "([\\s]*)"
                "([0-9]*[.]?[0-9]+)"
                "([\\s]*)"
                "(\\))");
        if (regex_match(Figure.c_str(), result, regular)) {
            R = stof(result.str(10));
        }
    }
    return R;
}

bool isGoodCircle(string Figure)
{
    if ((strstr(Figure.c_str(), "circle "))
        || (strstr(Figure.c_str(), "circle("))) {
        cmatch result;
        regex regular(
                "([\\w\\s]+)"
                "(\\()"
                "([\\s]*)"
                "([0-9]+)"
                "([\\s]*)"
                "([0-9]+)"
                "([\\s]*)"
                "(\\,)"
                "([\\s]*)"
                "([0-9]*[.]?[0-9]+)"
                "([\\s]*)"
                "(\\))");
        if (regex_match(Figure.c_str(), result, regular)) {
            return true;
        } else
            return false;
    } else
        return false;
}

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
