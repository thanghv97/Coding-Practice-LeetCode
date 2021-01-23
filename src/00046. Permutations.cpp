class Solution {
public:
    void recursion(std::vector<std::vector<int>>& rs, std::queue<int> &queue, 
                   std::vector<int>& tmp) {
        int n = queue.size();
        if (n == 0) {
            rs.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            int val = queue.front(); queue.pop();
            tmp.push_back(val);    
            recursion(rs, queue, tmp);
            queue.push(val);    
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        std::queue<int> queue;
        std::vector<std::vector<int>> rs;
        std::vector<int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            queue.push(nums[i]);
        }    
        recursion(rs, queue, tmp);
        return rs;
    }
};