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
