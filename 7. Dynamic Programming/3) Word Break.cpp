/*
Given a string s and a dictionary of words dict, determine if s can be segmented into
 a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
		if (wordDict.empty()) return false;
		int maxWordLen = 0;
		for (auto &word : wordDict)
			maxWordLen = max (maxWordLen, static_cast<int>(word.length()));

		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;		

		for (int i = 1; i <= s.length(); i++){
			for (int j = i - 1; j >= 0 && i - j <= maxWordLen; j--){
				// check substr  s(j, i - 1)
				if (wordDict.count(s.substr(j, i - j)) && dp[j])
					dp[i] = true;
			}
		}
		return dp[s.length()];
    }
};