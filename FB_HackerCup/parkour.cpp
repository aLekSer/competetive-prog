#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;
// we should iterate and wait when all v[i] == v[i-1]

// run command:
// cat ~/Downloads/tourist.txt |  ./a.out - > ./Output.txt

vector<string> attr;
vector<pair<int, int>> v3;
bool pairCompare(const std::pair<int, int>& f, const std::pair<int, int>& s) {
	if (f.first == s.first) {
		return f.second < s.second;
	}
  return f.first < s.first;

}
long long select(vector<int> &v, int k) {
	int min = 6000;
	int minPos = 0;
	sort(v3.begin(), v3.end(), pairCompare);
	
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
// Hi = (W * Hi-2 + X * Hi-1 + Y) % Z (for i=3..N) 

typedef long long ll;
void ch(int W, int X, int  Y, int Z, vector<ll> & h) {
	for (int i = 2; i < h.size(); i ++) {
		h[i] = ((W * h[i-2]  ) % Z + (X * h[i-1]) % Z   + Y % Z) %Z ;
	}
	return;
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
		int n, m;
		cin >> n >> m;
		long long r;
		//H1, H2, W, X, Y, and Z. Then, M lines follow. The ith of these lines contains the space-separated integers Ai, Bi, Ui, and Di. 

		cout << "Case #" << i+1<<  ": " ;
		vector<int> v(n, 0);
		unsigned long long mid  = 0;
		long long init = 0;
		int w, x,   y,  z;
		vector<ll> h(n);
		cin >>  h[0] >> h[1] >> w >> x >> y >> z;
		ch(w, x, y, z, h);
		vector<double> hd(n);

		for (int j = 0; j < n; j++) {
							   cerr << h[j] << " h ";
							   hd[j] = h[j];

		}
							   cerr << endl; 

		vector<int> a(m), b(m), u(m) , d(m);
		
		for (int j = 0; j < m; j++)
		{
			cin >> a[j] >> b[j] >> u[j] >> d[j];
		}
		vector<double> change(n,0);
		vector<double> dchange(n, 0);
		vector<double> change2(n,0);
		vector<double> dchange2(n, 0);
		int diff = 0;
		for (int j = 0; j < m; j++)
		{
			if (b[j] > a[j]) {
				for (int k = a[j] ; k < b[j] ; k ++)
				{
					cerr << k  << "Up " << endl;
					if ( hd[k] > hd[k-1]) 
					   { 
						   double u1 =  hd[k] - hd[k-1];
						   if (u1 > u[j]) {
								hd[k] = hd[k-1] - diff;
							   change[k] = max(u1 - u[j], change[k]);
								if ( k == a[j]) {
								   hd[k-1] = (hd[k] - hd[k-1]) / 2 + hd[k-1];
								   diff = (hd[k] - hd[k-1]);
								}
							   hd[k] = hd[k-1] + u[j];
							   cerr << change[k] << " change " << endl; 
						   }

					   }
					 else if ( hd[k] < hd[k-1]) 
					   {
						   double d1 =  - hd[k] + hd[k-1];
						   if (d1 > d[j]) {
							   dchange[k] = min(- (d1 - d[j]), dchange[k]);
							   if ( k == a[j]) { 
						  			 hd[k-1] = (hd[k] - hd[k-1]) / 2 + hd[k-1];
								   diff = (hd[k] - hd[k-1]);
							   }
							   hd[k] = hd[k-1] - d[j];
							   cerr << dchange[k] << " d	change " << endl; 
						   }

					   }


				}
			

			} else {
				for (int k = a[j] - 1; k > b[j] - 1  ; k --)
				{
					cerr << k  << "Down " << endl;
					if ( hd[k] < hd[k-1]) 
					   {
						   double u1 =  hd[k-1] - hd[k];
						   if (u1 > u[j]) {
							 hd[k-1]   = hd[k]  + u[j];
							   change2[k] = max(u1 - u[j], change2[k]);
							   cerr << change2[k] << " change " << endl; 
						   }

					   }
					if ( hd[k] > hd[k-1]) 
					   {
						   double d1 =  - hd[k-1] + hd[k];
						   if (d1 > d[j]) {
							 hd[k-1]   = hd[k]  - d[j];
							   dchange2[k] = min(- (d1 - d[j]), dchange2[k]);
							   cerr << dchange2[k] << " d2	change " << endl; 
						   }

					   }

					
				}
			}
		}
		cerr <<  "Investigate " << endl;

		for (int i = 0; i < n ; i++) {
			cerr << hd[i] - h[i]<< " ";
		}
		cerr << endl;
		ll max = 0;
		for (int i = 0; i < n ; i++) {
							   cerr << change[i] << " " ;
							   if (abs(change[i]) > max ) 
							   	max  = abs(change[i]);

		}
		cerr << endl << "d	change " << endl;
		for (int i = 0; i < n ; i++) {
							   cerr << dchange[i] << " " ; 
							   if (abs(dchange[i]) > max ) 
							   	max  = abs(dchange[i]);
		}
		cerr << endl; 
		for (int i = 0; i < n ; i++) {
							   cerr << change2[i] << " " ;
							   if (abs(change2[i]) > max ) 
							   	max  = abs(change2[i]);

		}
		cerr << endl << "d	change " << endl;
		for (int i = 0; i < n ; i++) {
							   cerr << dchange2[i] << " " ; 
							   if (abs(dchange2[i]) > max ) 
							   	max  = abs(dchange2[i]);
		}
		cerr << endl;
		cerr << max << endl; 
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
		//cerr << "stop " << stop << " " << ((r % stop) - 1);
		/*
		*/

		//char s2 [40];
		//cerr << mid << endl;
		//sprintf(s2, "%x", mid);
		//cerr << s2 << endl;
			//cerr << " " << mid << " ";
		cout << endl;
	}
	return 0;
}
