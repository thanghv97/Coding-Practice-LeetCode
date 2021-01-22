class Solution {
public:
    void recursion(vector<vector<pair<int, int>>> &sols, vector<pair<int, int>> &tmp,
                   const int& n, const int k) {
        if (k == n) {
            sols.push_back(tmp);
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
            recursion(sols, tmp, n, k + 1);
            tmp.pop_back();
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int, int>>> sols;
        vector<vector<string>> rs;
        vector<pair<int, int>> tmp;
        recursion(sols, tmp, n, 0);

        for (int k = 0; k < sols.size(); k++) {
            vector<string> tmp;
            for (int i = 0; i < n; i++) {
                string str = "";
                for (int j = 0; j < n; j++) {
                    str += (j != sols[k][i].second) ? '.' : 'Q';
                }
                tmp.push_back(str);
            }
            rs.push_back(tmp);
        }
        return rs;
    }
};