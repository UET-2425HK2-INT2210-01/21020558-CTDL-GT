#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(NULL) {}

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void printStack() {
        Node* temp = top;
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
    Stack s;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (op == "pop") {
            s.pop();
        }
    }

    s.printStack();
    return 0;
}

