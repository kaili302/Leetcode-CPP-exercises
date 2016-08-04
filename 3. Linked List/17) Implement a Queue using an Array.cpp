/*Implement a Queue using an Array in CPP */

class MyQueue {
private:
    int *m_array;
    int m_size;
    int m_head;
    int m_tail;
    int m_capacity;

public:
    MyQueue(int capacity): m_capacity{capacity}, m_size{0}, m_head{0}, m_tail{1} {
        m_array = new int[m_capacity];
    }
    ~MyQueue() {
        delete[] m_array;
    }

    bool push (int item) {
        if (isFull()) return false;
        m_tail = (m_tail-1+m_capacity)%m_capacity;
        m_array[m_tail] = item;
        m_size++;
        return true;
    }

    bool pop () {
        if (isEmpty()) return false;
        m_head=(m_head-1+m_capacity)%m_capacity;
        m_size--;
        return true;
    }

    int front() {
        if (isEmpty()) return -1;
        return m_array[m_head];
    }

    bool isFull() {
        return m_size == m_capacity;
    }

    bool isEmpty() {
        return m_size == 0;
    }
};