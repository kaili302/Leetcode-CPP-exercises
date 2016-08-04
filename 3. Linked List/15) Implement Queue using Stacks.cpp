class Queue {
private:
	std::stack<int> main;
	std::stack<int> alt;

	void mainToAlt() {
		while (!main.empty()) {
			alt.push(main.top());
			main.pop();
		}
	}

public:
    // Push element x to the back of queue.
    void push(int x) {
    	main.push(x);    
    }

    // Removes the element from in front of queue.
    void pop(void) {
		if (alt.empty()) mainToAlt();			
		if (!alt.empty()) alt.pop();
    }

    // Get the front element.
    int peek(void) {
        if (alt.empty()) mainToAlt();	
        // No exception case
     	return alt.top();   
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return main.empty() && alt.empty();
    }

};