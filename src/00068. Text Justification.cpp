class Solution {
public:
    int getWords(const vector<string>& words, int& i, const int& maxWidth) {
        int total_len = 0;
        int curr_len = 0;
        while (i < words.size() && total_len + words[i].length() <= maxWidth) {
            curr_len += words[i].length();
            total_len = total_len + words[i++].length() + 1;     
        }
        return curr_len;
    }
    
    string formatText(const int& begin, const int& end, const int& len,
                      const vector<string>& words, const int& maxWidth) {
        string str = "";
        if (end == words.size() || end - begin == 1) {
            for (int i = begin; i < end; i++) {
                str = str + words[i];
                str = (str.length() < maxWidth) ? str + ' ' : str;
            }
            while (str.length() < maxWidth) str += ' ';
        } else {
            int spaces = maxWidth - len;
            for (int i = begin; i < end; i++) {
                str += words[i];
                int tmp = end - i - 1;
                if (tmp > 0) {
                    int ext_spaces = (spaces % tmp == 0) ? spaces/tmp : spaces/tmp + 1;
                    for (int j = 0; j < ext_spaces; j++) {
                        str += ' ';
                    }
                    spaces -= ext_spaces;
                }
            }
        }
        return str;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rs;
        int i = 0;

        while (i < words.size()) {
            int j = i;
            int len = getWords(words, j, maxWidth);
            rs.push_back(formatText(i, j, len, words, maxWidth));
            i = j;
        }
        
        return rs;
    }
};