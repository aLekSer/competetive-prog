#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>
# include <algorithm>

using namespace std;

typedef __uint128_t ll ;

std::ostream&
operator<<( std::ostream& dest, ll value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        ll tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
using namespace std;
 
// Class to represent a graph
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
        cerr << Stack.top() << " ";
        v.push_back(Stack.top());
        Stack.pop();
    }
}
int algo2(const vector<int> & b, int k, Graph &g, Graph &g2) {
    int n = b.size();
    for (int i = 0; i < b.size(); i++) {
        for( int j = max(0, i -k); j < min(n, i+k); j++ ) {
            if(b[j] < b[i]) {
                g.addEdge(i, j);
                g2.addEdge( j, i);
            }
        }
    }

}
int algo(const vector<int> & b, int k) {
    // find 0es - set them to 1
    vector<int> c(b.size(), 1000000);
    vector<pair<int, int>> st;
    for (int i = 0; i < b.size(); i++) {
        st.push_back(make_pair(b[i], i));
    }
    int N = b.size();
    sort(st.begin(), st.end());
    int prev = 0;
    for (int i = 0; i < st.size(); i++) {
        cerr << "st" << st[i].first << " " << st[i].second;
        if (st[i].first == 0) {
            c[st[i].second] = 1;
            prev = 1;
        } else {
            //TODO
            bool found = false;
                int cur_m = 100000;
            for (int l = 2; l < 100; l ++) {
                c[st[i].second] = l;
                int j = st[i].second;
                int count = 0;
                for (int ii = max(0, j-k); ii <= min(N-1, j+k); ii ++) {
                    if (c[ii] < c[j]) {
                        count ++;
                        cerr << "++" ;
                    }
                    if (ii != j && c[ii] < cur_m) {
                        cur_m = c[ii];
                    }
                }
                if (count == st[i].first) {
                    found = true;
                    prev = l;
                    break;
                }
            }
            if (!found) {
                if (cur_m == 100000) {
                    cur_m = 1;
                }
                c[st[i].second] = cur_m + 2;
                
            }
            
        }
    }
    
    long long sum_of_elems = 0;
    cerr << "My elems:" << endl;
    for (auto& n : c) {
        cerr << n << " ";
        sum_of_elems += n;
    }
    cerr << endl;
    return sum_of_elems;

}
// gcd (a, b) == gcd( (a^N)% b, b)
int prepare(const vector<int> & a, int s) {
    vector<int> b = a;
    const int n = a.size();
    int sum = 0;

    // i is k itself
    int k = 0;
    for (int i = 1; i < n; i ++) {
        Graph g(n);
        Graph g2(n);
        algo2(b, i, g, g2);
        vector<int> c;
        g.topologicalSort(c);
        cerr << endl << i << endl;
        vector<int> r(n);
        for (int j = 0; j < c.size(); j++) {
            if (g2.adj[c[j]].size() == 0) {
                r[c[j]] = 1;
            } else {
                int max = 0;
                // Set the level value of the node to the max(parents) + 1
                for (list<int>::iterator it = g2.adj[c[j]].begin(); it != g2.adj[c[j]].end(); it++  ) {
                    if (r[*it] > max) {
                        max = r[*it];
                    }
                }
                r[c[j]] = max + 1;
            }
                        
        }
        cerr << " Max : ";


        int sum = 0;
        for (int j = 0; j < c.size(); j++) {
            cerr << r[j] << " ";
            sum += r[j];

        }
        if (sum <= s) {
            k = i;
        }
        cerr << endl;
    }
    cout << k + 1 << " a " << endl;
    return 0;
    for (int j = 0; j < n; j++) {
        sum += a[j];        
    }
    if (sum < s) {
        return n;
    }
    vector<int> c(n, -1);
    int mid = 10000;
    //vector<int>  b (n);
    int k_m;
    for (int k = 1; k < n; k ++) {
            int mi = mid * 2;
            cerr << "K " << k;
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = max(0, j-k); i <= min(n-1, j+k); i ++) {
                if (a[i] < a[j]) {
                    count ++;
                    cerr << "++" ;
                }
            }
            b[j] = count;
            /*
            if (c[j] == -1)
                c[j] = mid;
            for (int i = max(0, j-k); i < j; i ++)
            {
                if (c[i] < c[j]) {
                    count --;
                }
            }
            for (int i = j+1 ; i <  min(n, j+k); i ++) {
                if (i != j) {
                    if (count > 0) {
                        c[i] = c[j] - 1;
                        count --;
                    } else {
                        c[i] = c[j];
                    }
                    if (c[i] < mi) {
                        mi = c[i];
                    }
                }
            }
            */
        }
        //auto siz = algo(b, k);
        /*
        if (siz <= s) {
            cerr << "Here " <<endl;

        } else {
            //TODO check do we have other K after one fail
            k_m = k;
            break;

        }
        */
        
    }
    return k_m;
}
int main() 
{
    int t;
    cin >> t;
    for (int i = 0; i < t ; i++) {
        long long  n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        cout << (long long ) prepare(a, s) << endl;
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
        
*/

