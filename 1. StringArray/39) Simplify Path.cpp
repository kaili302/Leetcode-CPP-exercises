/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int left = -1;
        for (int i = 0; i < path.size(); i++){
            string word = "";
            if (path[i] == '/'){
                if (left != -1)
                    word = path.substr(left + 1, i - left - 1); 
                left = i;
            }else if (i == path.size() - 1)
                word = path.substr(left + 1, i - left); 

            if (word != "" && word != "."){
                if (word == "..") {
                    if(s.size()) s.pop();
                }else s.push(word);
            }
        }

        string res = "";
        while (s.size()){
            res = "/" + s.top() + res;
            s.pop();
        }
        
        return res.empty() ? "/" : res;
    }
};
