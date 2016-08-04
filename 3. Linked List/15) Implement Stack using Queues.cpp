class Stack {
private:
    std::queue<int> main;
    std::queue<int> alt;
public:
    // Push element x onto stack.
    void push(int x) {
        if (main.empty()) alt.push(x);
        else main.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (empty()) return;
        if (main.empty()) {
            while (alt.size()>1) {
                main.push(alt.front());
                alt.pop();
            }
            alt.pop();
        }else if(alt.empty()) {
            while (main.size()>1) {
                alt.push(main.front());
                main.pop();
            }
            main.pop();
        }
    }

    // Get the top element.
    int top() {
        int result;
        if (main.empty()) {
            while (alt.size()>1) {
                main.push(alt.front());
                alt.pop();
            }
            result=alt.front();
            main.push(result);
            alt.pop();
        }else if(alt.empty()) {
            while (main.size()>1) {
                alt.push(main.front());
                main.pop();
            }
            result=main.front();
            alt.push(result);
            main.pop();
        }
        return result;
    }

    // Return whether the stack is empty.
    bool empty() {
        return main.empty() && alt.empty();
    }
};