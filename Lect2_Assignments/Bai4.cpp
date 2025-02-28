#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) return;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    void printQueue() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (op == "dequeue") {
            q.dequeue();
        }
    }

    q.printQueue();
    return 0;
}

