// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
// Use  RoadsAndJunctions as reference how to change this into vector

#include <bits/stdc++.h>

#include <stdio.h>
#include <limits.h>
#include <vector>
  
// Number of vertices in the graph
//#define V 9

using namespace std;
  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(vector<int> dist, vector<bool> sptSet)
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < dist.size(); v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// A utility function to print the constructed distance array
int printSolution(vector<int> dist, int n)
{
   cerr <<"Vertex   Distance from Source\n";
   char buf [256];
   for (int i = 0; i <  dist.size(); i++) {
      sprintf(buf, "%d tt %d\n", i, dist[i]);
      cerr << buf << endl;
   }
}
  
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
long dijkstra(vector<vector<int>> graph, int src, int k)
{
     vector<int> dist(graph.size());     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     vector<bool> sptSet(graph.size()); // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < graph.size(); i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < graph.size()-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in the first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < graph.size(); v++)
       {
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
                                       {
            dist[v] = dist[u] + graph[u][v];
                                       }
       }
     }
  
     // print the constructed distance array
     printSolution(dist, graph.size());
     cerr << "sdf " << dist[graph.size()-1];
     return dist[graph.size()-1];
}
  
// driver program to test above function
/*
int main()
{
   int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
} */

// Complete the leastTimeToInterview function below.
long leastTimeToInterview(int n, int k, int m) {
    // Return the least amount of time needed to reach the interview location in seconds.
    vector<vector<int>> gr(n, vector<int>(n));
    for(int i = 0; i < m; i++) 
    {
      int s, d, t;
      cin >> s >> d >> t;
      gr[s-1][d-1] = t;
      gr[d-1][s-1] = t;
    }
    return dijkstra(gr,0, k);
     
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = leastTimeToInterview(n, k, m);

    fout << result << "\n";

    fout.close();

    return 0;
}