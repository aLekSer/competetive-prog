#include <vector>

using namespace std;

class EllysAndXor {
    public:

int getMax(vector <int> numbers);
    };

int EllysAndXor::getMax(vector <int> numbers) {
    if ( numbers.size() == 1 )
        return numbers[0];
    int m = 0;
    int c =  1 << ( numbers.size() - 1);
    
    for (int i = 0 ; i < c ; i ++ ) 
    {
        int d = numbers[0];
   		int l = i;
    	//int id = 1;
        for (int j = 1 ; j < numbers.size(); j ++ )
        {
            if (l % 2) {
                d = d & numbers[j];
                } else {
                d = d ^ numbers[j];
                }
                l = l/2;
        }
        if ( d > m )
             m = d;
        
        
    }
    return m;
}

int main () {

}