class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int begin = 0;
        int end = x;
        
        while (begin <= end) {
            int mid = (begin + end) / 2;
            
            if (mid <= x/mid) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        // cout << begin << " " << end << " " << endl;
        return begin - 1;
    }
};