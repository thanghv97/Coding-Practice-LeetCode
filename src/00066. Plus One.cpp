class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int tmp = 1;
        for (int i = n - 1; i >= 0 && tmp == 1; i--) {
            int sum = digits[i] + tmp;
            tmp = (sum == 10) ? 1 : 0;
            digits[i] = sum % 10;
        }

        if (tmp == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};