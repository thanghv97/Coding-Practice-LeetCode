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
    int n;
    
    TreeNode* getNode(TreeNode* root, vector<int>& tmp, int id, int num) {
        if (tmp[id] == 0) return nullptr;
        
        TreeNode* node = new TreeNode(tmp[id]);
        if (root == nullptr) {
            root = node;
        }
        if (++num == n) {
            return root;
        }
        node->left = getNode(root, tmp, 2*id, num);
        node->right = getNode(root, tmp, 2*id + 1, num);
        return node;
    }
    
    void recursion(const int& begin, const int &end, const int& id, 
                   vector<TreeNode*>& rs, vector<int>& tmp, vector<bool>& f, int& num) {
        cout<<id<<" | ";
        for (int i = 1; i <= 8; i++) {
            cout<<tmp[i]<<" ";
        }
        cout<<endl;
        if (num == n) {
            rs.push_back(getNode(nullptr, tmp, 1, 0));
            return;
        }
        
        bool has_node = false;
        for (int i = begin; i <= end; i++) {
            if (!f[i]) {
                tmp[id] = i;
                has_node = true;
                f[i] = true;
                num++;
                recursion(begin, i - 1, 2*id, rs, tmp, f, num);
                recursion(i + 1, end, 2*id + 1, rs, tmp, f, num);
                f[i] = false;
            }        
        }
        if (!has_node) tmp[id] = 0;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        this->n = n;
        
        vector<TreeNode*> rs;
        vector<bool> f(n, false);
        vector<int> tmp(1<<n + 1, 0);
        
        int num = 0;
        recursion(1, n, 1, rs, tmp, f, num);
        return rs;
    }
};