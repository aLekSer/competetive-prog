#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

//PDELIV
typedef  long long ll;
using namespace std;
int main()
{
	int n = 0, m;
	cin >> n ;
    
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i] ;
        v[i] = v[i] - (v[i] % 2 ^ 0x1) ;
	}

	for (int i = 0; i < n; i++) {
        
        cout << v[i] << " " ;
	} 
}

