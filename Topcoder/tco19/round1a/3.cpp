#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

class EllysCodeConstants  {
    public:
    string getLiteral(string candidate);
//double getPrice(int N, vector <int> C, int target);
};


 string EllysCodeConstants::getLiteral(string candidate)
 {
     string o = "0x";
     // L, LL, U, UL, ULL, LU, LLU
     set<char> s;
     //'O', 'Z', 'S', 'T', 'A', 'B', 'C', 'D', 'E', 'F'
     char myints[]= {'O', 'Z', 'S', 'T', 'A', 'B', 'C', 'D', 'E', 'F'};  
     s.insert(myints, myints +10);
     set<char> m;
     m.insert('L');
     m.insert('U');
     map<char, char> g;
     g['O']= '0';
     g['I']= '1';
     g['T']= '7';
     g['S']= '5';
     g['A']= 'A';
     g['B']= 'B';
     g['C']= 'C';
     g['D']= 'D';
     g['E']= 'E';
     g['F']= 'F';
     string ca = candidate;
     for (int i = 0; i < candidate.length(); i ++ ) {
         if (m.find(ca[i]) == m.end() && s.find(ca[i]) == s.end()) 
         {
             return "";
         } else {
             o += g[ca[i]];
             }
     }
     return o;
     
 }