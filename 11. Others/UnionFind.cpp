class UnionFind{
private:
    vector<int> m_items;
    int m_size;

    int getRout(int val){
        while (m_items[val] != val) {
            int tmp = m_items[val];
            m_items[val] = m_items[tmp];
            val = tmp;
        }
        return val;
    }

public:
    UnionFind(int size):m_size{size}{
        for (int i = 0; i < m_size; i++){
            m_items.push_back(i);
        }       
    }

    void union(int val1, int val2) {
        if (val1 >= m_size || val2 >= m_size || val1 < 0 || val2 < 0)
            return;
        int root1 = getRout(val1);
        int root2 = getRout(val2);
        m_items[root1] = root2;
    }

    bool find(int val1, int val2) {
        if (val1 >= m_size || val2 >= m_size || val1 < 0 || val2 < 0)
            return false;
        return getRout(val1) == getRout(val2);
    }
}