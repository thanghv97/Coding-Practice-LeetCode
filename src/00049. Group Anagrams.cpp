class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> maps;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(27, 0);
            for (int j = 0; j < strs[i].length(); j++) {
                count[strs[i][j] - 'a']++;
            }
            string str;
            for (int j = 0; j < 27; j++) {
                str += string(count[j], j + 'a');
            }
            maps[str].push_back(strs[i]);
        }
        
        std::vector<std::vector<string>> rs;
        for (auto it: maps) {
            rs.push_back(it.second);
        }
        return rs;
    }
};