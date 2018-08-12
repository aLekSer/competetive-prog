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
#define FINISHED -1
#define NOCYCLE -2
class Graph
{
     
    // No. of vertices 
    // in graph
public:
int index;
    int V; 
    list<int> *adj;
    vector<int> path;
    vector<int> path2;
    int back_idx;
    vector<int> parnt;
    void set_index();
    void 
printCycle(int v, int u) {
  if (v==u) 
    path2.push_back(v);
     
  else {
    path2.push_back(v);
     printCycle(parnt[v], u);
      
  }
     }

int isCyclicUtil(int v, bool visited[], int *cycleVertices, int parent);
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
    this->index = 0;
}

void Graph::set_index()
{
    this->index = 0;
}
void Graph::addEdge(int u, int v)
{
     
    // Add v to u’s list.
    adj[u].push_back(v); 
    adj[v].push_back(u); 
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

int Graph::isCyclicUtil(int v, bool visited[], int *cycleVertices, int parent)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            int result = isCyclicUtil(*i, visited, cycleVertices, v);
            if (result == FINISHED)
                return FINISHED;
            else if (result != NOCYCLE) {
                cycleVertices[index++] = *i;
                if (result == v)
                    return FINISHED;
                else
                    return result;
            }
        }

        else if (*i != parent) {
                cycleVertices[index++] = *i;

                //cycleVertices[index++] = *i;
            return *i;
        }
    }
    return NOCYCLE;
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
    int cycleVertices[4];
    for (int u = 0; u < V; u++)
        if (!visited[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u, visited, cycleVertices, -1)) 
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
        //int *cycleVertices = new int[n];
        int cycleVertices[10];
        for (int i = 0; i <n; i++)
            cycleVertices[i] = -1;
        vector<pair<int, int>> e;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
            e.push_back(make_pair(u, v));
        }
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++)
            visited[i] = false;
        g.isCyclicUtil(3, visited, cycleVertices, -1) ? cerr << "Graph contains cycle\n" :
            cerr << "Graph doesn't contain cycle\n";
        int x = 0;
        while (cycleVertices[x] != -1)
            cerr << cycleVertices[x++] << " ";
       // cerr << g.isCyclicUtil() << endl;

        for( vector<int>::iterator it = g.path.begin(); it != g.path.end(); it ++) {
            cerr << *it << "  : ";
        }
        cerr << "New ine" << endl;
       // g.printCycle(g.back_idx, g.parnt[g.back_idx]);
        cerr << endl;
        for (int i = 0; i < m; i ++) {
            int res = g.countPaths(e[i].first, n, e[i]);
            cout << res << endl;
        }

    }
    /*
    */
    return 0;
}
