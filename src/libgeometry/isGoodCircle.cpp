#include "isGoodCircle.h"
#include <string>
#include <iostream>
#include <regex>
using namespace std;

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
