#include <vector>

using namespace std;

class EllysTicketPrices {
    public:
double getPrice(int N, vector <int> C, int target);
};


 double EllysTicketPrices::getPrice(int N, vector <int> C, int target)
 {
     double res = 1;
     vector<double> k;
    for (int i = 0; i < C.size(); i ++)
    {
        res *= (100. + C[i]) / 100. ;
        k.push_back(res);
    }
    double sum = 1;
    for (int i = 0; i < C.size(); i ++)
    {
        sum += k[i];
    }
    double appr = target * N / sum;
    return appr;
}

int main() {
    EllysTicketPrices e;vector<int> v; 
    //v.push_back();
}
