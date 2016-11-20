
/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.  The dungeon consists of M x N rooms laid out in a 2D grid. 
Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or 
contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2	-3	3
-5	-10	1
10	30	-5

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int HE = dungeon.size();
        if (!HE) return 1;
        int WI = dungeon[0].size();
    
        vector<vector<int>> dp(HE, vector<int>(WI, 0));
        for (int r = HE - 1; r >= 0; r--){
            for (int c = WI - 1; c >= 0; c--){
                if (r != HE - 1 || c != WI - 1)
                    dp[r][c] = min((r == HE - 1? INT_MAX: dp[r+1][c]), (c == WI - 1? INT_MAX: dp[r][c+1]));
                dp[r][c] = dungeon[r][c] - dp[r][c];
                if (dp[r][c] > 0) dp[r][c] = 0;
                else dp[r][c] = -dp[r][c];
            }
        }
        return dp[0][0] + 1;
    }
};