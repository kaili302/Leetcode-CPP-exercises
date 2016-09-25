class Solution{
public:
    int longestSubstr2UniqueChars(string s){
        if (s.size() <= 1) return 0;
        unordered_map<char, int> hashmap;
        int maxLen = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++){
            if (hashmap.count(s[i])) hashmap[s[i]] = i;
            else{
                if (hashmap.size() == 2){
                    unordered_map<char, int>::iterator it = hashmap.begin();
                    char toRemove = it->second < (++it)->second ? hashmap.begin()->first : it->first;
                    left = hashmap[toRemove] + 1;
                    hashmap.erase(toRemove);
                }
                hashmap.emplace(s[i], i);
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};