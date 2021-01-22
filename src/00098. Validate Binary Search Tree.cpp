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
    bool search(TreeNode* root, long low, long high) {
        if (root == nullptr) {
            return true;
        }
        
        // cout<<root->val<<" "<<low<<" "<<high<<endl;
        if ((low != LONG_MIN && root->val <= low) ||
            (high != LONG_MAX && root->val >= high)) {
            return false;
        }
        
        return search(root->left, low, root->val) && search(root->right, root->val, high);
    }
    
    bool isValidBST(TreeNode* root) {
        return search(root, LONG_MIN, LONG_MAX);
    }
};