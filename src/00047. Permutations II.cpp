class Solution {
public:
    void recursion(std::vector<std::vector<int>> &rs, std::queue<int> &queue, 
                   std::vector<int> &tmp) {
        if (queue.size() == 0) {
            rs.push_back(tmp);
            return;
        }
        
        int val_tmp = -11;
        for (int i = 0; i < queue.size(); i++) {
            int val = queue.front(); queue.pop();
            if (val != val_tmp) {
                tmp.push_back(val);
                recursion(rs, queue, tmp);
                tmp.pop_back();
                val_tmp = val;
            }
            queue.push(val);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::queue<int> queue;
        std::vector<std::vector<int>> rs;
        std::vector<int> tmp;
        
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            queue.push(nums[i]);
        }
        recursion(rs, queue, tmp);
        return rs;
    }
};