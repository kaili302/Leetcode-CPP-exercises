/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
*/

class Solution{
public:
    int coinChange(vector<int>& coins, int target){
        sort(coins.begin(), coins.end());
        vector<int> dp(target + 1, target + 1);
        dp[0] = 0;
        for (int i = 1; i <= target; i++){
            for (auto& coin : coins){
                if (coin > i) break;
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        return dp[target] == target + 1 ? -1 : dp[target];
    }
};