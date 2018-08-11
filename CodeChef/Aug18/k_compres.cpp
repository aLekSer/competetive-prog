#include <iostream>
#include <vector>

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack>
using namespace std;
 


// A C++ program to print topological sorting of a DAG
// Class to represent a graph
typedef  long long ll;
class Graph
{
    int V;    // No. of vertices'
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    // Pointer to an array containing adjacency listsList
    list<int> *adj;
 
    Graph(int V);   // Constructor
 
     // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of the complete graph
    void topologicalSort(vector<int> & v);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], 
                                stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack which stores result
    Stack.push(v);
}

// The function to do Topological Sort. It uses recursive 
// topologicalSortUtil()
void Graph::topologicalSort(vector<int> & v)
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false)
    {
        //cerr << Stack.top() << " ";
        v.push_back(Stack.top());
        Stack.pop();
    }
}
int algo2(const vector<ll> & b, int k, Graph &g, Graph &g2) {
    int n = b.size();
    for (int i = 0; i < b.size(); i++) {
        for( int j = max(0, i -k); j < min(n, i+k +1); j++ ) {
            if(b[j] <= b[i]) {
                g.addEdge(i, j);
                g2.addEdge( j, i);
            }
        }
    }

}

// gcd (a, b) == gcd( (a^N)% b, b)
int prepare(const vector<ll> & a, ll s) {
    //vector<int> b = a;
    const int n = a.size();
    ll sum = 0;

    // i is k itself
    int k = 0;
    // TODO: add binary search of k over 0 : n
    for (int i = 0; i <= n; i ++) {
        Graph g(n);
        Graph g2(n);
        algo2(a, i, g, g2);
        vector<int> c;
        g.topologicalSort(c);
        //cerr << endl << i << endl;
        vector<ll> r(n);
        for (int j = 0; j < c.size(); j++) {
            if (g2.adj[c[j]].size() == 0) {
                r[c[j]] = 1;
            } else {
                ll max = 0;
                // Set the level value of the node to the max(parents) + 1
                for (list<int>::iterator it = g2.adj[c[j]].begin(); it != g2.adj[c[j]].end(); it++  ) {
                    if (r[*it] > max) {
                        max = r[*it];
                    }
                }
                r[c[j]] = max + 1;
            }
                        
        }
       // cerr << " Max : " << i;


        ll sum = 0;
        for (int j = 0; j < c.size(); j++) {
            //cerr << r[j] << " ";
            sum += r[j];

        }
        if (sum <= s) {
            k++;
        }
        //cerr << endl;
    }
    //cout << k + 1  << endl ;// << " a " << endl;
    return k ;
}
int main() 
{
    int t;
    cin >> t;
    for (int i = 0; i < t ; i++) {
        long long  n, s;
        cin >> n >> s;
        vector<ll> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        //prepare(a, s) ;
        cout <<  prepare(a, s) << endl;
       // cout.flush();
    }
    return 0;
}

//Some test cases
/*
./mod
1
1999999 1999999 1999994
output: 0 ?


Considerations how we can solve the problem:
    First of all lets solve it on the paper:
        4 2 8 1 4 3 8 1
        Sol for k = 2
        3 2 4 1 3 2 4 1 
        Sol for k = 3
        3 2 4 1 3 2 4 1
        Why we could not do that for k = 4
        4 2 5 1 4 3 5 1 Sum > 20

        Suggested algo:
        start with calculating the number of X the elements < ai
        for example for k = 3:
        2 1 5 0 3 2 4 0

        We could start from 0 to 5
        and then we put 1 for 0,
        2, iterating to valid number for 1
        the same for each other number starting from value = 2 

        Found error:
        ./kc
1 2 2
2 1
 Max : 01 1
 Max : 11 1
 Max : 21 2
2

        
*/

