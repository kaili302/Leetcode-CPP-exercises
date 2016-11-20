/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : Target is lower than guess
 1 : Target is higher than guess
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
		int lo = 1, hi = n;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			int result = guess(mid);
			if (result == 0) return mid;
			else if (result > 0) lo = mid + 1;
			else hi = mid - 1;
		}
		return -1;
    }
};


/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. 
You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
*/
/*
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

*/

// 新的 dp 算法
class Solution {
private:
    int helper(vector<vector<int>>& dp, int lo, int hi){
        if (lo >= hi) return 0;
        if (dp[lo][hi] > 0) return dp[lo][hi];
        int cost = INT_MAX;
        for (int x = lo; x <= hi; x++)
            cost = min(cost, x + max(helper(dp, lo, x - 1), helper(dp, x + 1, hi)));
        dp[lo][hi] = cost;
        return cost;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp (n + 1, vector<int>(n + 1, 0));
        return helper(dp, 1, n);
    }
};


