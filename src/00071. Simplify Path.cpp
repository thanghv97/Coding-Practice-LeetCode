class Solution {
public:
    string simplifyPath(string path) {
        stack<string> names;
        
        int i = 0;
        while (i < path.length() && path[i] != '/') i++;
        while (i < path.length()) {
            int j = i + 1;
            string tmp = "";
            while (j < path.length() && path[j] != '/') { 
                tmp += path[j++];
            }
            if (tmp == "..") {
                if (names.size() > 0) {
                    names.pop();
                }
            } else if (tmp != "." && tmp != "") {
                names.push(tmp);
            }
            
            i = (path[j] == '/') ? j : j + 1;
        }
        
        string rs = "";
        while (names.size() > 0) {
            rs = (rs == "") ? names.top() + rs : names.top() + "/" + rs;
            names.pop();
        }
        return "/" + rs;
    }
};