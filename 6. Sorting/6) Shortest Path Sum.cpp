struct Edge{
	int v1;
	int v2;
	int weight;
};

struct Vertex{
	int id;
	int val;
	vector<Edge> outbounds;
};

class VertexCmp{
public:
	bool operator()(Vertex* pv1, Vertex* pv2) const{
		return pv1->val > pv2->val;
	}
};

typedef set<Vertex*, vector<Vertex*>, VertexCmp> RBTree;


int shortestPathSum(vector<Edge>& graph, int N, int start, int end){
	vector<Vertex> vertices;
	for (int i = 0; i < N; i++)
		vertices.emplace_back(i, INT_MAX);
	
	for (auto& edge : graph){
		vertices[edge.v1].outbounds.push_back(edge);
		vertices[edge.v2].outbounds.emplace_back(edge.v2, edge.v1, edge.weight);
	}

	RBTree rbTree;
	rbTree.insert(&vertices[start]);
	vertices[start].val = 0;

	vector<int> previous(N, -1);

	while (rbTree.size()){
		Vertex* pMinVertex = *(rbTree.begin()); 
		if (pMinVertex->id == end)
			return pMinVertex->val;

		rbTree.erase(pMinVertex);

		for (Edge& outbound : pMinVertex->outbounds){
			if (vertices[outbound.v1].val + outbound.weight < vertices[outbound.v2].val){
				if (rbTree.count(&vertices[outbound.v2]))
					rbTree.erase(&vertices[outbound.v2]);
				vertices[outbound.v2].val = vertices[outbound.v1].val + outbound.weight;
				rbTree.insert(&vertices[outbound.v2]);
			}
		}
	}
	// can not reach end from start
	return -1;
}


int main(){
	vector<Edge> graph{{3, 4, 3},{3, 6, 4},{6, 4, 1},{6, 2, 1}, {4, 5, 5}, {4, 1, 1}, {6, 0, 3}, {0, 5, 2}};
	int res = shortestPathSum(graph, 7, 3, 5);
	cout << res << endl;
}







}