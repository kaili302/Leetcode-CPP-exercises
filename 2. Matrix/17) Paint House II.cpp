/*
3 colors become k colors. same as paint house
*/

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int nHouses = costs.size();
        assert(nHouses);
        int nColors = costs[0].size();

        int prevMin = 0;
        int prevSecond = 0;
        int prevMinIndex = 0;

        for (int i = 0; i < nHouses; i++){
        	if (i != 0) {
	        	for (int j = 0; j < nColors; j++) {
	        		costs[i][j] += (prevMinIndex == j? prevSecond: prevMin);
	        	}	
        	}

        	prevMin = costs[i][0];
        	prevMinIndex = 0;
        	prevSecond = -1;
        	for (int j = 1; j < nColors; j++) {
        		if (costs[i][j] < prevMin) {
        			prevSecond = prevMin;
        			prevMin = costs[i][j];
        			prevMinIndex = j;
        		}else if (prevSecond == -1 || costs[i][j] < prevSecond ) {
        			prevSecond = costs[i][j];
        		}
        	}
        }

       	int minCost = costs[nHouses-1][0];
       	for (int i = 1; i < nColors; i++) 
       		minCost = min(minCost, costs[nHouses-1][i]);
       	return minCost;
    }
};