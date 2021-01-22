class Solution {
public:
    void recursion(int &rs, vector<pair<int, int>> &tmp, const int& n, const int k) {
        if (k == n) {
            rs++;
            return;
        }

        for (int i = 0; i < n; i++) {
            bool check = false;
            for (int j = 0; j < tmp.size(); j++) {
                if (i == tmp[j].second || (abs(k - tmp[j].first) == abs(i - tmp[j].second))) {
                    check = true;
                    break;
                }
            }
            if (check) {
                continue;
            }

            tmp.push_back({k, i});
            recursion(rs, tmp, n, k + 1);
            tmp.pop_back();
        }
    }
    
    int totalNQueens(int n) {
        int rs = 0;
        vector<pair<int, int>> tmp;
        recursion(rs, tmp, n, 0);

        return rs;
    }
};