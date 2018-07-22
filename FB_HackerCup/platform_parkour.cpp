#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200100;
const int MAX_M = 32;

double H[MAX_N];
long long N,M,W,X,Y,Z;
long long A[MAX_M], B[MAX_M];
double U[MAX_M], D[MAX_M];
double U_P[MAX_N], D_P[MAX_N];

void read()
{
	cin >> N >> M;
	cin >> H[1] >> H[2] >> W >> X >> Y >> Z;
	for (int i=0; i<M; ++i)
	{
		cin>>A[i]>>B[i]>>U[i]>>D[i];
	}
}

void prepare()
{
	for (int i=3; i<=N; ++i)
	{
		long long p1 = H[i-2];
		long long p2 = H[i-1];
		H[i] = (W*p1 + X*p2 + Y)%Z;
	}
	for (int i=0; i<M; ++i)
	{
		if (A[i] > B[i])
		{
			swap(A[i], B[i]);
			swap(U[i], D[i]);
		}
	}
	for (int i=1; i<=N; ++i)
	{
		U_P[i] = 1e9;;
		D_P[i] = 1e9;
		for (int j=0; j<M; ++j)
		{
			if (i >= A[j] and i < B[j])
			{
				U_P[i] = min(U_P[i], U[j]);
				D_P[i] = min(D_P[i], D[j]);
			}
		}
	}
}

bool check_equal()
{
	for (int i=2; i<=N; ++i)
	{
		if (H[i] != H[i-1])
			return false;
	}
	return true;
}

bool possible_show(double time)
{
	double jump_high = H[1]+U_P[1]+time;
	double jump_down = H[1]-D_P[1]-time;
	for (int i=2; i<=N; ++i)
	{
		double previous_jump_high = jump_high;
		double previous_jump_down = jump_down;
		if (H[i]-time > jump_high or H[i]+time < jump_down)
			return false;
		jump_high = min(H[i]+time+U_P[i], jump_high+U_P[i]);
		jump_down = max(H[i]-time-D_P[i], jump_down-D_P[i]);	
	}
	return true;
}

void solve()
{
	prepare();
	double answer = 0;
	bool equal = check_equal();
	if (not equal)
	{
		double maximum = 1e9;
		double minimum = 0;
		for (int i = 0; i < 100; ++i)
		{
			double middle = (maximum + minimum)/2;
			if (possible_show(middle))
			{
				maximum = middle;	
			}
			else
			{
				minimum = middle;
			}
		}
		answer = maximum;
	}
	cout << fixed << setprecision(6) << answer << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int c=1; c<=T; ++c)
	{
		read();
		cout << "Case #"<<c<<": ";
		solve();
	}

	return 0;
}