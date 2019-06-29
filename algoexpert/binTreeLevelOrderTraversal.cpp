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
        queue<pair<int , TreeNode*>> q;
    void levelO( TreeNode* root, int lvl) {
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int lvl = 0;
      // levelO(root, lvl);
        vector<vector<int>> res;
        if (root == NULL) {
            return  res;
        }
        vector<int> cur;
        q.push(make_pair(0, root));
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p.second == NULL) 
                    continue;
            q.push(make_pair(p.first+ 1, p.second->left ));
            q.push(make_pair(p.first+ 1, p.second->right ));
            if (p.first > lvl) {
                lvl ++;
                res.push_back(cur);
                cur = vector<int>();
            }
            cur.push_back(p.second->val);
        }
                
        res.push_back(cur);
        return res;
    }
};