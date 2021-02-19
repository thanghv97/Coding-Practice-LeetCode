/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> recursion(const int& begin, const int& end) {        
        if (begin >= end) {
            TreeNode* node = (begin == end) ? new TreeNode(begin) : nullptr;
            return {node};
        }
        
        vector<TreeNode*> rs;
        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> left = recursion(begin, i - 1);
            vector<TreeNode*> right = recursion(i + 1, end);
            for (int u = 0; u < left.size(); u++) {
                for (int v = 0; v < right.size(); v++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[u];
                    root->right = right[v];
                    rs.push_back(root);
                }
            }
        }
        return rs;
    }

    vector<TreeNode*> generateTrees(int n) {
        return recursion(1, n);
    }
};