#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

void reverseFirstK(queue<string>& q, int k) {
    if (k < 0 || k > (int)q.size()) {
        cout << "Invalid value of K!\n";
        return;
    }

    if (k == 0)
        return;

    stack<string> s;
    int n = q.size();

    // Put the first K elements into the stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Push them back in reversed order
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Move the remaining elements to the back
    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<string> q;

    q.push("J1");
    q.push("J2");
    q.push("J3");
    q.push("J4");
    q.push("J5");
    q.push("J6");
    q.push("J7");

    reverseFirstK(q, 3);

    cout << "Queue after reversal: ";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    return 0;
}
