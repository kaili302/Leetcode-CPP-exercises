/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a
 single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/

typedef unordered_map<string, priority_queue<string, vector<string>, greater<string>>> Graph;
class Solution{
  void buildGraph(vector<pair<string, string>>& tickets, Graph& graph){
    for (auto& ticket : tickets){
      if (!graph.count(ticket.first)) 
        graph.insert({ticket.first, priority_queue<string, vector<string>, greater<string>>{}});
      graph[ticket.first].push(ticket.second);
    }
  }

  void dfs(string dep, Graph& graph, vector<string>& res){
      while (graph[dep].size()){
        string des = graph[dep].top();
        graph[dep].pop();
        dfs(des, graph, res);
      }
      res.push_back(dep);
  }
public:
  vector<string> findItinerary(vector<pair<string, string>>& tickets) {
      Graph graph;
      buildGraph(tickets, graph);
      vector<string> res;
      dfs("JFK", graph, res);
      reverse(res.begin(), res.end());
      return res;
  }
};
