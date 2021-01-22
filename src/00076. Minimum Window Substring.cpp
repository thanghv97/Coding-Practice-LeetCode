class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> maps;
        
        for (int i = 0; i < t.length(); i++) { 
            maps[t[i]]++;
        }
    
        int num = maps.size();
        int i = 0, j = 0;
        int rs = s.length(), id = 0;
        while (j < s.length()) {
            cout<<j<<" - "<<s[j]<< " | ";
            if (--maps[s[j++]] == 0) num --;
            while (i < j && maps[s[i]] < 0) {
                cout<<i<<" ";
                if (++maps[s[i]] == 0) maps.erase(s[i]);
                i++;
            }
            cout<<endl;
            if (num == 0) {
                rs = min(rs, j - i);
                id = i;
            }
        }
        return s.substr(id, rs);
    }
};