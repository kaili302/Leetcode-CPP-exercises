/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Subscribe to see which companies asked this question
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int totalRemaining = 0;
    	int start = 0;
    	int total = 0;
    	for (int station = 0; station < gas.size(); station++){
        	int remaining = gas[station] - cost[station];
        	if (totalRemaining >= 0){
        		totalRemaining += remaining;
        	}else{
        		totalRemaining = remaining;
        		start = station;
        	}
        	total += remaining;
        }

        if (total < 0) return -1;
        return start;
    }
};