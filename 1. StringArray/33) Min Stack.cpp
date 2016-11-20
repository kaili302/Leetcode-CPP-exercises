class MinStack {
private:
    struct Item{
        int val;
        int min;
    };

    stack<Item*> m_s;

    bool isEmpty(){
        return m_s.empty();
    }

public:
    /** initialize your data structure here. */
    MinStack() { }
    ~MinStack() {/* delete all Items left in the stack */}
    
    void push(int x) {
        if (isEmpty() || x < getMin()) 
            m_s.push(new Item{x, x});
        else 
            m_s.push(new Item{x, getMin()});
    }
    
    void pop() {
        if (isEmpty()) return;
        delete m_s.top();
        m_s.pop();
    }
    
    int top() {
        return m_s.top()->val;
    }
    
    int getMin() {
        return m_s.top()->min;   
    }
};