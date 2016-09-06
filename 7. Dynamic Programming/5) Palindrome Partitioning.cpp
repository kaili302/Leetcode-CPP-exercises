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
class Solution{
private:
	void partition(string &s, int start, vector<string> &tmpList, vector<vector<string>> &result, vector<vector<bool>> &isPalindrome) {
		if (start == s.length()) {
			result.push_back(tmpList);
		}

		for (int i = start; i < s.length(); i++){
			if (isPalindrome[start][i]) {
				tmpList.push_back(s.substr(start, i - start + 1));
				partition(s, i + 1, tmpList, result, isPalindrome);
				tmpList.pop_back();
			}
		}
	}
public:
 	vector<vector<string>> partition(string s) {
 		int sLen = s.length();
 		vector<vector<bool>> isPalindrome(sLen, vector<bool>(sLen, false));

 		for (int i = sLen - 1; i >= 0; i--){
 			for (int j = i; j < sLen; j++){
 				if (s[i] == s[j] && (i + 1 >= j || isPalindrome[i+1][j-1]))
 					isPalindrome[i][j] = true;
 			}
 		}

 		vector<vector<string>> result;
		vector<string> tmpList;
		tmpList.reserve(s.length());
		partition(s, 0, tmpList, result, isPalindrome);
		return result;
 	}
};