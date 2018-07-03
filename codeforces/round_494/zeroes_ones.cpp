#include <iostream>
#include <string>
#include "stdlib.h"
#include <stdio.h>
using namespace std;

int main() {
// your code goes here
	int x, a, b;
	cin >> a >> b >> x;
	string s = "";
	int b1;
		int totalA = 0;
		int totalB = 0;
	if (a > b) {
		totalA++;
		s += "0";
		b1 = 0;
	}  else  {
		totalB++;
		s += "1";
		b1 = 1;
	}
	if (a == 0 && b == 0) {
		cout << endl;
		return 0;
	}
	if (x == 0 && b == 0) {
		
	}
	string c[2] = {"0", "1"};
	for (int i = 0; i < x; i ++) {
		b1 = ! b1;
			if (b1 == 0) {
				totalA ++;
			}
			if (b1 == 1) {
				totalB ++;
			}
			char st [100];
			s += c[b1];
			//cerr << s << endl;
    
	}
		int j = 0;
		/*
		while(s[j] != "0") {
			j ++;
		} 
		
		int j = 0;
		while(s[j] != "1") {
			j ++;
		} */
		//cerr << s << endl;
		string z = "";
		for (int i = totalA; i < a ; i++) {
			z += "0";
		}
		string e = "";
		for (int i = totalB; i < b ; i++) {
			e += "1";
		}
		//cerr << e <<endl;
		string l = s.substr(0, s.find("0")) ;
		string r = s.substr(s.find("0"), s.length());
		s = l + z + r;
		 l = s.substr(0, s.find("1")) ;
		 r = s.substr(s.find("1"), s.length());
		s = l+ e + r;
		cout << s << endl;
	return 0;
}

