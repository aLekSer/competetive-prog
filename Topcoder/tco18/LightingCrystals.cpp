// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <time.h>

template <typename T>
void remove_duplicates(std::vector<T>& vec)
{
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

using namespace std;

vector<vector<int>> res;
vector<vector<int>> pos;
vector<vector<int>> pos2;
vector<vector<long long>> pos3;
// We will use to close the points for new lanterns if ver = 0
// or to calculate the colored diamonds if ver = color
// if ver = -1 removing the light
bool update_res(int i, int j, int n, int m, int ver, int col = 0, int* color = NULL) {
	bool success = false;
    for (int i2 = 1; i2 < n; i2 ++) {
        if (i + i2 < n )  { 
            if ( (ver==0)){
                if( !pos[i + i2][j] ) { //&& (res[i +i2][j] %100 == 0 )) {
                    res[i+i2][j] += 100; //lightning the area
                    //cerr << "Light "<<endl;
                } else break;
            }
        else if (ver > 0) { 
            int x = i + i2;
        if (res[x][j] ==  16 || res[x][j] ==  32)
        break;
        if (pos[x][j] & ver) {
            success = true;
            pos2[x][j] |= ver;
            pos3[x][j] = i*10000 + j;
            //cerr << "ASFD";
        break;
            //return true;
        } else if (ver < 10 && ver > 0 && (pos[x][j] ) > 0 )  {
                if (pos[x][j] < 16)
                    pos2[x][j] |= ver;
                break;
            }
       
        }
        if (ver == -1) { if ( pos[i+i2][j] == 0 && res[i+i2][j] != 16) {//&& res[i+i2][j] == 100) {
            res[i+i2][j] -=100;
            } else break; }
        if (ver == -2) {
            int x = i + i2;
        if (res[x][j] ==  16 || res[x][j] ==  32)
         return false;
            if (pos[i][x] > 0) 
                return false;
            if (pos[x][j] == 0 && (res[x][j] > 0) && (res[x][j] < 6 ) ) {//&& res[i+i2][j] == 100) {
                *color = res[x][j];
                return true;
            } 
            /*
            if (pos[x][j] & col) {
                success = true;
                pos2[x][j] |= col;
                return true;
            } */
        }
        }
    }

    
    for (int i2 = 1; i2 < n; i2 ++) {
        if(i - i2 >=0 ) {
            if  ((ver==0) ) {
                if (!pos[i - i2][j] ) { // && (res[i - i2][j]%100 == 0 )) {
                res[i-i2][j] +=100; //lightning the area
                } else break;
            }
        else if (ver > 0) {
            int x = i - i2;
        if (res[x][j] ==  16 || res[x][j] ==  32)
        break;
        if (pos[i-i2][j] & ver) {
            success = true;
            pos2[i-i2][j] |= ver;
            pos3[i-i2][j] = i*10000 + j;
        break;
            //return true;
        } else if (ver < 10 && ver > 0 && ( pos[x][j]  > 0))  {
                if (pos[x][j]< 16)
                    pos2[x][j] |= ver;
                break;
            }
            }
            if (ver == -1 ) { if ( pos[i-i2][j] == 0 && res[i-i2][j] != 16) {//  &&  res[i-i2][j] == 100) {
                res[i-i2][j] -= 100; 
                } else break; }

        if (ver == -3) {
            int x = i - i2;
            if (pos[i][x] > 0)
                return false;
        if (res[x][j] ==  16 || res[x][j] ==  32)
         return false;
            if (pos[x][j] == 0 && (res[x][j] > 0) && (res[x][j] < 6 ) && res[x][j] != 16) {//&& res[i+i2][j] == 100) {
                *color = res[x][j];
                return true;
            } /*
            if (pos[x][j] & col) {
                success = true;
                pos2[x][j] |= col;
                return true;
            }*/
        }
        }
    }
       
    for (int i2 = 1; i2 < m; i2 ++) {
        if(j + i2 < m ) {
            if ((ver==0)) {
            if( !pos[i][j + i2]) { // && (res[i][j +i2]%100 == 0 )) {
                res[i][j+i2] +=100; //lightning the area

                } else break;
            } else if (ver > 0) {
                int x = j + i2;
        if (res[x][j] ==  16 || res[x][j] ==  32)
        break;
            if (pos[i][j+i2] & ver) {
            pos2[i][j+i2] |= ver;
                success = true;
            pos3[i][j + i2] = i*10000 + j;
        break;
            //return true;
            } else if (ver < 10 && ver > 0 && ( pos[i][x] > 0))  {
                if (pos[i][x]< 16)
                   pos2[i][x] |= ver;
                break;
            }
            
           
         } 
         if (ver == -1) { if ( pos[i][j+i2] == 0 && res[i][j+i2] != 16) {// && res[i][j+i2]%100 == 100) {
                res[i][j+i2] -= 100;
            } else break; }
        if (ver == -4) {
            int x = j+i2;
            if (pos[i][x] == 0 && (res[i][x] > 0) && (res[i][x] < 6 ) && res[i][x] != 16) {//&& res[i+i2][j] == 100) {
                *color = res[i][x];
                return true;
            }
            if (pos[i][x] > 0)
                return false;
        if (res[i][x] ==  16 || res[i][x] ==  32)
         return false;
         /*
            if (pos[i][x] & col) {
                success = true;
                pos2[i][x] |= col;
                return true;
            } */
        }
         
    }
    }

    for (int i2 = 1; i2 < m; i2 ++) {
        if (j - i2 >= 0 ) { 
            if((ver==0)) { if(!pos[i ][j-i2] ) { // && (res[i][j - i2] == 0 )) {
            res[i][j-i2] += 100; //lightning the area
             } else break;
        } else if (ver > 0) {
                int x = j - i2;
        if (res[x][j] ==  16 || res[x][j] ==  32)
        break;
	   if (pos[i][j-i2] & ver) {
            pos2[i][j-i2] |= ver;
            //Seting failed lamp
            pos3[i][j - i2] = i*10000 + j;
	    success = true;
        break;
           // return true;
	} else if (ver < 10 && ver > 0 && ( pos[i][x]  > 0))  {
                if (pos[i][x]< 16)
                   pos2[i][x] |= ver;
                break;
            }
	 }
    if (ver == -1 ) { if ( pos[i][j-i2] == 0 && res[i][j-i2] != 16) {//&& res[i][j-i2] == 100) {
		res[i][j-i2] -=100; 
            } else break; }
         
    }
        if (ver == -5) {
            int x = j-i2;
        if (res[i][x] ==  16 || res[i][x] ==  32)
            return false;
            if (pos[i][x] > 0)
                return false;
            if (pos[i][x] == 0 && (res[i][x] > 0) && (res[i][x] < 6 ) && res[i][x] != 16) {//&& res[i+i2][j] == 100) {
                *color = res[i][x];
                return true;
        }
                /*
            if (pos[i][x] & col) {
                success = true;
                pos2[i][x] |= col;
                return true;
            }
            */
    
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
    srand ( time(NULL) );
            vector<string> BestSt;
            int mx = -100000;
           const int n = tB.size();
           const int m = tB[0].length();
           const int MAL = 5;
        for (int tot = 0 ; tot < 400; tot ++) {
           set<int> seen;
           int c;
            vector<string> st;
           int calc = 0;
           //cerr << costObstacle;
	  res = vector<vector<int>>(n, vector<int>(m, 0));
	  pos = vector<vector<int>>(n, vector<int>(m, 0));
	  pos2 = vector<vector<int>>(n, vector<int>(m, 0));
	  pos3 = vector<vector<long long>>(n, vector<long long>(m, 0));
            vector<int> placedC(n, 0);
            vector<int> placedR(m, 0);
           for (int i = 0; i < n; i ++) {
               for (int j = 0; j < m; j++) {
                   if ( tB[i][j] >= '1' && tB[i][j] <= '6') {
                       c = tB[i][j] - '1' + 1;
                       seen.insert(c);
                       pos[i][j] = c;
                   } else if (tB[i][j] == 'X') {
                       //cerr << int('X') << endl;
                        pos[i][j] = 16;
                   }
               }
           }
           int M = 0x1;
           //for (int k = 0; k < 3 ; k ++) {

           for (int i = 0; i < n; i ++) {
               for (int j = 0; j < m; j++) {
                   if(pos[i][j] && pos[i][j] != 16  ) {
                       placedC[i] = pos[i][j];
                       //cerr << placedC[i] << "added "<< endl;
                       placedR[j]  = pos[i][j];
                   }
                      
               }
           }
            //M = M << 1;
           //}
            M = 0x1;
           //for (int k = 0; k < 3; k ++) {

                for (int i = 0; i < n; i ++) {
                    bool br;
                    if (true ) { //placedC[i] & M) {
                        //cerr << " Here ";
                        for (int j = 0; j < m; j++) {
                        int r2 = rand() %10;
                            for (int k = 6; k > 0; k --) {
                            int r = rand() %3;
                            bool suc = update_res(i, j, n, m,  1 << r);
                            if((suc  && r2 < MAL && !pos[i][j]  && (res[i][j] == 0) /*&&  (placedR[j] & M) && (placedC[i] & M)*/)) {
                                res[i][j] = 1 << r;
                                //cerr <<  placedR[j] << "bef" << endl;
                                //placedR[j] = placedR[j] ^ M;
                                //placedC[i] = placedC[i] ^ M;
                                //cerr <<  placedR[j] << "after" << endl;
                                update_res(i, j, n, m, 0);
                                break;
                            }
                            }
                                
                        }
                    }
                }
                M = M << 1;
                    //cerr << endl;
                    /*
                for (int i = 0; i < n; i ++) {
                    bool br;
                    for (int j = 0; j < m; j++) {
                        //cerr << res[i][j] << " " ;
                    }
                        //cerr << endl;
                    }   
                //cerr << M << endl; */
           //}
            //cerr << "TU22";

            M = 0x1;
            
           //for (int k = 0; k < 3; k ++) {

        if (tot > 50) {
                for (int i = 0; i < n; i ++) {
                    bool br;
                        //cerr << " Here2324 " << k;
                    for (int j = 0; j < m; j++) {
                        int r = rand() %3;
                        int r2 = rand() %10;
                            for (int k = 0; k < 3; k ++) {
                                bool suc = update_res(i, j, n, m,  1 << k);
                        if(( suc && r2 < MAL && (pos[i][j] == 0) && (res[i][j] == 0)/* && (placedR[j] & M) && ( placedC[i] & M)*/)) {
                            res[i][j] = 1 << k;
                            //cerr <<  placedR[j] << "bef" << endl;
                            //placedR[j] = placedR[j] ^ M;
                            //placedC[i] = placedC[i] ^ M;
                            //cerr <<  placedR[j] << "aft" << endl;
                            /**/
			                update_res(i, j, n, m, 0);
                            break;
                        }
                            }
                            
                    }
                }
        }
                M = M << 1;
           //}
           //cerr << "step 2";
           set<long long > fal;
           /**/
        for (int i = 0; i < n; i ++) {
            bool br;
            for (int j = 0; j < m; j++) {
                if(((pos[i][j] == 0)  && (res[i][j]>0 && res[i][j] < 100))) {
                    //cerr << "Light231" << endl;
                    bool suc =  update_res(i, j, n, m, res[i][j]);
                    int r = rand() % 3;
                    if (!suc ) {

                            //
                        //bool suc = update_res(i, j, n, m, ((res[i][j]<<1 )% 8));
                        if (!suc ) {
                            //cerr << "FOUND" << endl;
                            //fal.insert(i*10000 + j);
                            //TODO uncomment
                            res[i][j] = 0;
                            update_res(i, j, n, m, -1);
                            for (int k = 3; k < 0; k ++) {
                                suc = update_res(i, j, n, m,  1 << k);
                                if (suc) {
                                    res[i][j] = 1 << k;
                                    update_res(i, j, n, m, 0);
                                    break;
                                }

                            }
                        } else {
                            //res[i][j] = (res[i][j]<<1 )% 8;
			                //update_res(i, j, n, m, 0);
                        }
                    }
                    //break;
                }
                    
            }
        }
        //cerr << "step 3";
        for (int i = 0; i < n; i ++) {
            bool br;
            for (int j = 0; j < m; j++) {
                //cerr << res[i][j] + pos[i][j] << " " ;
            }
                //cerr << endl;
            }   
        //cerr << M << endl;
        /**/
        if (tot > 30) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                if((pos[i][j] == 0) && (res[i][j]==0) ) {
                        //cerr << "44 44" << endl;
                    bool suc = update_res(i, j, n, m, 1);
                    if (suc ) {
                        //cerr << i << j << endl;
                        res[i][j]= 1;
                         update_res(i, j, n, m, 0);
                         continue;
                    }
                    suc = update_res(i, j, n, m, 2);
                    if (suc ) {
                        //cerr << i << j << endl;
                        res[i][j]= 2;
                         update_res(i, j, n, m, 0);
                         continue;
                    }
                    suc = update_res(i, j, n, m, 4);
                    if (suc ) {
                        //cerr << i << j << endl;
                        res[i][j]= 4;
                         update_res(i, j, n, m, 0);
                         continue;
                    }
                    //break;
                }
                    
            }
        } 
        }
        if (tot > 50) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                if((pos[i][j] == 0) && (res[i][j]==0) ) {
                    int newc = rand() % 3;
                    bool suc = true; // update_res(i, j, n, m, 1 << newc);
                    if (suc) {
                        res[i][j] = 1 << newc;
                        update_res(i,j,n,m, 0);

                    }

                }
                //cerr << res[i][j] + pos[i][j] << " " ;
            }

            //cerr << endl << "  Next   ";
        }
        }
        for (int i = 0; i < n; i ++) {
            bool br;
            for (int j = 0; j < m; j++) {
                if(((pos[i][j] == 0)  && (res[i][j]>0 && res[i][j] < 100))) {
                    //cerr << "Light231" << endl;
                    bool suc =  update_res(i, j, n, m, res[i][j]);
                    if (!suc ) {

                        //bool suc = update_res(i, j, n, m, ((res[i][j]<<1 )% 8));
                        if (!suc ) {
                            //cerr << "FOUND" << endl;
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
        int obstCount = 0;
        int mirCount = 0;
        const int Total = 2;
        int skip = Total;
        //cerr << "Tutses";
        // REcalc of pos2
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                int r = rand()%10;
                if (r < MAL && res[i][j] > 0 && res[i][j] < 6) {
                    res[i][j] = 0;
                    update_res(i,j,n,m,-1);
                }
            }
        }
                for (int i = 0; i < n; i ++) {
                    bool br;
                    if (true ) { //placedC[i] & M) {
                        //cerr << " Here ";
                        for (int j = 0; j < m; j++) {
                        int r = rand() %3;
                        int r2 = rand() %10;
                                bool suc =  true ; //update_res(i, j, n, m,  1 << r);
                            if((suc && r2 < MAL && !pos[i][j]  && (res[i][j] == 0) /*&&  (placedR[j] & M) && (placedC[i] & M)*/)) {
                               // res[i][j] = 1 << r;
                                //cerr <<  placedR[j] << "bef" << endl;
                                //placedR[j] = placedR[j] ^ M;
                                //placedC[i] = placedC[i] ^ M;
                                //cerr <<  placedR[j] << "after" << endl;
                               // update_res(i, j, n, m, 0);
                            }
                                
                        }
                    }
                }
        int totalLit = 0;
        int totalCr = 0;
        if (tot % 3 == 0) {
                for (int i = 0; i < n; i ++) {
                    bool br;
                    if (true ) { //placedC[i] & M) {
                        //cerr << " Here ";
                        for (int j = 0; j < m; j++) {
                        int r2 = rand() %10;
                            for (int k = 6; k > 0; k --) {
                            int r = rand() %3;
                            bool suc = update_res(i, j, n, m,  1 << r);
                            if((suc  && (res[i][j] % 100 == 0  ) && !pos[i][j]  && (res[i][j] == 0) /*&&  (placedR[j] & M) && (placedC[i] & M)*/)) {
                                res[i][j] = 1 << r;
                                //cerr <<  placedR[j] << "bef" << endl;
                                //placedR[j] = placedR[j] ^ M;
                                //placedC[i] = placedC[i] ^ M;
                                //cerr <<  placedR[j] << "after" << endl;
                                update_res(i, j, n, m, 0);
                                break;
                            }
                            }
                                
                        }
                    }
                }
        for (int i = 0; i < n; i ++) {
            bool br;
            for (int j = 0; j < m; j++) {
                if(((pos[i][j] == 0)  && (res[i][j]>0 && res[i][j] < 100))) {
                    //cerr << "Light231" << endl;
                    bool suc =  update_res(i, j, n, m, res[i][j]);
                    int r = rand() % 3;
                    if (!suc ) {

                            //
                        //bool suc = update_res(i, j, n, m, ((res[i][j]<<1 )% 8));
                        if (!suc ) {
                            //cerr << "FOUND" << endl;
                            //fal.insert(i*10000 + j);
                            //TODO uncomment
                            res[i][j] = 0;
                            update_res(i, j, n, m, -1);
                            for (int k = 3; k < 0; k ++) {
                                suc = update_res(i, j, n, m,  1 << k);
                                if (suc) {
                                    res[i][j] = 1 << k;
                                    update_res(i, j, n, m, 0);
                                    break;
                                }

                            }
                        } else {
                            //res[i][j] = (res[i][j]<<1 )% 8;
			                //update_res(i, j, n, m, 0);
                        }
                    }
                    //break;
                }
                    
            }
        }
        }
	  pos2 = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                if (res[i][j] > 0 && res[i][j] < 6) {
                    update_res(i,j,n,m,res[i][j]);
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                    int r2 = rand() %10;
                if(r2 < MAL && pos[i][j] == 0 ) { // && pos2[i][j]  != pos[i][j]) {
                   // fal.insert(pos3[i][j]);
                   /*
                   if (skip != 0) {
                       skip --;
                       continue;
                   } else {
                       skip = Total;
                   }*/
                   if (tot > 70) {
                   if (costObstacle < 10 && obstCount < maxObstacles)  {
                        //cerr << "OBst";
                       int x = pos3[i][j]/10000;
                       int y = pos3[i][j]%10000;
                       //int midX = (x + i) /2;
                       //int midY = (y + j) /2;
                       int midX =  i;
                       int midY =  j;
                       //cerr << midX << midY;
                       if (!pos[midX][midY] && (res[midX][midY] % 100) == 0) { //&& midX != i && midY != j && midX != x && midY != y ) {
                        //cerr << "bbOO";
                            char buf[50];
                            sprintf(buf, "%d %d X", midX, midY);
                            res[midX][midY] = 16;
                            st.push_back(buf);
                            //cerr << "Added 1" << endl;
                            obstCount ++;
                       }
                   }
                   } 
                   if ( mirCount < maxMirrors)  {
                        //cerr << "OBst";
                       int x = pos3[i][j]/10000;
                       int y = pos3[i][j]%10000;
                       //int midX = (x + i) /2;
                       //int midY = (y + j) /2;
                       int midX =  i;
                       int midY =  j;
                       int r = 0;
                       int color = 0;
                       int ll;
                         int dx;
                         int dy;
                       for (int l = -2 ; l > -6; l--) {
                           //ll = l;
                         //r += update_res(midX, midY, n, m, l, 1, & color) ? 1 :0;

                           switch (l) {
                               case -2:
                               dx = +1; dy = 0;
                               break;
                               case -3:
                               dx = -1; dy = 0;
                               break;
                               case -4:
                               dx = 0; dy = +1;
                               break;
                               case -5:
                               dx = 0; dy = -1;
                               break;                    
                           }
                           for (int o = 1; o < max(n, m); o++) {
                               int x = midX + o*dx;
                               int y = midY + o*dy;
                               if (x >=0 && x < n && y >= 0 &&  y < m)
                               if(res[x][y] > 0 && res[x][y] < 6) {
                                   color = res[x][y];
                                   r++;
                                   ll = l;
                                   continue;
                               }
                               if (pos[x][y] > 0) {
                                   continue;
                               }
                           }
                       }
                         //cerr << r;
                       if (r == 1) {
                    int r2 = rand() %3;
                       if (r2 < MAL && !pos[midX][midY] && res[midX][midY] % 100 == 0) { //  && midX != i && midY != j && midX != x && midY != y ) {

                           switch (ll) {
                               case -2:
                               dx = 0; dy = -1;
                               break;
                               case -3:
                               dx = 0; dy = +1;
                               break;
                               case -4:
                               dx = -1; dy = 0;
                               break;
                               case -5:
                               dx = +1; dy = 0;
                               break;                    
                           }
                           for (int o = 1; o < max(n, m); o++) {
                               int x = midX + o*dx;
                               int y = midY + o*dy;
                               if (x >=0 && x < n && y >= 0 &&  y < m)
                               if(pos[x][y] > 0) {
                                   if (pos[x][y] < 16) {
                                       pos2[x][y] |= color;
                                      // cerr << "Here";
                                   }
                                break;
                               }
                           }
                           switch (ll) {
                               case -2:
                               dx = -1; dy = 0;
                               break;
                               case -3:
                               dx = +1; dy = 0;
                               break;
                               case -4:
                               dx = 0; dy = -1;
                               break;
                               case -5:
                               dx = 0; dy = -1;
                               break;                    
                           }
                           for (int o = 1; o < max(n, m); o++) {
                               int x = midX + o*dx;
                               int y = midY + o*dy;
                               if (x >=0 && x < n && y >= 0 &&  y < m)
                               if(pos[x][y] > 0) {
                                   if (pos[x][y] < 16) {
                                       if ( pos2[x][y] & color) {

                                      // cerr << "Here2";
                                        pos2[x][y] ^= color;
                                       }
                                   }
                                break;
                               }
                           }
                        //cerr << "bbO2";
                            char buf[50];
                            //cerr << "Added";
                            sprintf(buf, "%d %d /", midX, midY);
                            res[midX][midY] = 32;
                            st.push_back(buf);
                            mirCount ++;
                       }
                       }
                   }/**/

                }
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j++) {
                if((pos2[i][j]  == pos[i][j]) && (pos[i][j] > 0) && (pos[i][j] < 16)) {
                    if (pos[i][j] != 1 && pos[i][j] != 2 && pos[i][j] != 4)
                        calc += 30;
                    else calc+= 20;
                    totalLit ++;
                }
                if((pos2[i][j] != 0) && (pos2[i][j]  != pos[i][j] ) && (pos[i][j] > 0) && (pos[i][j] < 16)) {
                    calc -= 10;
                   //cerr << pos2[i][j] << pos[i][j] << endl;
                }
                if (res[i][j] > 0 && res[i][j] < 6 ) {
                    calc -= costLantern;
                   //cerr << "Lantern";
                    }
                if (res[i][j] == 16 ) {
                    calc -= costObstacle;
                   //cerr << "Lantern";
                    }
                if (res[i][j] == 32 ) {
                    calc -= costMirror;
                   //cerr << "Lantern";
                    }
                if (pos[i][j] > 0 && pos[i][j] < 16){
                    totalCr ++;
                }
            }}
           M = 0x1;
           // We need to iterate through all cells, calculate the total score
           // and color that we should add at the certain row column
           /*
        */
                //cerr << "TUT2";
    
        for (int i = 0; i < n; i ++) {
            
            for (int j = 0; j < m; j++) {
                   // //cerr << "TUT3214";
                    if (res[i][j]  < 15 && res[i][j] > 0) {
                        char buf[50];
                        sprintf(buf, "%d %d %d", i, j, res[i][j]);
                        
                        //set<long long >::iterator it = fal.find(i*10000 + j);
                        //if (it == fal.end()) {
                            st.push_back(buf);
                        //}
                    }
            }
        }
        for (int i = 0; i < st.size(); i++) {
            //cerr << st[i] << endl;
        }
        //cerr << totalLit << " " <<  calc << " Before return";
        if (calc > mx) {
            mx = calc;
            BestSt = st;
        }
            //BestSt = st;
       }
       cerr << "MAx" << mx;
        remove_duplicates<string>(BestSt);
        if (mx > -1000000)
            return BestSt;
        else
            return {};

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
    //cout << "Here 234";
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
