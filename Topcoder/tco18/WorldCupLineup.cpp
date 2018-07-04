// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <random>
    using namespace std;
// F, M , D - 0, 1, 2
vector<bool> pls;

vector<vector<int>> stats;
vector<vector<int>> locStats;
double start_time = 0;
double timeout = 10; // 65; //10; // seconds
const double ticks_per_sec = 2500000000;
inline double get_time() {
    uint32_t lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    //cerr << (((uint64_t)hi << 32) | lo) / ticks_per_sec;;
    return (((uint64_t)hi << 32) | lo) / ticks_per_sec;
}
double max_temperature = 0.9;
double min_temperature = 0.1;

double prob_change_1 = 0.2;
double prob_change_2 = 0.3;
double prob_change_3 = 0.4;
const int cc = 10;
// Player, position
//bool players [30];
vector<vector<int>> curSt;
vector<vector<int>> maxSt;  
int curSc = 0;
int maxSc = 0;
vector<vector<int>> gr;
vector<vector<int>> grSt;
class stch {
    public:
    //changing player number
    vector<int> shifts; 
    // changing player to forward etc
    vector<int> incr;
    int calcS() {
        locStats = stats;
        int a = 0;
        int d = 0;
        for (int i = 0; i <  gr.size(); i ++) {
        bool all = true;
        for (int j = 0; j < gr[i].size(); j ++) {
            all &= pls[gr[i][j]] ;
        }
        if (all) {
            //cerr << "Updating " << i << endl;
        for (int j = 0; j < gr[i].size(); j ++) {
            for (int k = 0; k < 3 ; k ++)
            locStats[gr[i][j]][k] += grSt[i][k];
        }

        }
        }

        for (int i = 0; i < 10; i ++) {
            if (curSt[i][1] == 1) {
                a += locStats[curSt[i][0]][0] * (1- (double)locStats[curSt[i][0]][2]/100)  ; 
                d += locStats[curSt[i][0]][1]* (1- (double)locStats[curSt[i][0]][2]/100)  ;
            } else if (curSt[i][1] == 0) {
                a += 2* locStats[curSt[i][0]][1]* (1- (double)locStats[curSt[i][0]][2]/100)  ;
            } else {

                d += 2*  locStats[curSt[i][0]][0]* (1- (double)locStats[curSt[i][0]][2]/100)  ;
            }
        }
        return min(a, d);
    }
    void apply() {

        for (int i = 0; i < cc; i ++) {
            if (this->shifts[i] == 0)  
                continue;
                if( this->shifts[i] ==3) {
                    this->shifts[i] == 4;
                }
                int j = rand() % 10;
            pls[curSt[j][0]] = false;
            curSt[j][0] += this->shifts[i] ;
            
             curSt[j][0] %= 30;
            while (pls[curSt[j][0]] ) {
                curSt[j][0] += this->shifts[i] ;
                ////cerr << this->shifts[i];
             curSt[j][0] %= 30;
            }
                pls[curSt[j][0]] = true;
        }
        curSc = calcS();
        if (curSc > maxSc) {
            maxSt = curSt;
            maxSc = curSc;
        }


    }
    void apply2() {

        for (int i = 0; i < 10; i ++) {
            curSt[i][1] += this->incr[i] ;
            
             curSt[i][1] %= 3;
        }
        curSc = calcS();
        if (curSc > maxSc) {
            maxSt = curSt;
            maxSc = curSc;
        }


    }
    double Delta; 
};
stch StateChange1(double temp) {
    stch stDel;
    stDel.shifts = vector<int>(cc);

    stDel.incr = vector<int>(10, 0);
    for (int i = 0; i < cc; i ++) {
        if ((rand()% 100) / 100 < temp)
        stDel.shifts[i] = rand() % cc;
    }
    for (int i = 0; i < 10; i ++) {

        bool r = rand() % 2;
        if (r ) {
            stDel.incr[i] ++;
        }
    }
    stDel.Delta = 0;
    for (int i = 0; i < cc; i ++) {

        if (stDel.shifts[i])
            stDel.Delta ++ ;
    }
        stDel.Delta /= (cc * 5);
        return stDel;
}
void simulated_annealing() {
      double skip_time = get_time() - start_time;
      double used_time = skip_time;
      std::uniform_real_distribution<double> type_dist(0, 1);
      std::mt19937 rnd;
      int count = 0;
      //while (used_time < timeout) {
          //cerr << used_time;
          while (count < 2000) {
              count ++;
        double temperature = (1.0 - ( (double)count ) / (2000))
          * (max_temperature - min_temperature) + min_temperature;
              if (count % 100 == 0) 
              cerr << count << " d "<< maxSc << " T " <<  temperature << endl;
        
        for (int iteration = 0; iteration < 1000; iteration++) {
          double type = type_dist(rnd);
            
          // prob_change_1 + prob_change_2 + prob_change_3 == 1.0
          
          if (type < prob_change_1) {
            stch sd1 = StateChange1(temperature);
            ////cerr << sd1.Delta << " d " << endl;
            if (sd1.Delta < temperature) {
              sd1.apply();
            } else {
                ////cerr << "not";
            }
          }
          else if (type < prob_change_1 + prob_change_2) {
            stch sd2 = StateChange1(temperature);
            if (sd2.Delta < temperature)  {
              sd2.apply2();
            }
          }
          else {
            stch sd3 = StateChange1(temperature);
            if (sd3.Delta < temperature) {
              sd3.apply();
              sd3.apply2();
            }
          }
            /**/
        }
      }
      used_time = get_time() - start_time;
    }
    
