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

typedef priority_queue<string, deque<string>, greater<string>> MinHeap_t;
class Solution {
public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    unordered_map<string, MinHeap_t> graph;
    for (auto& ticket : tickets){
      if (!graph.count(ticket.first)) 
        graph.emplace(ticket.first, MinHeap_t{});
      graph[ticket.first].push(ticket.second);
    }
    deque<string> result;
    dfs("JFK", result, graph);
    return {result.begin(), result.end()};
  }

  void dfs(string dep, deque<string>& result, unordered_map<string, MinHeap_t>& graph){
    MinHeap_t& destinations = graph[dep];
    while(destinations.size()){
      string destination = destinations.top();
      destinations.pop();
      dfs(destination, result, graph);
    }
    result.push_front(dep);
  }
};