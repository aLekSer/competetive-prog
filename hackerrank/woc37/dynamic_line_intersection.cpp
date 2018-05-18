#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the dynamicLineIntersection function below.
 */
void dynamicLineIntersection(int n) {
    /*
     * Write your code here.
     */
    long long k;
    long long b;
    int lines = 0;
    long long q;
    int queries = 0;
    char c; 
    typedef std::pair<long long, long long> DoublePair;
    typedef unordered_map<long long, int> setter;
    vector<int> inter(200002, 0);
    vector<int> K(100002, 0);
    vector<int> B(100002, 0);
    int oneCount = 0;
    //map<int, int> M;
    setter abc;
    set<long int> abc2;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == '?')
        {
          cin >> q;  
            
               long long total = 0;
            long double first = 0, second = 0;
                for (int i = 2; i <= sqrt(100000); i++)
                {
                        long long tmp = i * 1000000 + q % i;
                        total += abc[tmp];

                }
                    total += inter[q] + oneCount + B[q];
              cout << total << "\n";
        } else if (c == '+')
        {
          cin >> k;
          cin >> b;
            if (k == 1)
                oneCount ++;
            long long tmp = k * 1000000 + b % k;
            DoublePair d(k, b % k);
            abc[tmp]++;
            if (k > sqrt(100000)) {
                for (int i = -100000/k -2 ; i < 100000/k + 2; i++ )
                {
                    long long res = i*k + b;
                    if(res>=0 && res <= 100000)
                    {
                        inter[res] ++;
                    }
                }
                
            }
            long long  i = 0;
                    long double r = 0;
        } else if (c == '-')
        {
          cin >> k;
          cin >> b;
            if (k == 1)
                oneCount --;
            DoublePair d(k, b % k);
            long long tmp = k * 1000000 + b % k;
            abc[tmp]--;
            if (k > sqrt(100000)) {
                for (int i = -100000/k -2; i < 100000/k + 2; i++ )
                {
                    long long res = i*k + b;
                    if(res>=0 && res <= 100000)
                    {
                        inter[res] --;
                    }
                }
                  //B[b] --;
            }
            long double r = 0;
            long long  i = 0;
        }
            
    }
}

int main()
{
    int n;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> n;
    cerr << "123";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    dynamicLineIntersection(n);

    return 0;
}
