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

// overload hash and equal function to use graph hashmap
/*
template<>
struct hash<UndirectedGraphNode*>{
	// use memory address as hash value
	size_t operator()(const UndirectedGraphNode*& pNode) const{
		return reinterpret_cast<size_t>(pNode);
	}
};
*/

// one pass and bug free ;) bfs solution

class Solution {
private:
  vector<UndirectedGraphNode*> toDelete;

  UndirectedGraphNode* cloneNode(UndirectedGraphNode* pNode){
    toDelete.push_back(new UndirectedGraphNode(pNode->label));
    toDelete.back()->neighbors = pNode->neighbors;
    return toDelete.back();
  }
public:
  ~Solution(){
    for (auto &pNode : toDelete) 
      delete pNode;
  }
  
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
      if (!node) 
      	return nullptr;
      
      unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hashMap;
      queue<UndirectedGraphNode*> q;

      UndirectedGraphNode* clonedRoot = cloneNode(node);
      q.push(clonedRoot);
      hashMap.insert({node, clonedRoot});

      while (q.size()){
        UndirectedGraphNode* pClonedNode = q.front();
        q.pop();
        for (int i = 0; i < pClonedNode->neighbors.size(); i++){
        if (!hashMap.count(pClonedNode->neighbors[i])){
            UndirectedGraphNode* clonedNeighbor = cloneNode(pClonedNode->neighbors[i]);
            q.push(clonedNeighbor);
            hashMap.insert({pClonedNode->neighbors[i], clonedNeighbor});
          }
          pClonedNode->neighbors[i] = hashMap[pClonedNode->neighbors[i]];
        }
      }    
      return hashMap[node];
    }
};