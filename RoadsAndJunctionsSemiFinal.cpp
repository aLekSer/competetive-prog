// C++11
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//1) NAIVE implementation is to just link all cities with the roads in the index order without junctions
// Try to send this to check how much score it gonna have and time consumption of sqr(N) algo
typedef double t2;
typedef double main_t;
typedef double t3;
//#define INT_MAX2 = 1 << 30;main_t;
class RoadsAndJunctions {
public:
    int NC;
    vector<int> result;
    vector<int> result2;
    vector<int>  c2;
    vector<int>  junctions;
    vector<int>  outputJunctions;
    double jc ;
    double jf ;
    int S1;
    vector<int>  c3;
    long long total;
    long long total_1st;
    //adjacency matrix with mst
    vector<vector<main_t>> mst;
    double distance(int i, int j, vector<int> & c)
    {
        double d1 = c[2*i]- c[2*j];
        double d2 = c[2*i+1]- c[2*j+1];
        return sqrt(d1*d1+d2*d2);
    }
    // A utility function to print the constructed MST stored in parent[]
    int minKey(vector<main_t> key, vector<bool> mstSet)
    {
        // Initialize min value
        int NC = mstSet.size();
        int min = INT_MAX, min_index;
        
        for (int v = 0; v < NC; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;
        
        return min_index;
    }
    int printMST(vector<int> parent, int n, vector<vector<main_t>> graph)
    {
        result = vector<int>(0);
        mst = vector<vector<main_t>>(n, vector<main_t>(n, 0));
        //printf("Edge   Weight\n");
        //cerr << n << " ts " << endl;
        for (int i = 1; i < n ; i++)
        {
            result.push_back(parent[i]);

            result.push_back(i);
            total += graph[i][parent[i]];
            mst[i][parent[i]] = graph[i][parent[i]];
            mst[parent[i]][i] = graph[i][parent[i]];
            // cerr << endl << "in here " << parent[i] << " " << i;
            //printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
        }
        //cerr << "Total " <<   total << endl;
      return 0;
    }
    //Find coords
    void findFermat(int i, int j, int k, int & x, int & y)
    {
        int ax, ay;
        int bx, by;
        //int cx, cy;
        findEqui(i, j, k, ax, ay);
        findEqui(j, k, i, bx, by);
        //findEquiTest();
        //findEqui(j, k, i,  cx, cy);
        t2 resx;
        t2 resy;
        //cerr << "Before intersection " << i << " size "<< j << " " << k; 
        char s [250]; sprintf( s,  " Check triangle %d %d %d %d %d %d", c2[2*k], c2[2*k+1], c2[2* i], c2[2 * i + 1], c2[2* j], c2[2 * j + 1] );
        //cerr << s;
        //cerr << "Before intersection " << S1 << " size "<< ax << " "    << ay <<  " " <<bx <<  " " <<by << endl;
        //intersection(ax, ay, c2[2*k], c2[2*k+1], bx, by, c2[2* i], c2[2 * i + 1], &resx, &resy);
        char res2 = intersection(ax, ay, c2[2*k], c2[2*k+1] , bx, by, c2[2* i], c2[2 * i + 1], &resx, &resy);
        x = resx;
        y = resy;
        //&& jc < 0.2 && jf < 0.2 
        if (res2  ) {
            bool new_point = true;
            for (int i = 0 ; i < NC; i ++)
            {
                if (c2[2*i] == x && c2[2*i +1 ] == y) {
                    new_point = false;
                    break;
                }
                

            }
            for (int i = 0 ; i < junctions.size()/2; i ++)
            {
                if (junctions[2*i] == x && junctions[2*i +1 ] == y) {
                    new_point = false;
                    break;
                }
                

            }
            if (new_point && (x >0 ) && (x < S1) && (y >0 ) && (y < S1)) {
                junctions.push_back(x );
                junctions.push_back(y );
                c3.push_back(x);
                c3.push_back(y);
            }
        }
        //cerr << "Intersection points " << (int)res2 << " " << x << " "  << y << endl;
        t2 resx2;
        t2 resy2;
        char res3 = intersection(-1, 0, 2, 0, 0, -1 ,  0 ,2, &resx2, &resy2);
        //cerr <<  endl << "Result "  << (int )res3 << " "<< resx2 << " " << resy2<< endl;
        //cerr << "1 " << endl;

    }
    typedef double T;
    int sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }
    //First 2 points forms side from whihc we form an equilateral triangle

