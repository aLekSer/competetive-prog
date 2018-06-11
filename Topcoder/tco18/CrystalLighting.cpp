// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector<vector<int>> res;
vector<vector<int>> pos;
vector<vector<int>> pos2;
// We will use to close the points for new lanterns if ver = 0
// or to calculate the colored diamonds if ver = color
// if ver = -1 removing the light
bool update_res(int i, int j, int n, int m, int ver) {
	bool success = false;
    for (int i2 = 1; i2 < n; i2 ++) {
        if (i + i2 < n )  { 
            if ( (ver==0) ){
                if( !pos[i + i2][j]){ //&& (res[i +i2][j] == 0 )) {
                    res[i+i2][j] = 100; //lightning the area
                    cerr << "Light "<<endl;
                } else break;
            }
        else if (ver > 0) { 
        if (pos[i+i2][j] & ver) {
            success = true;
            cerr << "ASFD";
            return true;
        } else if (ver < 10 && ver > 0 && pos[i][j+i2] == 16)  {
                break;
            }
        if (ver == -1 && res[i+i2][j] == 100) {
            res[i+i2][j] = 0;
            } else break;
       
        } else break;
    }
    }

    for (int i2 = 1; i2 < n; i2 ++) {
        if(i - i2 >=0 ) {
            if (ver==0) {
                if (!pos[i - i2][j]) { //&& (res[i - i2][j] == 0 )) {
                res[i-i2][j] =100; //lightning the area
                } else break;
            }
        else if (ver > 0) {
        if (pos[i-i2][j] & ver) {
            success = true;
        } else if (ver < 10 && ver > 0 && pos[i][j+i2] == 16)  {
                break;
            }
        if (ver == -1 && res[i-i2][j] == 100) {
            res[i-i2][j] = 0; 
            } else break;
        } else break;
    }
    }
       
    for (int i2 = 1; i2 < m; i2 ++) {
        if(j + i2 < m ) {
            if ((ver==0)) {
            if( !pos[i][j + i2] ) { //&& (res[i][j +i2] == 0 )) {
                res[i][j+i2] =100; //lightning the area

                } else break;
            } else if (ver > 0) {
            if (pos[i][j+i2] & ver) {
                success = true;
            } else if (ver < 10 && ver > 0 && pos[i][j+i2] == 16)  {
                break;
            }
            if (ver == -1 && res[i][j+i2] == 100) {
                res[i][j+i2] = 0;
            } else break;
           
         } else break;
    }
    }

    for (int i2 = 1; i2 < m; i2 ++) {
        if (j - i2 >= 0 ) { 
            if((ver==0)) { if(!pos[i ][j-i2]  ){ // && (res[i][j - i2] == 0 )) {
            res[i][j-i2] =100; //lightning the area
             } else break;
        } else if (ver > 0) {
	   if (pos[i][j-i2] & ver) {
	    success = true;
	} else if (ver < 10 && ver > 0 && pos[i][j+i2] == 16)  {
                break;
            }
    if (ver == -1 && res[i][j-i2] == 100) {
		res[i][j-i2] = 0; 
            } else break;
	 } else break;
    }
    }
	return success;

}
class CrystalLighting {
public:
    // Details of the marks used
    // 6.XX..2..X
    //ROW COL TYPE
    //  '1', '2' and '4' for lanterns of primary colors, '\' and '/' for a mirror and 'X' for an obstacle. 
    vector<string> placeItems(vector<string> tB, int costLantern, int costMirror, int costObstacle, 
       int maxMirrors, int maxObstacles) {
            vector<string> st;
           set<int> seen;
           int c;
           cerr << costObstacle;
           const int n = tB.size();
           const int m = tB[0].length();
	  res = vector<vector<int>>(n, vector<int>(m, 0));
	  pos = vector<vector<int>>(n, vector<int>(m, 0));
            vector<int> placedC(m, 0);
            vector<int> placedR(n, 0);
           for (int i = 0; i < n; i ++) {
                   bool setL = false;
                   bool seenThisLine = false;
               for (int j = 0; j < m; j++) {
                   if ( tB[i][j] >= '1' && tB[i][j] <= '6') {
                       seenThisLine  = true;
                       c = tB[i][j] - '1' + 1;
                       seen.insert(c);
                       pos[i][j] = c;
                   } else if (tB[i][j] == '.' && seenThisLine && !setL && !placedC[j] && !placedR[i]) {
                       setL= true;
                       
                   } else if (tB[i][j] == 'X') {
                       cerr << int('X') << endl;
                        pos[i][j] = 16;
                   }
               }
           }
           int M = 0x1;
           //for (int k = 0; k < 3 ; k ++) {

           for (int i = 0; i < n; i ++) {
                   bool setL = false;
                   bool seenThisLine = false;
               for (int j = 0; j < m; j++) {
                   if(pos[i][j] && pos[i][j] != 16  ) {
                       placedC[i] = pos[i][j];
                       cerr << placedC[i] << endl;
                       placedR[j]  = pos[i][j];
                   }
                      
               }
           }
            //M = M << 1;
           //}
            M = 0x1;
           for (int k = 0; k < 3; k ++) {

                for (int i = 0; i < n; i ++) {
                    bool br;
                    if (placedC[i] & M) {
                        cerr << " Here ";
                    for (int j = 0; j < m; j++) {
                        if((!pos[i][j]  && (res[i][j] == 0) &&  (placedR[j] & M))) {
                            res[i][j] = M;
			                update_res(i, j, n, m, 0);
                            //break;
                        }
                            
                    }
                    }
                }
                M = M << 1;
                    cerr << endl;
                for (int i = 0; i < n; i ++) {
                    bool br;
                    for (int j = 0; j < m; j++) {
                        cerr << res[i][j] << " " ;
                    }
                        cerr << endl;
                    }   
                cerr << M << endl;
           }
                        cerr << "TU22";

            M = 0x1;
           for (int k = 0; k < 3; k ++) {

                for (int i = 0; i < n; i ++) {
                    bool br;
                        cerr << " Here2324 ";
                    for (int j = 0; j < m; j++) {
                        if((!pos[i][j]  && (res[i][j] == 0))) {
                            res[i][j] = M;
			                update_res(i, j, n, m, 0);
                            //break;
                        }
                            
                    }
                }
                M = M << 1;
                    cerr << endl;
                for (int i = 0; i < n; i ++) {
                    bool br;
                    for (int j = 0; j < m; j++) {
                        cerr << res[i][j] << " " ;
                    }
                        cerr << endl;
                    }   
                cerr << M << endl;
           }
           set<long long > fal;
        for (int i = 0; i < n; i ++) {
            bool br;
            for (int j = 0; j < m; j++) {
                if(((pos[i][j] == 0)  && (res[i][j]>0 && res[i][j] < 100))) {
                        cerr << "Light231" << endl;
                    bool suc = update_res(i, j, n, m, res[i][j]);
                    if (!suc ) {

                        bool suc = update_res(i, j, n, m, ((res[i][j]<<1 )% 8));
                        if (!suc ) {
                            cerr << "FOUND" << endl;
                            //fal.insert(i*10000 + j);
                            res[i][j] = 0;
                            update_res(i, j, n, m, -1);
                        } else {
                            res[i][j] = (res[i][j]<<1 )% 8;
                        }
                    }
                    //break;
                }
                    
            }
        }
                for (int i = 0; i < n; i ++) {
                    bool br;
                    for (int j = 0; j < m; j++) {
                        cerr << res[i][j] + pos[i][j] << " " ;
                    }
                        cerr << endl;
                    }   
                cerr << M << endl;
       
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                if((pos[i][j] == 0) && (res[i][j]==0) ) {
                        cerr << "44 44" << endl;
                    bool suc = update_res(i, j, n, m, 1);
                    if (suc ) {
                        cerr << i << j << endl;
                        res[i][j]= 1;
                    }
                    suc = update_res(i, j, n, m, 2);
                    if (suc ) {
                        cerr << i << j << endl;
                        res[i][j]= 2;
                    }
                    suc = update_res(i, j, n, m, 4);
                    if (suc ) {
                        cerr << i << j << endl;
                        res[i][j]= 4;
                    }
                    //break;
                }
                    
            }
        }
                        cerr << "TUT2";
        
           for (int i = 0; i < n; i ++) {
               
               for (int j = 0; j < m; j++) {
                        cerr << "TUT";
                        if (res[i][j]  < 100 && res[i][j] > 0) {
                            char buf[50];
                            sprintf(buf, "%d %d %d", i, j, res[i][j]);
                            
                            set<long long >::iterator it = fal.find(i*10000 + j);
                            if (it == fal.end()) {
                                st.push_back(buf);
                            }
                        }
               }
            }
           M = 0x1;
           // We need to iterate through all cells, calculate the total score
           // and color that we should add at the certain row column
           /*
           for (int k = 0; k < 3; k ++) {

                    for (int j = 0; j < m; j++) {
                    bool br;
                    if (placedR[j] & M) {
                        cerr << " Here ";
                for (int i = 0; i < n; i ++) {
                        if((!pos[i][j]  && (res[i][j] == 0) )) {
                            res[i][j] = M;
                            for (int i2 = 1; i2 < n; i2 ++) {
                                if((i + i2 < n )  &&  !pos[i + i2][j] ){ //&& (res[i +i2][j] == 0 )) {
                                    res[i+i2][j] =100; //lightning the area
                                } else break;
                            }

                            for (int i2 = 1; i2 < n; i2 ++) {
                                if((i - i2 >= 0 )  &&  !pos[i - i2][j] ){ //&& (res[i - i2][j] == 0 )) {
                                    res[i-i2][j] =100; //lightning the area
                                } else break;
                            }
                            for (int i2 = 1; i2 < m; i2 ++) {
                                if((j + i2 < m )  &&  !pos[i][j + i2]  ){ //&& (res[i][j +i2] == 0 )) {
                                    res[i][j+i2] =100; //lightning the area
                                } else break;
                            }

                            for (int i2 = 1; i2 < m; i2 ++) {
                                if((j - i2 >= 0 )  &&  !pos[i ][j-i2]  ){ // && (res[i][j - i2] == 0 )) {
                                    res[i][j-i2] =100; //lightning the area
                                } else break;
                            }

                            //break;
                        }
                            
                    }
                    }
                }
                M = M << 1;
                    cerr << endl;
                for (int i = 0; i < n; i ++) {
                    bool br;
                    for (int j = 0; j < tB[i].length(); j++) {
                        cerr << res[i][j] << " " ;
                    }
                        cerr << endl;
                    }   
                cerr << M << endl;
           }
           */
                /*
                        char buf [50];
                        if (c & 0x1)
                        sprintf(buf, "%d %d %d", i, j, c & 0x1);
                        placedR[i] = true;
                        placedC[j] = true;
                        if (c & 0x2)
                        sprintf(buf, "%d %d %d", i, j, c & 0x2);
                        if (c & 0x4)
                        sprintf(buf, "%d %d %d", i, j, c & 0x4);
                       st.push_back(buf);
                       */
                for (int i = 0; i < n; i ++) {
                    bool br;
                    for (int j = 0; j < m; j++) {
                        cerr << res[i][j] << " " ;
                    }
                        cerr << endl;
                    }
           return st;

        //return {"0 7 2", "9 5 1"};
    }
};
// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}
/*
int main() {
    CrystalLighting cl;
    int H;
    cin >> H;
    vector<string> targetBoard(H);
    getVector(targetBoard);
    int costLantern, costMirror, costObstacle, maxMirrors, maxObstacles;
    cin >> costLantern >> costMirror >> costObstacle >> maxMirrors >> maxObstacles;

    vector<string> ret = cl.placeItems(targetBoard, costLantern, costMirror, costObstacle, maxMirrors, maxObstacles);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
*/
int main() {
    CrystalLighting cl;
    int H;
    cin >> H;
    vector<string> targetBoard(H);
    getVector(targetBoard);
    int costLantern, costMirror, costObstacle, maxMirrors, maxObstacles;
    cin >> costLantern >> costMirror >> costObstacle >> maxMirrors >> maxObstacles;

    vector<string> ret = cl.placeItems(targetBoard, costLantern, costMirror, costObstacle, maxMirrors, maxObstacles);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
