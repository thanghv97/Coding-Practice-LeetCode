class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(10);
        vector<int> nums;

        for (int i = 1; i < 10; i++) {
            factorial[i] = (i != 1) ? factorial[i-1] * i : 1;
            nums.push_back(i);
        }
        
        string rs = "";
        int idx = n;
        for (int i = 0; i < n - 1; i++) {
            int ch = 0;
            while (ch < idx && (ch + 1) * factorial[n - i - 1] < k) ch++;
            
            rs = rs + (char)(nums[ch] + '0');
            k -= ch * factorial[n - i - 1];
            
            swap(nums[ch], nums[--idx]);
            sort(nums.begin(), nums.begin() + idx);
        }
        
        rs += (char)(nums[0] + '0');
        return rs;
    }
};