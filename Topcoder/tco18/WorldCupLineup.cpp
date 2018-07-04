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
    
double start_time = 0;
double timeout = 10; // seconds
const double ticks_per_sec = 2500000000;
inline double get_time() {
    uint32_t lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return (((uint64_t)hi << 32) | lo) / ticks_per_sec;
}
double max_temperature = 0.9;
double min_temperature = 0.1;

double prob_change_1 = 0.4;
double prob_change_2 = 0.3;
double prob_change_3 = 0.3;
void StateChange1() {

}
void simulated_annealing() {
      double skip_time = get_time() - start_time;
      double used_time = skip_time;
      std::uniform_real_distribution<double> type_dist(0, 1);
      std::mt19937 rnd;
      while (used_time < timeout) {
        double temperature = (1.0 - (used_time - skip_time) / (timeout - skip_time))
          * (max_temperature - min_temperature) + min_temperature;
        
        for (int iteration = 0; iteration < 1000; iteration++) {
          double type = type_dist(rnd);
            
          // prob_change_1 + prob_change_2 + prob_change_3 == 1.0
          /*
          if (type < prob_change_1) {
            stch sd1 = StateChange1();
            if (accept(sd1.delta, temperature)) {
              sd1.apply();
            }
          }
          else if (type < prob_change_1 + prob_change_2) {
            stch sd2 = StateChange2();
            if (accept(sd2.delta, temperature)) {
              sd2.apply();
            }
          }
          else {
            stch sd3 = StateChange3();
            if (accept(sd3.delta, temperature)) {
              sd3.apply();
            }
          }*/
            
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
// F, M , D - 0, 1, 2
vector<int> players;

vector<vector<int>> stats;
class WorldCupLineup {
public:
    vector<string> selectPositions(vector<string> players, vector<string> groups) {
       // cerr << "1";
       cerr << players.size() << " " << groups.size();
       for (int i = 0 ; i < players.size(); i ++) {
           vector<string> v = tokenize(players[i], ',');
           cerr << "a " << v[0] << " end ";
       }
        return vector<string>({"F 0", "F 1", "F 2", "M 3", "M 4", "M 5", "M 6", "D 7", "D 8", "D 9"});
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
       // cerr << "1";
    cin >> H;
    //cerr << H;
    vector<string> players(H);
    getVector(players);
       // cerr << "1";
       string s;
       cin >> s;
    cin >> H;
    cerr << H;
    vector<string> groups(H);
    getVector(groups);
        //cerr << "1";

    vector<string> ret = sol.selectPositions(players, groups);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
