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
auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int ii = -1;
    std::unordered_map<int, int> cs;
    
    TreeNode* buildSubTree(const vector<int>& preorder, const vector<int>& inorder, int l, int r) {
        ii++;
        int i = cs.find(preorder[ii])->second;
        
        TreeNode* root = new TreeNode(preorder[ii]);
        root->left = (l == i) ? nullptr : buildSubTree(preorder, inorder, l, i - 1);
        root->right = (r == i) ? nullptr : buildSubTree(preorder, inorder, i + 1, r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); i++) {
            cs[inorder[i]] = i;
        }
        return buildSubTree(preorder, inorder, 0, inorder.size() - 1);
    }
};