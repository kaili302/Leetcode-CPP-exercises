/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.
*/



class Solution {
public:
    bool isValid(string s) {
    	unordered_map<char, char> dict;
    	dict.emplace(']', '[');
    	dict.emplace('}', '{');
    	dict.emplace(')', '(');

    	stack<char> cstack; 
    	for (int i = 0; i < s.size(); i++){
    		if (dict.count(s[i])){
    		    if (cstack.empty()) return false;
    			if (cstack.top() != dict[s[i]])
    				return false;
    			cstack.pop();
    		}else cstack.push(s[i]);
    	}
    	return cstack.empty();
    }
};