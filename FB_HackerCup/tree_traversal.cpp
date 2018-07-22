#include <vector>
#include <iostream>
//#include <string>
//#include <algorithm>
//#include <sstream>

using namespace std;

//contains() function
//

bool algo(string a, string b) {
	int i = 0, j = 0;
	while ( true ) {
		if (i == a.length()) 
			return true;
		if (j == b.length() )
			return false;
		if (a[i] == b[j] ) 
		{
			//cerr<<"a"<<a[i]<<endl;
			//cerr<<"b"<<b[j]<<endl;
			i++; j ++;
			//cerr << i << endl; 
			continue;

		}
		if (i == 0) {
			j++;
			continue;
		}
		i = 0;
	}
	return false;
}

string getB(string a) {
	int found = false;
	for (int i = 1; i < a.length(); i++) {
		if (a[0] == a[i]) {
			found = true;
			for (int j = 1; j < a.length() - i; j ++) {
				if (a[j] != a[i + j]) {
					//cerr << i << " " << j;	
					return a.substr(0, i) + a;
				}
			}
		}
	}
	return "";
}

struct Node
{
    int data;
    int label;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    cout << node->data << " ";
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    cout << node->data << " ";
 
    /* then recur on left sutree */
    printPreorder(node->left); 
 
    /* now recur on right subtree */
    printPreorder(node->right);
} 
void printPreorder(struct Node* node, vector<int> & v)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    v.push_back(node->data);
 
    /* then recur on left sutree */
    printPreorder(node->left, v); 
 
    /* now recur on right subtree */
    printPreorder(node->right, v);
} 
void printPostorder(struct Node* node, vector<int> & v)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left, v);
 
    // then recur on right subtree
    printPostorder(node->right , v);
 
    // now deal with the node
    v.push_back(node->data);
}
 
 
int main() {
	int t ;
	cin >> t;
	for (int i = 0; i < t ; i ++ ) {
        int n, k;
        cin >> n >> k;
		cout << "Case #" << i + 1<<  ": ";
		//cout << a << endl;
        Node * root = new Node(1);
        vector<Node *> vert(n);
        vert[0] = root;
        for(int i = 1; i < n; i ++) {
            vert[i] = new Node(i + 1);
        }
        for (int i =0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (a != 0) {
                vert[i]->left = vert[a-1];
            }
            if (b != 0) {
                vert[i]->right = vert[b-1];
            }
        }
        /*
        printPreorder(root);
        cout << endl;
        printPostorder(root);
        cout << endl;*/
        vector<int> pre, post;
        printPreorder(root, pre);
        printPostorder(root, post);
        cerr << "Pre";
        for (int i =0; i < pre.size(); i++) {
            cerr << pre[i] << " ";
        }
         cerr << endl;
        cerr << "Post";
        for (int i =0; i < post.size(); i++) {
            cerr << post[i] << " ";
        }
         cerr << endl;
        
 		//std::size_t found = b.find(a);
		//cout <<  "Check " << ((b == "" && found == string::npos) || (b != "" && found != string::npos) )<< endl;
	}
	return 0;
}
