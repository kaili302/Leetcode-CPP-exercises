/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
class Solution {
public:
void buildPalMap(vector<vector<bool>>& palMap, string s){
	for (int i = s.size() - 1; i >= 0; i--){
		for(int j = i; j < s.size(); j++){
			palMap[i][j] = (s[i] == s[j] && (j - i <= 2 || palMap[i+1][j-1]));
		}
	}
}

void partition(vector<vector<bool>>& palMap, string& s, int idx, vector<string>& v, vector<vector<string>>& result){
	if (idx == s.size()) result.push_back(v);
	for (int len = 1; len <= s.size() - idx; len++){
		if (palMap[idx][idx+len-1]) {
			v.push_back(s.substr(idx, len));
			partition(palMap, s, idx + len, v, result);
			v.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	vector<vector<bool>> palMap(s.size(), vector<bool>(s.size(), false));
	buildPalMap(palMap, s);
	vector<vector<string>> result;
	vector<string> v;
	partition(palMap, s, 0, v, result);
	return result;
}
};