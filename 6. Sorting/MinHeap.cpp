class MinHeap{
private:
    int *m_pHeap;
    int m_end;
    int m_capacity;

    void sink(int k) {
        if (isEmpty()) return ;
        int j = k*2;
        while (j <= m_end && m_pHeap[k] > m_pHeap[j]) {
            if (j<m_end && m_pHeap[j+1] < m_pHeap[j]) j++;
            std::swap(m_pHeap[j], m_pHeap[k]);
            k = j;
            j = 2*k;
        }
    }

    void swim(int k) {
        if (isEmpty()) return ;
        int j = k/2;
        while (j>=1 && m_pHeap[j] > m_pHeap[k]) {
            std::swap(m_pHeap[j], m_pHeap[k]);
            k = j;
            j = k/2;
        }
    }

public:
    MinHeap(int capacity): m_end{0}, m_capacity{capacity}, m_pHeap{new int[capacity+1]}
    {}
    ~MinHeap(){
        delete[] m_pHeap;
    }

    void push(int val) {
        if (isFull()) {
            m_pHeap[1] = val;
            sink(1);
        }else {
            m_pHeap[++m_end] = val;
            swim(m_end);
        }
    }

    int& top(){
        return m_pHeap[1];
    }

    void pop() {
        if (isEmpty()) return;
        std::swap(m_pHeap[1], m_pHeap[m_end--]);
        sink(1);
    }

    bool isEmpty() { return m_end == 0; }

    bool size() { return m_end; }

    bool isFull() { return m_end == m_capacity; }
};


























