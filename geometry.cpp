#include <iostream>
#include <cstring>
#include <regex>
using namespace std;

int main () {
	string Figure;                                                                //��������� ������ � ������� 
	getline(cin, Figure);
	
if((strstr(Figure.c_str(),"circle ")) || (strstr(Figure.c_str(),"circle("))) {   //��������� ������������ ������ "����������"
                                                                           
	cmatch result;
	regex regular ("([\\w\\s]+)"
					"(\\()"  
					"([\\s]*)"    
					"([\\d]*)"
					"([\\s]*)"                                                     //��������� �������� ������
					"([\\d]*)"
					"([\\s]*)"  
					"(\\,)"
					"([\\s]*)"  
					"([0-9]*[.]?[0-9]+)"
					"([\\s]*)"  
					"(\\))"  );  
	
	if (regex_match(Figure.c_str(), result, regular)) {
		cout <<"true" <<endl;
//		for (int i=0; i<result.size(); i++) {
//			cout <<result[i++] <<endl;         -����� ������� �������
//			}	
	}

//string R=result.str(10);
//cout <<R; 
	
}
else cout <<"error" <<endl;
}
	