    void findEquiTest()
    {
        t3 ax = 0;
        t3 bx = 2;
        t3 cx = 0;
        t3 ay = 0;
        t3 by = 0;
        t3 cy = 2;
        cerr << "Find eq1t " << ax  << " " << ay   << bx << " "<< " " << by; /*
        double dx = bx - ((bx - ax) - sqrt(3) *(by -ay)) /2;
        double dy = by + (sqrt(3)*(bx - ax) -  (by -ay)) /2;
        */
       double r = sqrt(3)* (ay -by);
       cerr << endl << r << endl;
       r = sqrt(3)* (bx - ax );
       cerr << endl << r << endl;
        double dx = (((bx + ax) + sqrt(3)* (ay -by)) /2);
         double dy = ((sqrt(3)*(bx - ax) + by +  ay) /2);
        cerr << "Find eq 2 t " << dx  << " " << dy << endl;
        int x = (int)dx;
        int y = (int)dy;
        if(sgn(vect(cx - ax, cy - ay, bx- ax, by - ay)) != sgn(vect(x - ax, y - ay, bx- ax, by - ay)))
            return ;
            /*
        x = (int)(bx + ((bx - ax) - sqrt(3)* (by -ay)) /2);
        y = (int)(by - (sqrt(3)*(bx - ax) -  (by -ay)) /2);
        
        */
        x = (int)(((bx + ax) - sqrt(3)* (ay -by)) /2);
        y = (int)((by +  ay - sqrt(3)*(bx - ax) ) /2);
        cerr << "Find eq3 t " << x  << " " << y << endl;
    }
    void findEqui(int i, int j, int k, int &x , int &y)
    {
        t3 ax = c2[2*i];
        t3 bx = c2[2*j];
        t3 cx = c2[2*k];
        t3 ay = c2[2*i + 1];
        t3 by = c2[2*j + 1];
        t3 cy = c2[2*k + 1];
        //cerr << "Find eq1 " << ax  << " " <<ay<< " " << bx << " " <<by;
        /*
        double dx = bx - ((bx - ax) - sqrt(3) *(by -ay)) /2;
        double dy = by + (sqrt(3)*(bx - ax) -  (by -ay)) /2;
        */
       //cerr << "More ut put " << sqrt(3.)*  (bx - ax) << endl;
        double dx = (((bx + ax) + sqrt(3.)*  (ay -by)) /2.);
         double dy = ((sqrt(3.)*(bx - ax) + by +  ay) /2.);
        //cerr << "Find eq 2 " << dx  << " " << dy << endl;
        x = (int)dx;
        y = (int)dy;
        if(sgn(vect(cx - ax, cy - ay, bx- ax, by - ay)) != sgn(vect(x - ax, y - ay, bx- ax, by - ay)))
            return ;
            /*
        x = (int)(bx + ((bx - ax) - sqrt(3)* (by -ay)) /2);
        y = (int)(by - (sqrt(3)*(bx - ax) -  (by -ay)) /2);
        
        
        */
       dx = ( (bx + ax - sqrt(3.)*  (ay -by) ) / 2.);
         dy = (( by +  ay - sqrt(3.)*(bx - ax)) /2.);
        x = (int)( (bx + ax - sqrt(3.)*  (ay -by) ) / 2.);
        y = (int)( (by + ay - sqrt(3.)* (bx - ax) ) / 2.);
        //cerr << "Find eq3  " << x  << " " << y  << " " << dx <<" " << dy << endl;
    }
    double vect(int ax , int ay, int bx, int by) {
        return ax * by - ay * bx;
    }
    double distance(int i, int x, int y)
    {
        double d1 = c2[2*i]- x;
        double d2 = c2[2*i+1]- y;
        return sqrt(d1*d1+d2*d2);
    }
    // we need to find two fermat points one by one
    double calculateReduction(int i, int j, int k)
    {
        int x;
        int y;
        findFermat(i, j , k, x , y);
        main_t total = 0;
        total += distance(i, x, y); 
        total += distance(j, x, y);
 		return total;

    }// Returns 1 if the lines intersect, otherwise 0. In addition, if the lines 
    // intersect the intersection point may be stored in the floats i_x and i_y.
    char intersection   (t2 p0_x, t2 p0_y, t2 p1_x, t2 p1_y, 
        t2 p2_x, t2 p2_y, t2 p3_x, t2 p3_y, t2 *i_x, t2 *i_y)
    {
        float s1_x, s1_y, s2_x, s2_y;
        s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
        s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

        float s, t;
        s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
        t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

        if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
        {
            // Collision detected
            if (i_x != NULL)
                *i_x = p0_x + (t * s1_x);
            if (i_y != NULL)
                *i_y = p0_y + (t * s1_y);
            return 1;
        }

        return 0; // No collision
    }
    int selectThree() {
        // Just scan the column in matrix for now and select 4 first vertices 
        // which forms subgraph in MST
        //    cerr << "1";
        c3 = vector<int>(0);
        for (int i = 0 ; i < c2.size(); i ++) 
        {
            c3.push_back(c2[i]);
        }
        // cerr << c3.size() << "Size c3";
        for (int i = 0 ; i < NC-2; i ++)
        {
            int j = 0;
            for (; j < NC; j++)
            {
                if (mst[i][j]) {
                    break;
                }
            }
            int k = 0; 
            for (; k < NC; k++)
            {
                if (mst[j][k] && k != i) 
                    break;

            }
            int l = 0; 
            for (; l < NC; l++)
            {
                if (mst[l][k] && k != i && l !=j) 
                    break;

            }
            calculateReduction(j, k, l );
            //cerr << "2";
            //cerr << endl << i << " " << j << " " << k << endl;
            /*
            if ( red > max)
            {
                max =  red;
                fx = i; fy = j; fz = k; ff = l;
            }*/
        }
            //  cerr << "FOund" << c3.size();
      return 0;
    }
    // Function to construct and print MST for a graph represented using adjacency
    // matrix representation
    void primMST(vector<vector<main_t>> graph)
    {
        int NC = graph.size();
        vector<int> parent(NC); // Array to store constructed MST
        vector<main_t> key(NC);   // Key values used to pick minimum weight edge in cut
        vector<bool> mstSet(NC);  // To represent set of vertices not yet included in MST
    
        // Initialize all keys as INFINITE
        for (int i = 0; i < NC; i++)
            key[i] = INT_MAX, mstSet[i] = false;
    
        // Always include first 1st vertex in MST.
        key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
        parent[0] = -1; // First node is always root of MST 
    
        //cerr << NC;
        //cerr << "here 2";
        /*
        for (int i = 0; i < 15 ; i ++ )
        {

        for (int j = 0; j < 15 ; j ++ )
        {
            cerr << graph[i][j] << " ";

        }
        cerr << endl;
        }*/
        // The MST will have V vertices
        for (int count = 0; count < NC-1; count++)
        {
        //cerr << "here " << count;
            // Pick the minimum key vertex from the set of vertices
            // not yet included in MST
            int u = minKey(key, mstSet);
    
            // Add the picked vertex to the MST Set
            mstSet[u] = true;
    
            // Update key value and parent index of the adjacent vertices of
            // the picked vertex. Consider only those vertices which are not yet
            // included in MST
            for (int v = 0; v < NC; v++)
    
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];
        }
        // print the constructed MST
        printMST(parent, graph.size(), graph);
    }
    vector<vector<main_t>> preprocessCities(vector<int> & c)
    {
        int NC2 = c.size() / 2;
        //cerr << NC2 << "length " << endl;
        vector<vector<main_t>> Result (NC2, vector<main_t>(NC2, 0));
        for (int i = 0; i < NC2; i++) {
            for (int j = 0; j < NC2; j++) {
                Result[i][j] = distance(i, j, c);
            }
        }
       // cerr << "123";
        return Result;
    }
    void select_junctions(vector<int> &junctions_min, vector<int>& c4, int selected) {
        junctions_min = vector<int>({});
        for (int i = 0 ; i < c2.size(); i ++)
        {
            c4.push_back(c2[i]);
        }
        for (int i = 0 ; i < junctions.size()/2; i ++) {
            if ( selected & (1 << i)) {
                junctions_min.push_back(junctions[2*i]);
                junctions_min.push_back(junctions[2*i+1]);
            c4.push_back(junctions[2*i]);
            c4.push_back(junctions[2*i+1]);
                
            }
        }
    }

    void select_junctions2(vector<int> &junctions_min, vector<int>& c4, vector<int> juncSt) {
        junctions_min = vector<int>({});
        for (int i = 0 ; i < c2.size(); i ++)
        {
            c4.push_back(c2[i]);
        }
        cerr << junctions.size() << "Size " << endl;
        cerr << outputJunctions.size() << "Sized " <<endl;
        for (int i = 0 ; i < outputJunctions.size()/2; i ++) {
            if ( juncSt[i]) {
                junctions_min.push_back(outputJunctions[2*i]);
                junctions_min.push_back(outputJunctions[2*i+1]);
            c4.push_back(outputJunctions[2*i]);
            c4.push_back(outputJunctions[2*i+1]);
                
            }
        }
    }
    vector<int> buildJunctions(int S, vector<int> cities, double junctionCost, double failureProbability) {
        c2 = cities;
        S1 = S;
        // store number of cities for building the roads
        NC = cities.size() / 2;
        junctions = vector<int> (0);
        // build one junction at (0,0)
        //return vector<int>({0, 0});
        // adjacency matrix
        vector<vector<main_t >> distance;
        jc = junctionCost;
        jf = failureProbability;
        distance = preprocessCities(cities);
        cerr << "Distance " << distance.size();   
        cerr << "Here ";
        primMST(distance);
        cerr << "Here ";
        //int x; int y;
        selectThree();
        cerr << "Number of junctions " << junctions.size() << endl;
        vector<vector<main_t >> distance2;
        jc = junctionCost;
        distance2 = preprocessCities(c3);
        cerr << c3.size();
        cerr << distance2[0][0] << " 2errr \n";
        result2 = result;
        cerr << distance2[0][0] << " 24errr \n";
        total_1st = total;
        total = 0;
        //cerr << distance2[0][0] << " 24errr \n";
        //cerr << "Distance " << distance2.size();    
        primMST(distance2);
        cerr << " 2ewr " ;
        //cerr << "Distance " << distance2.size();
        int total_min = total_1st;
        cerr << "3333 ";
            vector<int> result_min;
         
            vector<int> junctions_min;
            vector<int> junctions_reserv;

        bool set1 = false;
        for (int i = 1; i < 256 ; i ++)
        {
            int j = 1 << i;
            vector<vector<main_t >> distance2;
            jc = junctionCost;
            vector<int> c4;
            select_junctions(junctions_min, c4, j);
            //cerr << " Junct mi2 size " << junctions_min.size() << " " << c4.size() << endl;
            if (junctions_min.size() != 0) {
                 total = 0;
                distance2 = preprocessCities(c4);   
                primMST(distance2);
                double add;
                if (failureProbability  == 0 )
                    add  = junctions_min.size()/2*junctionCost;
                else {

                    add  = junctions_min.size()/2*junctionCost/failureProbability;

                }
                //cerr << "Add " << add;
                if (((total + add )< total_min)) {
                    total_min = total + add;
                    result_min = result;
                   // junctions_min = junctions;
                    junctions_reserv =junctions_min;
                    set1 = true;
                    cerr << "Total  1st " << total << " "<< result_min.size()<< " " << junctions.size()<<  endl;
                }
            }
        }
        for (int i = 1; i < 256 ; i ++)
        {
            vector<vector<main_t >> distance2;
            jc = junctionCost;
            vector<int> c4;
            select_junctions(junctions_min, c4, i);
            //cerr << " Junct mi2 size " << junctions_min.size() << " " << c4.size() << endl;
            if (junctions_min.size() != 0) {
                 total = 0;
                distance2 = preprocessCities(c4);   
                primMST(distance2);
                double add;
                if (failureProbability  == 0 )
                    add  = junctions_min.size()/2*junctionCost;
                else {

                    add  = junctions_min.size()/2*junctionCost/failureProbability;

                }
                //cerr << "Add " << add;
                if (((total + add )< total_min)) {
                    total_min = total + add;
                    result_min = result;
                   // junctions_min = junctions;
                    junctions_reserv =junctions_min;
                    set1 = true;
                    cerr << "Total  1st " << total << " "<< result_min.size()<< " " << junctions.size()<<  endl;
                }
            }
        }
                if(set1) {
                //if (total_min != total && total_min > 0 && junctions_reserv.size() != 0) {
                    junctions = junctions_reserv;
                    result = result_min;
                    cerr << "Here 1sr232" << total << " min " << total_min ;
                    
                } else {
                    junctions = vector<int>({});
                    result = result2;
                }
                /*  
        if (total_1st > total) {
            return vector<int>({});
        }
        */
        //cerr << "1234";
      int total = S * junctionCost * failureProbability;
      //cerr << total;
        //return vector<int>({S/2, S/2});
        //return vector<int>({});
        outputJunctions = junctions;
        return junctions;
        
    }
    vector<int> buildRoads(vector <int> junctionStatus) {
        // build a road from the single junction to each city
        // (we assume that it was built, but don't check it)
        vector<int> ret(2 * NC );
        bool b = true ; //junctionStatus[0]; // = true;//
        
        for (int i =0 ; i < junctionStatus.size() ; i ++)
        {
            cerr << "Fss ";
            b = b && junctionStatus[i];
        }
        if (b){
            cerr << "Fss2 ";
            cerr << outputJunctions.size() << endl;
            return result;
        } else {
            cerr << "Fss3 ";
            vector<vector<main_t >> distance2;
            vector<int> c4({});
            vector<int> junctions_min({});
            for (int i = 0 ; i < junctionStatus.size(); i ++)
            {
                cerr << " JS " << junctionStatus[i]; 
            }
            cerr <<endl;
            select_junctions2(junctions_min, c4, junctionStatus);
            cerr << " Junct mi size " << junctions_min.size() << " " << c4.size() << endl;
                 total = 0;
                distance2 = preprocessCities(c4);   
                primMST(distance2);
                   // junctions_min = junctions;
                return result;
            
        }
      /*
      else {
        vector<int> ret(2 * NC -2);
        for (int i = 0; i < NC-1; ++i) {
            ret[2 * i] = NC-1;
            ret[2 * i + 1] = i;
        }
        cerr << endl << result.size();
        return result;
      }*/
    }
};

//////
// /////
////
template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}

int main() {
    RoadsAndJunctions rj;
    int S, C;
    cin >> S >> C;
    vector<int> cities(C);
    getVector(cities);
    double junctionCost, failureProbability;
    cin >> junctionCost >> failureProbability;

    vector<int> ret = rj.buildJunctions(S, cities, junctionCost, failureProbability);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
    
    int J;
    cin >> J;
    vector<int> junctionStatus(J);
    getVector(junctionStatus);

    ret = rj.buildRoads(junctionStatus);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
