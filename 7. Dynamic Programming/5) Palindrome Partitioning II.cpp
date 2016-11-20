/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",

Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class Solution {
private:
    void buildPalMap(vector<vector<bool>>& palMap, string s){
        for (int i = s.size() - 1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                palMap[i][j] = (s[i] == s[j] && (j - i <= 2 || palMap[i+1][j-1]));
            }
        }
    }
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        vector<vector<bool>> palMap(s.size(), vector<bool>(s.size(), false));
        buildPalMap(palMap, s);
        vector<int> minCut(s.size() + 1, 0);
        minCut[0] = -1;
        for (int i = 0; i < s.size(); i++){
            for (int j = i; j >= 0; j--)
                if (palMap[j][i]) minCut[i+1] = min(1 + minCut[j], minCut[i+1]);
        }
        return minCut.back();
    }
};
