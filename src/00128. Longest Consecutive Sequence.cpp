auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        std::unordered_set<int> val;
        int rs = 1;

        for (int num : nums) {
            val.insert(num);
        }
        
        for (int num : nums) {
            if (val.find(num - 1) == val.end()) {
                int itr = num + 1;
                while (val.find(itr++) != val.end());
                rs = max(rs, itr - num - 1);
            }
        }
        return rs;
    }
};