#include <vector>
#include <iostream>

using namespace std;

class Gr {
    public:
    int n;
    vector<vector<int>>  adj;
    vector<bool> v;
    Gr(int _n) {
        n = _n;
        adj = vector<vector<int>>(n+1, vector<int> (n+1, 0 ));
        /*
        for (int i = 0 ; i < n ; i ++) {
            adj.push_back(vector<int>(0));
        }*/
        v = vector<bool>(n, false);
    }
    void insert(int u, int v, int r) {
       // cerr << u << ":" << v<<endl;
        adj[u][v] =  r ;
        adj[v][u] =  r ;
    }
    void clear() {
       // cerr << "clear" << endl;
        v = vector<bool>(n, false);
    }
    /*
    int dfs(int s, int & l, int w, int from) {
        //l ;
        this->v[s] = true;
        for (int i = 0; i < adj[s].size(); i ++) {
         if ( !this->v[adj[s][i].first]) {
             
            int l2 =  l + adj[s][i].second;
             cerr << l2 << endl;
            dfs(adj[s][i].first, l2, adj[s][i].second, s);
             //cerr << adj[s][i] << " ";
         } else   {
             cerr << l - w << " w " << w << endl;
             if (from != adj[s][i].first) {
                if (l - w == w )
                    return 0;
                else
                    return 1;
             } else {
                 continue;
             }
         }
        }
        return 0;
    } */
};
int printSolution(vector<int> dist, int n);
int minDistance(vector<int> dist, vector<bool> sptSet)
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < dist.size(); v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation

vector<int> dijkstra(vector<vector<int>> graph, int src)
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
     for (int count = 0; count < graph.size() - 1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in the first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < graph.size(); v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
    // printSolution(dist, graph.size());
     return dist;
}

// A utility function to print the constructed distance array
int printSolution(vector<int> dist, int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < n; i++)
      printf("%d tt %d\n", i, dist[i]);
    return 0;
}
  
int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int tt; 
    cin >> tt;
    for (int t = 0 ; t < tt ; t ++) 
    {
        int n;
        cin >> n;

        int m;
        cin >> m;

        Gr g = Gr(n);

        vector<vector<int>> v (m, vector<int>(3));
        for (int i = 0; i < m; i++) {
            int l, j , k;
            cin >>  l ;
            cin >> j;
            cin >> k; v[i].push_back(l);
            v[i].push_back(j);v[i].push_back(k);
            g.insert(l, j, k);
        }
        bool possible = true;
        for (int i = 1 ; i < n +1 ; i ++) {
          auto dist =  dijkstra( g.adj, i);
            for (int j = 1 ; j < n +1 ; j ++) {
                if (i != j)
                 if (dist[j]  != INT_MAX && g.adj[i][j] != 0 ) {
                    if (dist[j] != g.adj[i][j]) {
                        //cerr << i << " " << j << " " << dist[j] << " " <<  g.adj[i][j];
                        possible = false ;
                        break;
                    } else {
                        int tmp = g.adj[i][j];
                        g.adj[i][j] = 0;
                        g.adj[j][i] = 0;
                         auto dist2 =  dijkstra( g.adj, i);
                        if ( dist2[j] == tmp) {
                            continue;
                         } else {
                             g.adj[i][j] = tmp;
                            g.adj[j][i] = tmp;
                         }
                    }
                 }
            }
            if (!possible)
                break ;
        }
        cout << "Case #" << (t + 1) <<  ": ";
        if (!possible) {
            cout << "Impossible\n";
        } else {
            int le = 0;
            for (int i = 0; i < g.adj.size(); i++ ) {
                for (int j = i + 1 ; j < g.adj.size(); j++ ) {
                    if (g.adj[i][j] > 0) 
                         le++;
                }
            }
            cout << le << endl;
            for (int i = 0; i < g.adj.size(); i++ ) {
                for (int j = i + 1 ; j < g.adj.size(); j++ ) {
                    if (g.adj[i][j] > 0) 
                         cout << i << " " << j  << " " << g.adj[i][j] << endl;
                }
            }
        }
    }


    return 0;
}

