class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int q;
    int stack_top;

public:
    MyQueue() { q = 0; }

    void push(int x) {
        while (!s1.empty()) {
            stack_top = s1.top();
            s1.pop();
            s2.push(stack_top);
        }
        s2.push(x);
        q += 1;
        while (!s2.empty()) {
            stack_top = s2.top();
            s2.pop();
            s1.push(stack_top);
        }
    }

    int pop() {
        if (s1.empty()) {
            return 0;
        }
        stack_top = s1.top();
        s1.pop();
        q -= 1;
        return stack_top;
    }

    int peek() {
        int stack_top = s1.top();
        return stack_top;
    }

    bool empty() {
        if (q <= 0) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
