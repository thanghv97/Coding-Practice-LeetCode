class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> f(nums.size());
        std::queue<int> queue;
        
        queue.push(0);
        f[0] = 0;
        int cs = 1;
        while (queue.size() > 0) {
            int idx = queue.front();
            while (cs < nums.size() && cs <= nums[idx] + idx) {
                f[cs] = f[idx] + 1;
                if (cs == nums.size() - 1) {
                    return f[cs];
                }
                queue.push(cs);
                cs++;
            }
            
            queue.pop();
        }
        
        return 0;    
    }
};