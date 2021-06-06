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
    
    struct comparer {
        inline bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return (a.second > b.second) || (a.second == b.second && a.first > b.first);
        }
    };
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        std::vector<std::pair<int, int>> performance;
        for (int i = 0; i < n; i++) {
            performance.push_back(make_pair(speed[i], efficiency[i]));
        }
        sort(performance.begin(), performance.end(), comparer());
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap_min;
        long sum = 0;
        long rs = 0;
        
        for (int i = 0; i < n; i++) {
            if (heap_min.size() < k) {
                sum += performance[i].first;
                heap_min.push(performance[i].first);
            } else {
                if (performance[i].first > heap_min.top()) {
                    sum -= heap_min.top();
                    sum += performance[i].first;
                    heap_min.push(performance[i].first);
                    heap_min.pop();
                }
            }
            if (sum * performance[i].second > rs) {
                rs = sum * performance[i].second;
            }
        }
        
        return rs % mod;
    }
};