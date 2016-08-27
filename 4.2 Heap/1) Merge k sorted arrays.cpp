

class ArrayContainer{
private:
    vector<int> *pList;
    int index;
public:
    ArrayContainer(vector<int> *pListIn): pList{pListIn}, index{0}{}
    
    int& top(){
        return (*pList)[index];
    }

    void pop(){
        index++;
    }

    bool isEmpty(){
        return index >= (*pList).size();
    }
};


class cmp{
public:
    bool operator()(ArrayContainer &node1, ArrayContainer &node2){
        return node1.top() > node2.top();
    }
    bool operator()(ArrayContainer *&node1, ArrayContainer *&node2){
        return node1->top() > node2->top();
    }
};


class Solution {
public:
    vector<int> mergeKLists(vector<vector<int>> &lists) {
        int size = lists.size();
        if (size == 0) return {};

        priority_queue<ArrayContainer, vector<ArrayContainer>, cmp> minHeap;

        for (auto &tmpList : lists) {
            if (tmpList.empty()) continue;
            minHeap.emplace(&tmpList);
        }

        vector<int> ret;

        while(minHeap.size()) {
            ArrayContainer ac = minHeap.top();
            minHeap.pop();
            ret.push_back(ac.top());
            ac.pop();
            if (!ac.isEmpty()) minHeap.push(ac);
        }

        return ret;
    }

    vector<int> mergeKLists2(vector<vector<int>> &lists) {
        int size = lists.size();
        if (size == 0) return {};

        priority_queue<ArrayContainer*, vector<ArrayContainer*>, cmp> minHeap;

        for (auto &tmpList : lists) {
            if (tmpList.empty()) continue;
            minHeap.push(new ArrayContainer{&tmpList});
        }

        vector<int> ret;

        while(minHeap.size()) {
            ArrayContainer *ac = minHeap.top();
            minHeap.pop();
            ret.push_back(ac->top());
            ac->pop();
            if (!ac->isEmpty()) minHeap.push(ac);
            else delete ac;
        }

        return ret;
    }
};



void test(){
    Solution s;
    vector<vector<int>> updates{{0, 5},{4, 10, 100},{3, 20, 23, 78}};
    vector<int> result = s.mergeKLists2(updates);
    for (auto &num : result)
        cout << num <<" ";
    cout << endl;
}