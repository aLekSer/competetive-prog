#include <vector>
#include <iostream>
using namespace std;

//g++ ./rivers.cpp  -std=c++14 -o ./rivers
class Node {
	public:
	Node () {
		for (int i = 0 ; i < 4 ; i ++) {
			n[i] = NULL;
		}
	}
	Node * n[4];
	int v;
};
vector<vector<Node *> > n;
void addNodes(int i , int j,	vector<vector<int> > & m  ) {
		Node* a = n[i][j];
	a->v = m[i][j];
	if (i - 1 >=0 )
	{
		a->n[0] = n[i-1][j];
	}
	if(j - 1 >= 0)
	{
		a->n[1] = n[i][j-1];
	}
	if (i + 1 < m.size() )
	{
		a->n[2] = n[i+1][j];
	}
	if (j + 1 < m[0].size() )
	{
		a->n[3] = n[i][j+1];
	}
}
int dfs (Node * n , int s) {
	if ( n == NULL)
		return s;
	
	if (n->v == 1)
	{
		
		n->v = 2;
		s ++;
		cout <<" s " << s << endl;
		for ( int i = 0; i < 4; i++) {
			s = dfs(n->n[i], s);
		}
		
	}
	
	n->v = 2;
	return s ;
}
vector<int> riverSizes(vector<vector<int> > matrix) {
			cout << "1";
	vector<vector<int> > & m = matrix;
	n = vector<vector<Node *> >(m.size(), vector<Node *>(m[0].size()));
			cout << "2";
	for (int i = 0 ; i < m.size(); i ++ ) {
		for (int j = 0 ; j < m[0].size(); j ++ ) {
			n[i][j] = new Node;
			cout << "3";
		}
	}
	for (int i = 0 ; i < m.size(); i ++ ) {
		for (int j = 0 ; j < m[0].size(); j ++ ) {
			addNodes(i, j, m);
		}
	}
	vector<int> v ;
	for (int i = 0 ; i < m.size(); i ++ ) {
		for (int j = 0 ; j < m[0].size(); j ++ ) {
	     int k = dfs(n[i][j], 0);
			if ( k != 0 ) {
				cout << k << endl;
				v.push_back(k);
			}
		}
	}
	return v;
  // Write your code here.
}

int main () {
    vector<vector<int> > testInput {
      {1, 0, 0, 1},
      {1, 0, 1, 0},
      {0, 0, 1, 0},
      {1, 0, 1, 0},
    };
    vector<int> expected {1, 1, 2, 3};

    vector<int> output = riverSizes(testInput);
	for ( int i = 0 ; i < output.size(); i ++ ) {
		cout << output[i] << " " ;
	}
}