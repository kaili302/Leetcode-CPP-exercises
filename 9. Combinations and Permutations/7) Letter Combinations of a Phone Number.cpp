
class Solution {
private:
	void initKeyMap(array<string, 10> &keymap){
    	keymap[2] = "abc"; keymap[3] = "def";
    	keymap[4] = "ghi"; keymap[5] = "jkl";
    	keymap[6] = "mno"; keymap[7] = "pqrs";
    	keymap[8] = "tuv"; keymap[9] = "wxyz";
	}
    void letterCombinations(string &digits, int idx, string &letter, vector<string> &combinations, array<string, 10> &keymap) {
    	if (idx == digits.length()){
    		combinations.push_front(letter);
    		return;
    	}
    	string const &alphabets = keymap[digits[idx] - '0'];
    	for (int i = 0; i < alphabets.length(); i++){
    		letter.push_back(alphabets[i]);
    		letterCombinations(digits, idx + 1, letter, combinations, keymap);
    		letter.pop_back();
    	}
    }
public:
    vector<string> letterCombinations(string digits) {
    	if (digits.empty()) return {};
    	vector<string> combinations;
    	array<string, 10> keymap;
    	initKeyMap(keymap);

    	string letter{""};
    	letter.reserve(digits.length());
    	letterCombinations(digits, 0, letter, combinations, keymap);
    	return combinations;
    }
};
