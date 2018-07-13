#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>

//PDELIV

using namespace std;
const int mod = 1000000007;
typedef long long  ll; 

class Graph
{
    int V;    // No. of vertices
	int size ;
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], int parent, int size);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic(int n);   // returns true if there is a cycle
	int getSize() {
		return size;
	}
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v-1].push_back(w-1); // Add w to v’s list.
    adj[w-1].push_back(v-1); // Add v to w’s list.
}
bool Graph::isCyclicUtil(int v, bool visited[], int parent, int a_size)
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
           if (isCyclicUtil(*i, visited, v, a_size + 1)) {
				size  =  a_size + 1;
			   cerr <<  "path " <<  *i;
              return true;
		   }
        }
 
        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent) {
			size  =  a_size + 1;
           return true;

		}
    }
    return false;
}
 
// Returns true if the graph contains a cycle starting from node n (1 to N), else false.
bool Graph::isCyclic(int n)
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
	size = 1;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    //My change to support starting from one node
	//for (int u = 0; u < V; u++)
        if (!visited[n-1]) // Don't recur for u if it is already visited
          if (isCyclicUtil(n-1, visited, -1, size))
             return true;
 
    return false;
}
int main()
{
	int n = 0, m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> c(m), k(m);
	//vector<set<int>> g(n, set<int>());
	Graph g(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int t; 
	int x;
	int y;
	int v;
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			cin >> y;
			a[x] = y;
		} else if (t == 2) {
			cin >> x;
			cin >> y;	
			cerr << "Adding edge " << x << " " << y;
			//g[x].insert(y);		
			g.addEdge(x, y);
		} else if (t == 3) {
			cin >> x;
			cin >> y;
			cin >> v;
			if (g.isCyclic(x)) {
				int s = g.getSize();
					cerr << "Number" << i<< ": " <<  s << endl;
				if ((s + 1) % 2 == 1 ) {
					cout << 0 << endl;
				} else {
					cout << 1 << endl;
				}
			}
		}
		
	}

	cerr << "ASDD";
	/*
	for (int i = 0; i < m; i++) {
		long long min = 9223372036854775807;
		for (int j = 0; j < n; j++) {
			if (un[i].find(j) != un[i].end())
				continue;
			long long cur = (c[i] - s[j] )* (c[i] - s[j] ) + p[j];
				if (cur < min)
					min = cur;
		}
		cout << min << endl;
	}*/
}

