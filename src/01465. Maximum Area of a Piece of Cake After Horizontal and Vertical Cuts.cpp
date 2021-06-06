auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    const unsigned int mod = 1000000007;
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxH = std::max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]);
        int maxW = std::max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]);
        
        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxH = std::max(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for (int i = 1; i < verticalCuts.size(); i++) {
            maxW = std::max(maxW, verticalCuts[i] - verticalCuts[i-1]);
        }

        return ((long)maxH * maxW) % mod;
    }
};