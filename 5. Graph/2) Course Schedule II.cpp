/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

return one valid solution
*/

class Solution{
public:
  vector<int> findOrder(int n, vector<pair<int, int>>& prerequisites) {
    vector<int> result;
    vector<int> inbounds(n, 0);
    vector<vector<int>> outbounds(n, vector<int>{});
    for (auto& prerequisit : prerequisites){
      inbounds[prerequisit.first]++;
      outbounds[prerequisit.second].push_back(prerequisit.first);
    }
    queue<int> zeroInbounds;
    for (int i = 0; i < n; i++){
      if (!inbounds[i])
        zeroInbounds.push(i);
    }
    while(zeroInbounds.size()){
      int course = zeroInbounds.front();
      zeroInbounds.pop();
      result.push_back(course);
      for (int next : outbounds[course]){
        if (!(--inbounds[next]))
          zeroInbounds.push(next);
      }
    }
    for (auto& inbound : inbounds){
      if (inbound) return {};
    }
    return result;
  }
};
