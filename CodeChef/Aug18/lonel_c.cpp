#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>
# include <algorithm>

using namespace std;

//g++ -o ./pr -g ./princ_dr.cpp

bool comp(int a , int b)
{
    return a > b;
}
const long long mod = 1000000007;// C++ program to count all
// paths from a source
// to a destination.
#include<bits/stdc++.h>
using namespace std;
 
// A directed graph using
// adjacency list
// representation
class Graph
{
     
    // No. of vertices 
    // in graph
public:
    int V; 
    list<int> *adj;

bool isCyclicUtil(int v, bool visited[], int parent);
bool  isCyclic();
    // A recursive function
    // used by countPaths()
    void countPathsUtil(int, int, 
                        bool [],
                        int &,  pair<int, int> e);
    void countPathsUtil(int, int, 
                        bool [],
                        int &);
 
 
    // Constructor
    Graph(int V); 
    void addEdge(int u, int v);
    int countPaths(int s, int d, pair<int, int> e);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
     
    // Add v to u’s list.
    adj[u].push_back(v); 
}
 
// Returns count of
// paths from 's' to 'd'
int Graph::countPaths(int s, int d, pair<int, int> e)
{
     
    // Mark all the vertices
    // as not visited
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));
 
    // Call the recursive helper
    // function to print
    // all paths
    int pathCount = 0;
    countPathsUtil(s, d, visited, pathCount, e);
    return pathCount;
}
 
// A recursive function to 
// print all paths from
// 'u' to 'd'. visited[] 
// keeps track of vertices
// in current path. path[] , pair<int, int> e
// stores actual vertices
// and path_index is current 
// index in path[]
void Graph::countPathsUtil(int u, int d, 
                           bool visited[],
                           int &pathCount, pair<int, int> e)
{
    visited[u] = true;
 
    // If current vertex is 
    // same as destination, 
    // then increment count
   // if (u == d)
        pathCount++;
 
    // If current vertex 
    // is not destination
    //else
    {
        // Recur for all the 
        // vertices adjacent to
        // current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != 
                    adj[u].end(); ++i)
                    {
                        if (e.second == *i && !visited[*i])
                            countPathsUtil(*i, d, visited,
                                                pathCount);
                        
                    }
    }
 
    visited[u] = false;
}
void Graph::countPathsUtil(int u, int d, 
                           bool visited[],
                           int &pathCount)
{
    visited[u] = true;
 
    // If current vertex is 
    // same as destination, 
    // then increment count
  //  if (u == d)
        pathCount++;
 
    // If current vertex 
    // is not destination
   // else
    {
        // Recur for all the 
        // vertices adjacent to
        // current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != 
                    adj[u].end(); ++i)
            if (!visited[*i])
                countPathsUtil(*i, d, visited,
                                    pathCount);
    }
 
    visited[u] = false;
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }
 
        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
        if (!visited[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u, visited, -1))
             return true;
 
    return false;
}
int main() 
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t ; tt++) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        Graph g(n+1);
        vector<pair<int, int>> e;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
            e.push_back(make_pair(u, v));
        }
        for (int i = 0; i < m; i ++) {
            int res = g.countPaths(e[i].first, n, e[i]);
            cout << res << endl;
        }

    }
    /*
    Graph g2(n+1);
    vector<vector<int>> c(n, vector<int>(n));
        int mi = 1000000;
        int max = 0;
        vector<int> mm(n);
        vector<int> b(n);
    for (int i = n-1; i >= 0; i--) {
        if(v[i] < mi) {
            mi = v[i];
            mm[i] = v[i];
        } else {
            mm[i] = mi;
        }
        cerr << mm[i];
        if(v[i] > max) {
            max = v[i];
            b[i] = v[i];
        } else {
            b[i] = max;
        }
    }
    for (int i = 0; i < n; i++) {
        int mi = 1000000;
        int max = 0;
        for (int j = i; j < min(n, i + b[i]); j ++) {
            if (v[j] < mi) {
                mi = v[j];
            }
            if (v[j] > max) {
                max = v[j];
            }
            c[i][j] = int( mi <= ( j-i + 1) && ( j-i + 1) <=  max);
            if (c[i][j]) {
                g.addEdge(i,j+1);
                g2.addEdge(j+1, i);
            }
            prepare(c, v, i, j, g);
           // cerr << c[i][j];
        }
       // cerr << endl;
    }
    vector<long long> d(n+1, 0);
    d[n] = 1;

    // Aglorithm to calculate all paths in DAG (directed acyclic graph) with backtrace and reverse topology ordering
    for (int i = n ; i >= 0; i--) {
        for (list<int>::iterator it = g2.adj[i].begin(); it != g2.adj[i].end(); it ++ ) {
            d[*it] = (d[*it] + d[i]) % mod;
        }        
    }
    cout << d[0] << endl;
    //cout << g.countPaths(0, n) << endl;
    */
    return 0;
}
