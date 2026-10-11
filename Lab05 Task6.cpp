#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> inStack;
    stack<int> outStack;

public:
    void enqueue(int value) {
        inStack.push(value);
    }

    int dequeue() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        if (outStack.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        int value = outStack.top();
        outStack.pop();

        return value;
    }
};

int main() {
    MyQueue q;

    q.enqueue(1);  // A
    q.enqueue(2);  // B

    cout << "Dequeued: " << char('A' + q.dequeue() - 1) << endl;

    q.enqueue(3);  // C

    cout << "Dequeued: " << char('A' + q.dequeue() - 1) << endl;
    cout << "Dequeued: " << char('A' + q.dequeue() - 1) << endl;

    return 0;
}
