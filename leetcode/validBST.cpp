// 98. Validate Binary Search Tree
// Note that properties of a tree are:
// All nodes in the left subtree are strictly less than node
// All nodes in the right subtree are more than current node val

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    long long m = (long long)INT_MIN - 5ll;
    bool valid(TreeNode * root ) {
        if (root == NULL)
            return true; 
        bool ans = true;
        ans = ans && valid(root->left);
        if (m >= (long long)root->val) {
            return false;
        }
        m = root->val;
        ans = ans && valid(root->right);
        return ans;
    }
public:
    bool isValidBST(TreeNode* root) {
        return valid(root);
        
    }
};
