class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::unordered_map<string, int> maps;
        std::unordered_map<int, std::unordered_map<string, int>> maps_cs;
        std::vector<string> f;
        std::vector<int> rs;
        int N = words.size();
        int L = words[0].length();
        
        if (N*L > s.length() || N == 0 || L == 0) return rs;
        
        for (int i = 0; i < words.size(); i++) {
            maps[words[i]]++;
        }
        
        for (int i = 0; i < L; i++) {
            maps_cs[i] = maps;
        }
        
        for (int i = 0; i < L; i++) {
            std::string tmp = "";
            int j = i;
            int begin = i;
            
            while (j + L - 1 < s.length()) {
                std::string sub = s.substr(j, L);
                tmp += sub;
                                
                auto it = maps.find(sub);
                if (it != maps.end()) {
                    if (--maps_cs[i][sub] == 0) {
                        maps_cs[i].erase(sub);
                    } 
                }
                
                if (j - begin + L == L * N) {
                    if (maps_cs[i].size() == 0) {
                        rs.push_back(begin);
                    }

                    std::string sub2 = s.substr(begin, L);
                    it = maps.find(sub2);
                    if (it != maps.end()) {
                        if (++maps_cs[i][sub2] == 0) {
                            maps_cs[i].erase(sub2);
                        }
                    }
                    
                    tmp.erase(0, L);
                    begin += L;
                }
                j += L;
            }
        }

        
        
        return rs;
    }
};