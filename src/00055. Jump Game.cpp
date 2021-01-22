class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        std::queue<int> q;
        std::vector<int> f(nums.size());
        int max_idx = 0;

        q.push(0);
        f[0] = 0;
        while (q.size() > 0) {
            int idx = q.front();
            
            for (int i = max_idx + 1; i <= idx + nums[idx]; i++) {
                f[i] = f[idx] + 1;
                if (i == nums.size() - 1) {
                    return true;
                }
                q.push(i);    
            }
            max_idx = std::max(max_idx, idx + nums[idx]);
            q.pop();
        }
        return false;
    }
};