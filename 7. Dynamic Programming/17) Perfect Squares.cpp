/*
Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/
#include <climits>

class Solution{
private:
    vector<int> getSquareNumbers(int n){
        int i = 1;
        vector<int> nums;
        while (i * i <= n) {
            nums.push_back(i * i);
            i++;
        }
        return nums;
    }
public:
    int numSquares(int n){
        vector<int> squareNums = getSquareNumbers(n);
        // need at most n numbers (contains only 1)
        vector<int> dp(n + 1, n); 
        dp[0] = 0;
        for (int num = 1; num <= n; num++){
            for (auto &snum : squareNums){
                if (snum > num) break;
                dp[num] = min(dp[num], dp[num-snum]+1);
            }
        }
        return dp[n];
    }
};