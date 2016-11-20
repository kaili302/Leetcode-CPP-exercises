/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/


class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string result;
        ostringstream oss; oss << 1;
        for (int i = 2; i <= n; i++){
        	result = oss.str();
        	oss.str("");
        	int j = 0;
        	while (j < result.size()){
        		int count = 1;
        		while (j + 1 < result.size() && result[j] == result[j+1]){
        			count++;
        			j++;
        		}
        		oss << count << result[j++];
        	}
        }
        return oss.str();
    }
};