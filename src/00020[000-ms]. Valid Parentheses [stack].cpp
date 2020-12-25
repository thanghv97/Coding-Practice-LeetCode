class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int i = 0;
        
        while (i < s.length()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push_back(s[i]);
            } else{
                if (stack.size() == 0) return false;
                if (s[i] == ')' && stack[stack.size()-1] != '(') return false;
                if (s[i] == ']' && stack[stack.size()-1] != '[') return false;
                if (s[i] == '}' && stack[stack.size()-1] != '{') return false;
                stack.pop_back();
            }
            i++;
        }
        
        if (stack.size() > 0) {
            return false;
        }
        return true;
    }
};