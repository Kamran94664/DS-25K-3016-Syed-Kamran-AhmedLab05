#include <iostream>
using namespace std;

class CircularQueue {
    int arr[6];
    int front, rear, count;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == 6;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int id) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }

        if (isEmpty())
            front = 0;

        rear = (rear + 1) % 6;
        arr[rear] = id;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        int id = arr[front];

        if (count == 1) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 6;
        }

        count--;
        return id;
    }

    void display() {
        cout << "\nFinal passengers in boarding order: ";

        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % 6] << " ";

        cout << "\nFront index: " << front;
        cout << "\nRear index: " << rear << endl;
    }
};

int main() {
    CircularQueue q;

    // Six initial passengers arrive
    for (int i = 101; i <= 106; i++)
        q.enqueue(i);

    // Board the first three passengers
    for (int i = 0; i < 3; i++)
        cout << "Boarded: " << q.dequeue() << endl;

    // Three new passengers arrive
    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    // Board two passengers
    for (int i = 0; i < 2; i++)
        cout << "Boarded: " << q.dequeue() << endl;

    // One new passenger arrives
    q.enqueue(110);

    // Board one passenger
    cout << "Boarded: " << q.dequeue() << endl;

    // Two new passengers arrive
    q.enqueue(111);
    q.enqueue(112);

    q.display();

    return 0;
}
