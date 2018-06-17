#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int T ;
	cin >> T;
	vector<int > v(9, 0);
	vector<bool > a(9, false);
	vector<string> ps;
	string number = "2134";
	sort(number.begin(),number.end());



	/*
	do cout << "Permutation: " << number << endl;

	while (next_permutation(number.begin(),number.end()));
	*/
	for (int i = 0 ; i < T; i++) {
int total = 0;
	    int  k, n;
	    cin >> n>> k;
	vector<bool > a(9, false);
	vector<int> emp (0);
	    for (int j = 0 ; j < n ; j ++) {
	        cin >> v[j];
	       a[v[j]] = true;
		   if (v[j] == 0) {
			   emp.push_back(j);
		   }
	    }
	    string number;
	    for (int j = 1 ; j < n + 1; j ++) {
	        if ( 
	       !a[j] ) {
	           number += std::to_string(j);
	       }
}
	do 
	{
		//cout << "Permutation: " << number << endl;
			char s [2];
			s[1] = '\0';
		for (int l = 0; l < number.length(); l++) {
			//string s = number[l];
			//cout << s;
			s[0]  = number[l];
			v[emp[l]] = atoi(s);  // std::stoi(s);
		}
		int count = 0;
	    for (int j = 1 ; j < n ; j ++) {
			if (v[j - 1 ] < v[j])
			count ++;
	       }
		if (count == k)
		total ++;
	} while (next_permutation(number.begin(),number.end()));
	    //int res = 0;
	    cout << total << endl;
	}
	return 0;
}

