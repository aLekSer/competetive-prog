// CPP program to check if two  
// numbers are co-prime or not 
#include<bits/stdc++.h> 
using namespace std; 
  
// function to check and print if  
// two numbers are co-prime or not  
bool coprime(int a, int b) { 
      
    return ( __gcd(a, b) == 1);
}
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<int> *adj;
 
    // A function used by DFS
    void DFSUtil(int v, bool visited[], vector<int> & a);
    void DFS(int s,bool visited[], vector<int> & a);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
    void connectedComponents(vector<vector<int>> & v);
};
 
// Method to print connected components in an
// undirected graph
void Graph::connectedComponents(vector<vector<int>> & v2)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;
 
    //cerr << "connectedComponenDFS(int s,bool visited[])ts";
    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
            vector<int> a;
            // print all reachable vertices
            // from v
           // DFSUtil(v, visited, a);
            DFS(v, visited, a);
            v2.push_back(a);
 
            //cerr << "\n";
        }
    }
}
 
void Graph::DFSUtil(int v, bool visited[], vector<int> & a )
{
    // Mark the current node as visited and print it
    visited[v] = true;
    //cerr << v << " ";
    a.push_back(v);
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited , a);
}
 void Graph::DFS(int s,bool visited[], vector<int> & a)
{
    // Initially mark all verices as not visited
    //vector<bool> visited(V, false);
 
    // Create a stack for DFS
    stack<int> stack;
 
    // Push the current source node.
    stack.push(s);
 
    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();
 
        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
            a.push_back(s);
            visited[s] = true;
        }
 
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then puah it
        // to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// driver code 
int main() 
{ 
    int n;
    cin >> n;
    vector<int> v(n);
    for ( auto &i : (v))
    {
        cin >> i;
    }
    Graph g(n);    
    for (int i = 0 ; i < v.size( ) ; i++)
    {
        for (int j = i; j < v.size() ; j ++ ) {
            if (coprime(v[i], v[j]))
                g.addEdge(i, j);
        }
    }
    vector<vector<int>> v2;
    g.connectedComponents(v2);
    cout << v2.size();
    return 0; 
} 
