/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution{
private:
	bool isLetter(string s){
		return s[0] != '0' && stoi(s) <= 26;
	}
public:
	int numDecodings(string s) {
	    if (s.empty()) return 0;
		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= s.size(); i++){
			if (i != s.size() && !s[i])
				continue;
			if (isLetter(s.substr(i-1, 1)))
				dp[i] += dp[i-1];
			if (i > 1 && isLetter(s.substr(i-2, 2)))
				dp[i] += dp[i-2];

		}
		return dp.back();
	}
};

// place can be reduced to o(1)