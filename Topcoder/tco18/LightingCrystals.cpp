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
vector<vector<long long>> pos3;
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
            int x = i + i2;
        if (pos[x][j] & ver) {
            success = true;
            pos2[x][j] |= ver;
            pos3[x][j] = i*10000 + j;
            cerr << "ASFD";
            return true;
        } else if (ver < 10 && ver > 0 && (pos[x][j] + res[x][j]) > 0 )  {
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
            int x = i - i2;
        if (pos[i-i2][j] & ver) {
            success = true;
            pos2[i-i2][j] |= ver;
            pos3[i-i2][j] = i*10000 + j;
        } else if (ver < 10 && ver > 0 && ( pos[x][j] + res[x][j] > 0))  {
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
                int x = j + i2;
            if (pos[i][j+i2] & ver) {
            pos2[i][j+i2] |= ver;
                success = true;
            pos3[i][j + i2] = i*10000 + j;
            } else if (ver < 10 && ver > 0 && ( pos[i][x] + res[i][x] > 0))  {
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
                int x = j - i2;
	   if (pos[i][j-i2] & ver) {
            pos2[i][j-i2] |= ver;
            //Seting failed lamp
            pos3[i][j - i2] = i*10000 + j;
	    success = true;
	} else if (ver < 10 && ver > 0 && ( pos[i][x] + res[i][x] > 0))  {
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
	  pos2 = vector<vector<int>>(n, vector<int>(m, 0));
	  pos3 = vector<vector<long long>>(n, vector<long long>(m, 0));
            vector<int> placedC(n, 0);
            vector<int> placedR(m, 0);
           for (int i = 0; i < n; i ++) {
                   bool setL = false;
                   bool seenThisLine = false;
               for (int j = 0; j < m; j++) {
                   if ( tB[i][j] >= '1' && tB[i][j] <= '6') {
                       seenThisLine  = true;
                       c = tB[i][j] - '1' + 1;
                       seen.insert(c);
                       pos[i][j] = c;
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
                            //res[i][j] = (res[i][j]<<1 )% 8;
			                //update_res(i, j, n, m, 0);
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
        /*
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
        } */
        int obstCount = 0;
        int mirCount = 0;
        const int Total = 2;
        int skip = Total;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                if(pos2[i][j]  != pos[i][j]) {
                   // fal.insert(pos3[i][j]);
                   if (skip != 0) {
                       skip --;
                       continue;
                   } else {
                       skip = Total;
                   }
                   if (obstCount < maxObstacles)  {
                        cerr << "OBst";
                       int x = pos3[i][j]/10000;
                       int y = pos3[i][j]%10000;
                       int midX = (x + i) /2;
                       int midY = (y + j) /2;
                       cerr << midX << midY;
                       if (!pos[midX][midY] && res[midX][midY] == 100 && midX != i && midY != j && midX != x && midY != y ) {
                        cerr << "bbOO";
                            char buf[50];
                            sprintf(buf, "%d %d X", midX, midY);
                            res[midX][midY] = 16;
                            //st.push_back(buf);
                            obstCount ++;
                       }
                   }
                   if (mirCount < maxMirrors)  {
                        cerr << "OBst";
                       int x = pos3[i][j]/10000;
                       int y = pos3[i][j]%10000;
                       int midX = (x + i) /2;
                       int midY = (y + j) /2;
                       if (!pos[midX][midY] && res[midX][midY] == 100 && midX != i && midY != j && midX != x && midY != y ) {
                        cerr << "bbO2";
                            char buf[50];
                            sprintf(buf, "%d %d \\", midX, midY);
                            res[midX][midY] = 32;
                            st.push_back(buf);
                            mirCount ++;
                       }
                   }

                }
            }
        }
                        cerr << "TUT2";
        
           for (int i = 0; i < n; i ++) {
               
               for (int j = 0; j < m; j++) {
                        cerr << "TUT";
                        if (res[i][j]  < 15 && res[i][j] > 0) {
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
           /**/
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
           /**/
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
