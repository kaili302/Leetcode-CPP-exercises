/*
Given two strings S and T, determine if they are both one edit distance apart.
*/

class Solution{
public:
    bool isOneEditDistance(string s, string t) {
        int sizeDiff = abs(static_cast<int>(s.size()) - static_cast<int>(t.size()));
        if (sizeDiff >= 2) return false;
        int loS = 0, hiS = s.size() - 1;
        int loT = 0, hiT = t.size() - 1;
        while (loS < s.size() && loT < t.size() && s[loS] == t[loT]){
            loS++; loT++;
        }
        while (hiS >= 0 && hiT >= 0 && s[hiS] == t[hiT]){
            hiS--; hiT--;
        }
        if (sizeDiff == 0)
            return loS == hiS;

        return ( loS == hiS && loT > hiT ) || ( loT == hiT && loS > hiS );
    }
};

