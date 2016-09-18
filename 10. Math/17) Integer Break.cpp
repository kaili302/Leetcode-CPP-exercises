/*
Given a positive integer n, break it into the sum of at least two positive integers 
and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); 
given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
*/
class Solution {
public:
    int IntegerBreak(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> dp(n + 1, 0);
        dp[1] = 1; dp[2] = 2; dp[3] = 3;

        for (int i = 4; i <= n; i++){
        	for (int j = 1; j <= i/2; j++){
        		dp[i] = max(dp[i], dp[j] * dp[i-j]);
        	}
        }
        return dp[n];
    }

	int integerBreak(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        if (n % 3 == 0)
        	return pow(3, n/3);
        else if (n % 3 == 1)
        	return pow(3, (n-4)/3) * 4;
        else 
        	return pow(3, n/3) * 2;
	}
};
