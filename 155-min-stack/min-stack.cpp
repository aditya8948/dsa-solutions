class MinStack {
public:
    stack<long long > s;
    long long  currMin ;
    MinStack() {
    
    }
    
    void push(int value) {
        if(s.empty()){
            currMin = value;
            s.push(value);
        }
        else if(value < currMin){
            s.push(2ll * value - currMin);
            currMin = value;
        }
        else {
            s.push(value);
        }

    }
    
    void pop() {
        if(!s.empty() && s.top() < currMin) {
            currMin = (2ll * currMin - s.top());
            s.pop();
        }
        else if(!s.empty()) {
            s.pop();
        }
    }
    
    int top() {
        int element ;
       if(!s.empty() && s.top() < currMin) element = currMin; 
       else if(!s.empty()) element = s.top();
       return element;
    }
    
    int getMin() {
        if(!s.empty()) return currMin;
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */