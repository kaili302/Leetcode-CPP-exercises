/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:
*/

struct UndirectedGraphNode{
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label{x} {};
};


class Solution {
  UndirectedGraphNode* cloneNode(UndirectedGraphNode* pNode){
    auto pNewNode = new UndirectedGraphNode(pNode->label);
    pNewNode->neighbors = pNode->neighbors;
    return pNewNode;
  };
public:
  UndirectedGraphNode* cloneGraph(UndirectedGraphNode* pRoot) {
    if (!pRoot)
        return pRoot;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hashmap;
    queue<UndirectedGraphNode*> bfsQ;
    auto pClone = cloneNode(pRoot);
    hashmap.insert({pRoot, pClone});
    bfsQ.push(pClone);

    while(bfsQ.size()){
      pClone = bfsQ.front();
      bfsQ.pop();
      for (auto& neighbor : pClone->neighbors){
        if (!hashmap.count(neighbor)){
          hashmap.insert({neighbor, cloneNode(neighbor)});
          bfsQ.push(hashmap[neighbor]);
        }
        neighbor = hashmap[neighbor];
      }
    }
    return hashmap[pRoot];
  }
};

