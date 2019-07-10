#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canGo(int i , int j, vector<vector<char>> b) {
        //printf()
        bool b1 =  (i >= 0 && j >= 0 && (i < b.size() ) && (j < b[0].size())) ;
        //printf("%d bool ", b1);
        return b1;
    }
    bool search(vector<vector<char>> & board, int x , int y , string& word, int i) {
        if (i == word.length()) {
            return true;
        }
       // printf("%d\n" , i );
        bool b = false;
        vector<vector<int>> v {{0, 1}, {1,0 } , {-1, 0}, {0, -1}};
        for (auto e : v) {
           // printf("%d %d w %c  %c \n",x+e[0], y+e[1],  board[x+e[0]][y+e[1]], word[i] );
            if (canGo (x +e[0], y + e[1], board)) {
                    //printf("%d %d new \n",x+e[0], y+e[1] );
                if (word[i] == board[x+e[0]][y+e[1]]) {
                   // printf("%d %d new \n",x+e[0], y+e[1] );
                        char c = board[x][y];
                    board[x][y] = '.';
                     b |= search(board, x+e[0], y+e[1], word, i +1) ;
                    board[x][y] = c;  
                    if (b == true ) 
                        return true;
                }
            }
        }
        return b;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool b = false;
        for (int i = 0; i < board.size(); i ++ ) {
            for (int j = 0; j < board[0].size(); j ++ ) {
                if (board[i][j] == word[0]) {
                    b = search(board, i, j , word, 1);
                    if (b)
                        return b;
                }
            }
        }
        return b;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        bool b = false;
        vector<string> w;
        for (int k = 0 ; k < words.size(); k ++ ) {
            for (int i = 0; i < board.size(); i ++ ) {
                bool br = false;
                for (int j = 0; j < board[0].size(); j ++ ) {
                    if (board[i][j] == words[k][0]) {
                        b = search(board, i, j , words[k], 1);
                        if (b) {
                            w.push_back(words[k]);
                            br = true;
                            break;
                        }
                    }
                }
                    if (br)
                        break;
            }
        }
        return w;
        
    }
};

int main() {
    Solution s;
    vector<vector<char>> v {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    bool b = s.exist(v, "ABCCED");
    printf("\n\n %d \n", b );
    return 0;
}