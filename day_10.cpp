#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        _top = 0;
        _min = INT32_MIN;
        _prev_min = INT32_MAX;
    }
    
    void push(int x) {
        _stack.insert(std::make_pair(_top , x));
        if(mins.empty() || mins.top() >= x)
        {
           mins.push(x);
        }
        _top++;
    }
    void pop() {
    
        auto  elem = _stack[_top - 1];
        if(elem == mins.top())
        {
            mins.pop();
        }
        _stack.erase(_top - 1);
        _top--;
    }
    int top() {
        auto x =  _stack[_top - 1];
        return x;
    }
    
    int getMin() {
        if(_top == 0)
        {
            return INT32_MIN;
        }
        return mins.top();
    }

private:
    int _top;
    int _min;
    int _prev_min;
    std::unordered_map<int , int> _stack;
    std::stack<int> mins;
};


int main(void)
{
    MinStack *m = new MinStack();
    m->push(3);
    m->push(4);
    m->push(5);
    m->push(6);
    m->push(7);
    std::cout << m->top() << std::endl;
    m->pop();
    std::cout << m->top() << std::endl;
    m->pop();
    std::cout << m->top() << std::endl;
    std::cout << m->getMin() << std::endl;
    m->push(-2);
    std::cout << m->getMin() << std::endl;

    delete(m);
    
    return 0;
}
