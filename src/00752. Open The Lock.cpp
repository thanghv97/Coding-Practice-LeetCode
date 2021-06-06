auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int bfs(const int target, vector<int> &f) {
        std::queue<int> queue;
        
        int initial = 0;
        if (f[initial] == -1) {
            return -1;
        } else {
            queue.push(initial);
            f[initial] = 1;
        }
        while (queue.size() > 0) {
            int base = queue.front();
            
            for (int i = 0; i < 4; i++) {
                int pow = (int)std::pow(10.0, i);
                int var = (base / (1000 / pow)) % 10;

                // add
                int add = ((var == 9) ? -9 : 1) * (1000 / pow);
                if (f[base + add] == 0) {
                    f[base + add] = f[base] + 1;
                    if (base + add == target) {
                        return f[target] - 1;
                    }
                    queue.push(base + add);
                }
                
                // minus
                int minus = ((var == 0) ? -9 : 1) * (1000 / pow);
                if (f[base - minus] == 0) {
                    f[base - minus] = f[base] + 1;
                    if (base - minus == target) {
                        return f[target] - 1;
                    }    
                    queue.push(base - minus);
                }
            }
            
            queue.pop();
        }
        
        return -1;
    }
    
    int openLock(vector<string>& deadends, string target) {
        vector<int> f(10000, 0);
        for (int i = 0; i < deadends.size(); i++) {
            f[std::stoi(deadends[i])] = -1;
        }
        int targetNum = std::stoi(target);
        
        return (targetNum == 0) ? 0 : bfs(targetNum, f);
    }
};