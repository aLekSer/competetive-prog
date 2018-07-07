#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
// we should iterate and wait when all v[i] == v[i-1]
		vector<string> attr;
		vector<pair<int, int>> v3;
long long select(vector<int> &v, int k) {
	int min = 6000;
	int minPos = 0;
	sort(v3.begin(), v3.end());
	
	for (int j = 0; j < k; j++)
	{
		
		//mid += 1 << minPos;
	//cerr << attr[v3[j].second] << " " <<" s ";
		v3[j].first ++;
	}
//cerr << endl;
/*
	for (int i = 1; i < v.size() ; i ++) {
		if (v[i] != v[i-1])
			return 0;
	}
	*/
	return -1;
	//cerr <<  endl;
	//return mid;
}
int main() {
	int t;
	/** /
		string s = "1 50 50 100000\n";
		for (int i = 0 ; i < 50 ; i ++) {
			
			s +=  to_string(i) + " ";
		}
		stringstream in(s);
		/*/
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		v3 = 
		vector<pair<int, int>> ();
		long long r;
		cin >> n >> k >> r;
		vector<int> v(n, 0);
		unsigned long long mid  = 0;
		long long init = 0;
		attr = vector<string> (n);
		for (int j = 0; j < k; j++)
		{
			init += 1 << j;
		}
		for (int j = 0; j < n; j ++) {
			cin >> attr[j];
			v3.push_back(make_pair(0, j));
		}
		for (int j = 0; j < n; j ++) {
			//cerr << v3[j].first << " d " << v3[j].second << endl;
//v3.push_back(make_pair(0, j));
		}
		long long stop;
		/*
		for (int l = 0; l < n * n; l++ ) {
			 mid = select(v, k);
			 if (l != 0 && mid ==  -1 ) {// init) {
				 //cerr << l;
				 stop = l;
				 break;
			 }
		}
		*/
		vector<int> v2(n, 0);
		stop = k * n;
		//cerr << "stop " << stop << " " << ((r % stop) - 1);
		/*
		*/
		long long d = ((r % stop) );
		if (((r % stop) ) <= 0) {
			d += stop;
		}

		for (long long it = 0/*(r / stop) * stop*/; it <  d ; it++) {
			 //cerr << "Iter "<< it;
			 /*mid =*/ select(v2, k);
		}
		
		cout << "Case #" << i+1<<  ": " ;
		//char s2 [40];
		//cerr << mid << endl;
		//sprintf(s2, "%x", mid);
		//cerr << s2 << endl;
			for (int iter = 0; iter < k; iter++) {
                    mid =  mid | (1ULL << v3[iter].second);
					//cerr << v3[iter].second << " n: " << iter << " " ;
					//cout << attr[v3[iter].second] << " ";
			}

                 for (int iter = 0; iter < 55; iter++) {
                   if (mid & (1ULL << iter))
                     cout << attr[iter] << " ";
				 }

			//cerr << " " << mid << " ";
		cout << endl;
	}
	return 0;
}
