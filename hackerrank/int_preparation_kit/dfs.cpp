#include <bits/stdc++.h>

using namespace std;

class Gr {
    public:
    int n;
    vector<vector<int>> adj;
    vector<bool> v;
    Gr(int _n) {
        n = _n;
        adj = vector<vector<int>>(n, vector<int>());
        v = vector<bool>(n, false);
    }
    void insert(int u, int v) {
        cerr << u << ":" << v<<endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void clear() {
        cerr << "clear" << endl;
        v = vector<bool>(n, false);
    }
    int dfs(int s, int & l) {
            
           // return 0;
        
        l ++;
        this->v[s] = true;
        for (int i = 0; i < adj[s].size(); i ++) {
         if ( !this->v[adj[s][i]]) {
            dfs(adj[s][i], l);
             cerr << adj[s][i] << " ";
             
         }
        }
        return 0;
    }
};
int gr(vector<vector<int>> grid, int i , int j) {
    if (i < grid.size() && i >= 0 && j >= 0 && j < grid[0].size())
        return grid[i][j];
    else return 0;
}
// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
    Gr g(grid[0].size()*grid.size());
    int n = grid[0].size();
    for (int i = 0; i < grid.size() ; i ++) {
        for (int j = 0; j < grid[0].size() ;  j ++) {
            if (gr(grid, i , j)) {
                int u = i * n + j;
                if (gr(grid, i-1,j)) {
                    int v = (i-1)*n + j;
                    g.insert(u,v );
                }
                if (gr(grid, i+1,j)) {
                    int v = (i+1)*n + j;
                    g.insert(u,v );
                }
                if (gr(grid, i,j-1)) {
                    int v = (i)*n + j-1;
                    g.insert(u,v );
                }
                if (gr(grid, i,j+1)) {
                    int v = (i)*n + j+1;
                    cerr << v << " v " << endl;
                    g.insert(u,v );
                }
                if (gr(grid, i-1,j-1)) {
                    int v = (i-1)*n + j-1;
                    g.insert(u,v );
                }
                if (gr(grid, i-1,j+1)) {
                    int v = (i-1)*n + j+1;
                    g.insert(u,v );
                }
                if (gr(grid, i+1,j-1)) {
                    int v = (i+1)*n + j-1;
                    g.insert(u,v );
                }
                if (gr(grid, i+1,j+1)) {
                    int v = (i+1)*n + j+1;
                    g.insert(u,v );
                }
            }
        }        
    }
    int max = 0;
    for (int i = 0; i < grid.size() ; i ++) {
        for (int j = 0; j < grid[0].size() ;  j ++) {
            int l = 1; g.clear() ;
            g.dfs(i*n+j, l);
            int tot = 0;
            for (int i = 0; i < g.n; i++) {
                //cerr << g.n << endl;
                if (g.v[i]) 
                    tot ++;
            }
            if (tot > max ) {
                max = tot;
            }
        }
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}

