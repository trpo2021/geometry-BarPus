#include <cstring>
#include <iostream>
#include <regex>
using namespace std;

void Circle(string Figure)
{
    if ((strstr(Figure.c_str(), "circle "))
        || (strstr(
                Figure.c_str(),
                "circle("))) { //проверяем правильности фигуры "окружность"

        cmatch result;
        regex regular(
                "([\\w\\s]+)"
                "(\\()"
                "([\\s]*)"
                "([0-9]+)"
                "([\\s]*)" //проверяем входящую строку
                "([0-9]+)"
                "([\\s]*)"
                "(\\,)"
                "([\\s]*)"
                "([0-9]*[.]?[0-9]+)"
                "([\\s]*)"
                "(\\))");

        if (regex_match(Figure.c_str(), result, regular)) {
            cout << "true" << endl;

            //		for (int i=0; i<result.size(); i++) {
            //			cout <<result[i++] <<endl;         -вывод каждого
            //участка
            //			}
        }

        // string R=result.str(10);
        // cout <<R;

        else
            cout << "error" << endl;
    } else
        cout << "error" << endl;
}

int main()
{
    string Figure; //принимаем строку с фигурой
    getline(cin, Figure);
    Circle(Figure);
    return 0;
}
