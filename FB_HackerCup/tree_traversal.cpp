#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <list>
#include <map>
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
 /*
void preorder(struct Node* node, vector<int> & v)
{
    if (node == NULL)
        return;
 
    /* first print data of node 
    Node * node1;
    Node * node2;
    while (v.size() != N) {
        v.push_back(node->data);

        /* then recur on left sutree 
        node = node->left;

        /* now recur on right subtree 
        node = node->right;

    }
} */
//iterativePreorder
void preorder(Node *root, vector<int> & v)
{
    // Base Case
    if (root == NULL)
       return;
 
    // Create an empty stack and push root to it
    stack<Node *> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false)
    {
        // Pop the top item from stack and print it
        struct Node *node = nodeStack.top();
        v.push_back(node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}
void postorder(Node *root, vector<int> & v)
{
    // Base Case
    if (root == NULL)
       return;
    std::stack<Node*> leftStack;
    std::stack<Node*> rightStack;

    Node* currentNode = root;
    while( !leftStack.empty() || currentNode != NULL )
    {
        if( currentNode )
        {
            leftStack.push( currentNode );
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = leftStack.top();
            leftStack.pop();

            rightStack.push( currentNode );
            currentNode = currentNode->right;
        }
    }

    while( !rightStack.empty() )
    {
        currentNode = rightStack.top();
        rightStack.pop();

        v.push_back(currentNode->data);
    }
}
void postOrderTraversal(Node* root, vector<int> & v)
{
    if(root == NULL)
        return;

    stack<Node*> st;
    st.push(root);

    //store most recent 'visited' node
    Node* prev=root;

    while(st.size() > 0)
    {
        Node* top = st.top();
        if((top->left == NULL && top->right == NULL))
        {
            prev = top;
            v.push_back(top->data);
            st.pop();
            continue;
        }
        else
        {
            //we can check if we are going back up the tree if the current
            //node has a left or right child that was previously outputted
            if((top->left == prev) || (top->right== prev))
            {
                prev = top;
                v.push_back(top->data);
                st.pop();
                continue;
            }

            if(top->right != NULL)
                st.push(top->right);

            if(top->left != NULL)
                st.push(top->left);
        }
    }
}
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<int> *adj;
 
    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
    void connectedComponents();
};
 
// Method to print connected components in an
// undirected graph
void Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;
 
    cerr << "connectedCommponents";
    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
            // print all reachable vertices
            // from v
            DFSUtil(v, visited);
 
            cerr << "\n";
        }
    }
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cerr << v << " ";
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
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
        //vector<int> pre, post;
        vector<int> pre2, post2;
        /*
        printPreorder(root, pre);
        printPostorder(root, post);
        cerr << "Pre";
        for (int i =0; i < pre.size(); i++) {
            cerr << pre[i] << " ";
        }
         cerr << endl;
        cerr << "Post ";
        for (int i =0; i < post.size(); i++) {
            cerr << post[i] << " ";
        }
         cerr << endl;
        */
        preorder(root, pre2);
        //postorder(root, post2);
        postOrderTraversal(root, post2);
        cerr << "Pre2";
        for (int i =0; i < pre2.size(); i++) {
            cerr << pre2[i] << " ";
        }
         cerr << endl;
        cerr << "Post2  ";
        for (int i =0; i < post2.size(); i++) {
            cerr << post2[i] << " ";
        }
         cerr << endl;
         //Missmatched vertices
         int mism = 0;
         set<int> s;
         vector<int> su(n, -1);
         vector<set<int>> v;
         Graph g(n);
        for (int i = 0 ; i < min(pre2.size(), post2.size()); i ++) {
            if (pre2[i] != post2[i]) {
                g.addEdge(pre2[i], post2[i]);
                mism ++;
            }
        }
        g.connectedComponents();
 		//std::size_t found = b.find(a);
		//cout <<  "Check " << ((b == "" && found == string::npos) || (b != "" && found != string::npos) )<< endl;
	}
	return 0;
}
