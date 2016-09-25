/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".*/
class Solution {
public:
    string addBinary(string a, string b) {
  		reverse(a.begin(), a.end());      
  		reverse(b.begin(), b.end());      
  		int carry = 0;
  		ostringstream oss;
  		for (int i = 0; i < a.size() || i < b.size() || carry != 0; i++){
  			int sum = carry + (i < a.size() ? a[i] - '0' : 0) + (i < b.size() ? b[i] - '0' : 0);
  			oss << sum % 2;
  			carry = sum / 2;
  		}
  		string ret = oss.str();
  		reverse(ret.begin(), ret.end());
  		return ret;
    }
};