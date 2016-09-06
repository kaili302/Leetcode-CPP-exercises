/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"]
*/
class Solution {
private:
    void wordBreak(int idx, vector<vector<string>> &wordLadder, vector<string> &wordsList, vector<string> &result) {
        if (idx == -1){
            string str;
            for (int i = wordsList.size() - 1; i >= 0; i--)
                str.append(wordsList[i]+" ");
            str.pop_back();
            result.push_back(str);
            return ;
        }
    
        for (auto &word : wordLadder[idx]){
            wordsList.push_back(word);
            wordBreak(idx - word.length(), wordLadder, wordsList, result);
            wordsList.pop_back();
        }
    }
    bool check(string s, unordered_set<string>& wordDict) {
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
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.empty() || !check(s, wordDict)) return {};
        int sLen = s.length();
        vector<vector<string>> wordLadder(sLen, vector<string>{});

        int maxWordLen = 0;
        for (auto &word : wordDict) 
            maxWordLen = max(maxWordLen, static_cast<int>(word.length()));

        for (int i = 0; i < sLen; i++){
            for (int j = i; j >= 0 && i - j + 1 <= maxWordLen; j--){
                // check whether substr(j, i) is a word from wordDict
                if (wordDict.count(s.substr(j, i - j + 1)))
                    wordLadder[i].push_back(s.substr(j, i - j + 1));
            }
        }

        vector<string> result;
        vector<string> wordsList;
        wordBreak(sLen - 1, wordLadder, wordsList, result);
        return result;
    }
};