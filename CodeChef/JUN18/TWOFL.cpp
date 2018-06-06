#include <iostream>
#include <vector>
using namespace std;
// A function to check if a given cell (row, col) can be included in DFS
int isSafe(vector<vector<int>>  M, int row, int col, vector<vector<bool>>& visited)
{
    // row number is in range, column number is in range and value is 1 
    // and not yet visited
    return (row >= 0) && (row < M.size()) &&     
           (col >= 0) && (col < M[0].size() ) &&      
           (M[row][col] && !visited[row][col]); 
}
 
// A utility function to do DFS for a 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
int DFS(vector<vector<int>>  M, int row, int col, vector<vector<bool>>& visited)
{
    // These arrays are used to get row and column numbers of 8 neighbours 
    // of a given cell
    static int rowNbr[] = { -1, 0, 0, 1};
    static int colNbr[] = { 0, -1, 1, 0};
 
    // Mark this cell as visited
    visited[row][col] = true;
 
    // Recur for all connected neighbours
    int count = 0;
    for (int k = 0; k < 4; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) ) {
           count = 1 + DFS(M, row + rowNbr[k], col + colNbr[k], visited); 
        }
    return count;
}
 
// The main function that returns count of maximal island in a given matrix
int countIslands(vector<vector<int>>  M)
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    vector<vector<bool>> visited(M[0].size(), vector<bool>(M.size()));
 
    // Initialize count as 0 and travese through the all cells of
    // given matrix
    int max_count = 0;
    for (int i = 0; i < M.size(); ++i)
        for (int j = 0; j < M[0].size(); ++j)
            if (M[i][j] && !visited[i][j]) // If a cell with value 1 is not
            {                         // visited yet, then new island found
                int count = DFS(M, i, j, visited) + 1;
                if (count > max_count)
                {
                    max_count = count;
                }
            }
 
    return max_count;
}
int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> v(n, vector<int>(m));
    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            v[i][j] = a;
        }
    }
    int res = 0;
    int maxRes = 0;
    // Make submatrises with only 2 flowers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            vector<vector<int>> d(n, vector<int>(m, 0));
            for (int l = 0; l < n; l++) {
                for (int g = 0; g < m; g++) {
                    if (v[l][g] == v[i][j] || v[l][g] == v[i][j+1] )
                        d[l][g] = v[i][j]; 
                }
                
            }
            res = countIslands(d) + 1;
            if (res > maxRes) {
                maxRes = res;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<int>> d(n, vector<int>(m, 0));
            for (int l = 0; l < n; l++) {
                for (int g = 0; g < m; g++) {
                    if (v[l][g] == v[i+1][j] || v[l][g] == v[i][j] )
                        d[l][g] = v[i][j]; 
                }
                
            }
            res = countIslands(d) + 1;
            if (res > maxRes) {
                maxRes = res;
            }
        }
    }
    cout << maxRes;
	// your code goes here
	return 0;
}
