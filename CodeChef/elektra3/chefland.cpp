#include <iostream>
#include <numeric>
int main()
{
    std::ios::sync_with_stdio(false); bool brk;
    short t; std::cin>>t; long long* n1, *n2; long n,k,p; long long sum1,sum2;
    while(t--)
    {
        std::cin>>n>>k>>p; n1 = new long long[n]; n2 = new long long[n];
        brk = false; sum1=0; sum2=0;
        for(int i=0;i<n;i++) std::cin>>n1[i];
        for(int i=0;i<n;i++) std::cin>>n2[i];
        for(int i=0;i<n-k;i++)
        {
            sum1 = std::accumulate(n1+i,n1+i+k,sum1);
            sum2 = std::accumulate(n2+i,n2+i+k,sum2);
            if(sum1+sum2>=p) { std::cout<<"no\n"; brk = true; break; }
            sum1=0; sum2=0;
        }
        if(!brk) std::cout<<"yes\n";
        delete[] n1; delete[] n2;
        if(brk) continue;
    }
}

/*#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool prime(long n)
{
    if(n==1) return false;
    else if(n==2||n==3) return true;
    else for(int i=2;i<=sqrt(n);i++) if(n%i==0) return false;
    return true;
}
void find_sub(vector<long> vec, int n)
{
    vector<long> vec2;
    for(unsigned short i=0;i<vec.size();i++)
    {
        for(int j=n-i;j<n;j++)
        {
            vec2.clear(); vec2.resize(n-i); copy(vec.begin()+n-j,vec.begin()+j+1,vec2.begin());
            if(count_if(vec2.begin(),vec2.end(),[](long v){return prime(v);})
            >count_if(vec2.begin(),vec2.end(),[](long v){return !prime(v);}))
            { cout<<vec2.size(); return; }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    short t; cin>>t; long n; vector<long> vec;
    while(t--)
    {
        cin>>n; vec.clear(); vec.resize(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        find_sub(vec,n);
    }
}
*/
