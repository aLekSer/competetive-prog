#include "vector"
#include <iostream>

using namespace std;

bool inR(int a) {
    int x = a % 10;
    return x == 2 || x == 3 || x == 9; 
}
int alg1(int a, int b)
{
    int count = 0;
    if ( a / 10 == b / 10 ){
        for (int i = a ; i  <= b; i++) {
            if (inR(i))
            count ++;
        }
    } else {
        for (int i = a; i < ((a / 10) + 1) * 10 ; i ++)
        {
            if (inR(i))
            count ++;
        }
        cerr << "Res" << ((b / 10) ) * 10 ;
        for (int i = ((b / 10) - 1) * 10 ; i <= b; i ++)
        {
            //cerr << i << endl;
            if (inR(i))
            count ++;
        }
        int y = b/10 - a / 10 - 2;
        count += y*3;
    }
    return count;
}
int main() 
{
    int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
	    int a, b;
	    cin >> a >> b; 
	    cout << alg1(a, b) << endl;
	}
return 0;

}