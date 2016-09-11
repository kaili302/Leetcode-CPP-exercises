class Solution{
public:	
	int LCS(string s, string t){
		if (s.size() * t.size() == 0) return 0;
		vector<vector<int>> dp (s.size() + 1, vector<int>(t.size() + 1));
		int maxLen = 0;
		for (int i = 1; i <= s.size(); i++){
			for(int j = 1; j <= t.size(); j++){
				if (s[i-1] != t[j-1]) dp[i][j] = 0;
				else {
					dp[i][j] = 1 + dp[i-1][j-1];
					maxLen = max(maxLen, dp[i][j]);
				}
			}
		}
		return maxLen;
	}
};