/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
  		// finish prerequisit.second to finish prerequisit.first
  		vector<int> inbounds(numCourses, 0);
  		for (auto& prerequisit : prerequisites){
  			// build inbounds map
  			inbounds[prerequisit.first]++;
  		}
  		queue<int> zeroInboundsQ;
  		for (int i = 0; i < numCourses; i++){
  			if (!inbounds[i]) 
  				zeroInboundsQ.push(i);
  		}

  		while (zeroInboundsQ.size()){
  			int zeroInboundsNode = zeroInboundsQ.front();
  			zeroInboundsQ.pop();
  			for (auto& prerequisit : prerequisites){
  				if (prerequisit.second == zeroInboundsNode){
  					if(--inbounds[prerequisit.first] == 0){
  						zeroInboundsQ.push(prerequisit.first);
  					}
				}
  			}
   		}

		for (int i = 0; i < numCourses; i++){
  			if (inbounds[i]) 
  				return false;
  		}
  		return true;
    }
};