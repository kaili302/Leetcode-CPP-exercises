// Given a digit string, return all possible letter combinations that the number could represent. 
// Input:Digit string "23", Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
class Solution{
private:
    const vector<string> keymap{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void letterCombinations(string& digits, int idx, string& letter, vector<string>& combinations){
        if (idx == digits.size()){
            combinations.push_back(letter);
            return;
        }
        for (int i = 0; i < keymap[digits[idx] - '0'].size(); i++){
            letter.push_back(keymap[digits[idx] - '0'][i]);
            letterCombinations(digits, idx + 1, letter, combinations);
            letter.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> combinations;
        string letter;
        letterCombinations(digits, 0, letter, combinations);
        return combinations;
    }
};