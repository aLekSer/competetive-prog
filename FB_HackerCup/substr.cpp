#include <vector>
#include <iostream>
#include <string>

using namespace std;

//contains() function
//

bool algo(string a, string b) {
	int i = 0, j = 0;
	while ( true ) {
		if (i == a.length()) 
			return true;
		if (j == b.length() )
			return false;
		if (a[i] == b[j] ) 
		{
			//cerr<<"a"<<a[i]<<endl;
			//cerr<<"b"<<b[j]<<endl;
			i++; j ++;
			//cerr << i << endl; 
			continue;

		}
		if (i == 0) {
			j++;
			continue;
		}
		i = 0;
	}
	return false;
}

string getB(string a) {
	int found = false;
	for (int i = 1; i < a.length(); i++) {
		if (a[0] == a[i]) {
			found = true;
			for (int j = 1; j < a.length() - i; j ++) {
				if (a[j] != a[i + j])
					return a.substr(0, i) + a;
			}
		}
	}
	return "";

}
int main() {
	cout << getB("ABACUS") << endl << " a " << endl;
	cout << algo("ABACUS", "ABABACUS") << "false";
	cout << getB("FACEBOOK") << endl << " b " << endl;
	cout << getB("XYZXZYX") << endl << " c  " << endl;
	cout <<algo("XYZXZYX", "XYZXYZXZYX") << endl << " c  " << endl;
	cout << getB("FBFBF") << endl << " d " << endl; 
	cout << algo("ABACUS", "ASUCABABACUSA") << "false";
	cout << algo("FLFE", "FLFLFE")<< "false";
	cout << algo("XYZXZYX", "XZYXYZXYZXZYXYZXYZYX")<< "false" << endl;
	return 0;
}
