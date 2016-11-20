struct Edge{
	int des;
	int dis;
	Edge(int ides, int idis) : des{ides}, dis{idis}{}
};

struct Vertex{
	int id;
	int sum;
	vector<Edge> outbounds;
	Vertex(int iid) : id{iid}{
		sum = INT_MAX;
	}
};

struct VertexCmp{
	bool operator()(Vertex* pV1, Vertex* pV2) const{
		return pV1->sum > pV2->sum;
	}
};

int shortestPathSum(vector<Vertex*>& vertices, int start, int end){
	priority_queue<Vertex*, vector<Vertex*>, VertexCmp> minHeap;
	vertices[start]->sum = 0;
	minHeap.push(vertices[start]);
	while(minHeap.size()){
		Vertex* pTop = minHeap.top();
		minHeap.pop();
		if (pTop->id == end)
			return pTop->sum;
		for (auto& outbound : pTop->outbounds){
			if (pTop->sum + outbound.dis < vertices[outbound.des]->sum){
				vertices[outbound.des]->sum = pTop->sum + outbound.dis;
				minHeap.push(vertices[outbound.des]);
			}
		}
	}
	return -1;
}

void test(){

	Vertex* v0 = new Vertex{0}; v0->outbounds = vector<Edge>{{1, 2}, {5, 2}};
	Vertex* v1 = new Vertex{1}; v1->outbounds = vector<Edge>{{4, 1}, {0, 2}};
	Vertex* v2 = new Vertex{2}; v2->outbounds = vector<Edge>{{6, 1}, {5, 1}};
	Vertex* v3 = new Vertex{3}; v3->outbounds = vector<Edge>{{4, 3}, {6, 4}};
	Vertex* v4 = new Vertex{4}; v4->outbounds = vector<Edge>{{1, 1}, {6, 1}, {5, 5}, {3, 3}};
	Vertex* v5 = new Vertex{5}; v5->outbounds = vector<Edge>{{2, 1}, {0, 2}};
	Vertex* v6 = new Vertex{6}; v6->outbounds = vector<Edge>{{2, 1}, {0, 3},{4, 1}, {3, 4}};
	vector<Vertex*> graph{v0, v1, v2, v3, v4, v5, v6};

	// Vertex v0{0}; v0.edges = vector<Edge>{{1, 3}, {2, 6}};
	// Vertex v1{1}; v1.edges = vector<Edge>{{0, 3}, {2, 5}};
	// Vertex v2{2}; v2.edges = vector<Edge>{{0, 6}, {1, 5}};
	// vector<Vertex> graph{v0, v1, v2};
	int start = 3;
	int end = 0;

	int res = shortestPathSum(graph, start, end);
	cout << res << endl;
}