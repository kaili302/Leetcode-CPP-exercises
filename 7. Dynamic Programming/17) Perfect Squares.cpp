/*
Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution{
private:
    void squareNums(int n, vector<int>& nums){
        for (int i = 1; i * i <= n; i++)
            nums.push_back(i * i);
    }
public:
    int numSquares(int n){
        vector<int> nums;
        squareNums(n, nums);

        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int i = 1; i <= n; i++ ){
            for (auto& num : nums){
                if (i < num) break;
                dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
        return dp[n];
    }
};