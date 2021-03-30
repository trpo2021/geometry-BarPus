#include <geometry/CircleRadius.h>
#include <geometry/isGoodCircle.h>
#include <geometry/PerimeterArea.h>
#include <iostream>
#include <string>
#include <regex>
using namespace std;


int main () {
	float R;
	string Figure;  
	cout <<"Input Figure" <<endl;                                                             
	getline(cin, Figure);
	if (isGoodCircle(Figure)) 
	{
		R=CircleRadius(Figure);
		Perimeter(R);
		Area(R);
	}
	else cout<<"the Figure is set incorrectly";
	return 0;
}
	