std::vector<std::string> tokenize(const std::string& s, char c) {
    auto end = s.cend();
    auto start = end;

    std::vector<std::string> v;
    for( auto it = s.cbegin(); it != end; ++it ) {
        if( *it != c ) {
            if( start == end )
                start = it;
            continue;
        }
        if( start != end ) {
            v.emplace_back(start, it);
            start = end;
        }
    }
    if( start != end )
        v.emplace_back(start, end);
    return v;
}

using namespace std;
class WorldCupLineup {
public:
    vector<string> selectPositions(vector<string> players, vector<string> groups) {
       // //cerr << "1";
       stats = vector<vector<int>>(30, vector<int>(3));
       //cerr << players.size() << " " << groups.size();
       for (int i = 0 ; i < players.size(); i ++) {
           vector<string> v = tokenize(players[i], ',');
           //cerr << "a " << v.size() << " end ";
           if (v.size() > 0) {
               
           for (int j = 0; j < 3; j++) {
                stats[i][j] = atoi(v[j].c_str());
                //cerr << stats[i][j] <<  " stats   " << endl;
           }
           }
       }

    gr = vector<vector<int>> (groups.size(), vector<int>());
    grSt = vector<vector<int>> (groups.size(), vector<int>());
       for (int i = 0 ; i < groups.size(); i ++) {
           vector<string> v = tokenize(groups[i], ' ');
           //cerr << "a " << v.size() << " end ";
           if (v.size() > 0) {
           vector<string> v2 = tokenize(v[0], ',');
           vector<string> v3 = tokenize(v[1], ',');
           for (int j = 0; j < v2.size(); j++) {
                gr[i].push_back(atoi(v2[j].c_str()));
                //cerr << stats[i][j] <<  " grstats   " << endl;
           }
           for (int j = 0; j < v3.size(); j++) {
                grSt[i].push_back(atoi(v3[j].c_str()));
           }
           }
       }
       curSt = 
vector<vector<int>> (10, vector<int>(2));
        pls = vector<bool> (30, false);
       for (int i = 0 ; i < 10; i ++) {
           curSt[i][0] = i;
           curSt[i][1] = i % 3;
           pls[i] = true;
       }
       simulated_annealing();
vector<string> f(10);
for (int i = 0; i < 10; i++) {
    string s = "";
    if (maxSt[i][1] == 0) {
        s += "F " ;
    }
    if (maxSt[i][1] == 1) {
        s += "M ";
    }
    if (maxSt[i][1] == 2) {
        s += "D ";
    }
    s += to_string(maxSt[i][0]);
    s += ",2,29,24,29";
    f[i] = s;
}
    return f;
        //return  vector<string>({"F 0", "F 1", "F 2", "M 3", "M 4", "M 5", "M 6", "D 7", "D 8", "D 9"});
    }
};
// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        getline(cin, v[i]);
}

int main() {
  start_time = get_time();
    WorldCupLineup sol;
    int H;
       // //cerr << "1";
    cin >> H;
    ////cerr << H;
    vector<string> players(H);
    getVector(players);
       string s;
       cin >> s;
       //cerr << s;
       // //cerr << "1";
       //string s;
       //cin >> s;
    cin >> H;
    //cerr << H;
    vector<string> groups(H);
    getVector(groups);
        ////cerr << "1";

    vector<string> ret = sol.selectPositions(players, groups);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
