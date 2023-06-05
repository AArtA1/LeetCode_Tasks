#include <iostream>
#include <stack>

class MyQueue {
public:
    MyQueue() : left(),right(){

    }

    void push(int x) {
        right.push(x);
    }

    int pop() {
        if(left.empty()){
            while(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }
        auto temp = left.top();
        left.pop();
        return temp;
    }

    int peek() {
        if(left.empty()){
            while(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }
        return left.top();
    }

    bool empty() {
        return left.empty() && right.empty();
    }
private:
    std::stack<int> left,right;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
