/*
n houses, each house can be painted with: red, blue or green.  paint all houses such that no 
two adjacent houses have same color.  costs is n*3 matrix. costs[0][0] is the cost of painting 
house 0 with color red(0); costs[1][2] is the cost of painting house 1 with color green… 
Find the minimum cost to paint all houses.*/

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        assert(costs.size());
        for (int i = 1; i < costs.size(); i++){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
        return min(min(costs.back()[0], costs.back()[1]), costs.back()[2]);
    }
};