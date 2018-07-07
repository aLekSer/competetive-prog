#include <vector>
#include <set>
#include <iostream>

using namespace std;
// we should iterate and wait when all v[i] == v[i-1]
long long select(vector<int> &v, int k) {
	int min = 6000;
	int minPos = 0;
	if(v[minPos] < min) {
		min = v[minPos];
	}
	set<int> used;
	set<int> initial;
	//set<int> mid;
	long long mid = 0;
	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < v.size(); i++) {
			if(used.find(i) != used.end())
				continue;
			if(v[i] < min) {
				min = v[i];
				minPos = i;
			}
		}
		used.insert(minPos);
		mid += 1 << minPos;
		//cerr << minPos << " " <<"s";
		v[minPos] ++;
		min = 6000;
	}
	//cerr <<  endl;
	return mid;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		long long r;
		cin >> n >> k >> r;
		vector<string> attr(n);
		vector<int> v(n, 0);
		long long mid ;
		long long init = 0;
		for (int j = 0; j < k; j++)
		{
			init += 1 << j;
		}
		for (int j = 0; j < n; j ++) {
			cin >> attr[j];
		}
		long long stop;
		for (int l = 0; l < n * n; l++ ) {
			 mid = select(v, k);
			 if (l != 0 && mid == init) {
				 //cerr << l;
				 stop = l;
				 break;
			 }
		}
		//cerr << "stop " << stop << " " << ((r % stop) - 1);
		long long d = ((r % stop) - 1);
		if (((r % stop) - 1) <= 0) {
			d += stop;
		}

		vector<int> v2(n, 0);
		for (long long it = 0/*(r / stop) * stop*/; it <  d ; it++) {
			 //cerr << "Iter "<< it;
			 mid = select(v2, k);
		}
		set<int> used;
		int min = 6000;
		int minPos = 0;
		if(v2[minPos] < min) {
			min = v2[minPos];
		}
		for (int j = 0; j < n; j ++) {
			//cerr << " n " << v2[j];
		}
		
		cout << "Case #" << i+1<<  ":" ;
		for (int j = 0; j < k; j++)
		{
			for (int iter = 0; iter < v2.size(); iter++) {
				if(used.find(iter) != used.end())
					continue;
				if(v2[iter] < min) {
					min = v2[iter];
					minPos = iter;
				}
			}
			used.insert(minPos);
			cout << attr[minPos] << " ";
			v2[minPos] ++;
			min = 6000;
		}
		cout << endl;
	}
	return 0;
}
