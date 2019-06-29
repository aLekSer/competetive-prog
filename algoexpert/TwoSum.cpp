#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	unordered_map<int, int> s;
	vector<int> v;
	for (int i : array) {
		if(s.find(i) != s.end()) {
				s[i] ++ ;
			} else {
				s[i] = 1;
			}
	}
	for (int i : array) {
		if(s.find(targetSum - i) != s.end()) {
				if ((targetSum - i ) == i && s[i] < 2 ) 
				{
					continue;
				}
			
					v.push_back(targetSum - i);
					v.push_back(i);
					break;
			}
	}
	sort(v.begin(), v.end());
	if (v.size() > 1) {
		//cout << v[0] << " " << v[1];
	}
	return v;
  // Write your code here.
}
