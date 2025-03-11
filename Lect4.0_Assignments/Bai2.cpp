#include <iostream>
#include <string>

using namespace std;

// Cau truc mot nut trong danh sach lien ket doi
struct Node {
    int value; // Gia tri phan tu
    int priority; // Do uu tien
    Node* next; // Con tro den nut ke tiep
    Node* prev; // Con tro den nut truoc do

    Node(int v, int p) : value(v), priority(p), next(nullptr), prev(nullptr) {}
};

// Lop hang doi uu tien su dung danh sach lien ket doi
class PriorityQueue {
private:
    Node* head; // Con tro dau danh sach
public:
    PriorityQueue() : head(nullptr) {}

    // Ham them phan tu vao danh sach theo thu tu uu tien
    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);

        // Neu danh sach rong hoac phan tu moi co uu tien cao hon head
        if (!head || priority > head->priority) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }

        // Tim vi tri thich hop de chen
        Node* temp = head;
        while (temp->next && temp->next->priority >= priority) {
            temp = temp->next;
        }

        // Chen nut moi vao danh sach
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Ham loai bo phan tu co uu tien cao nhat khoi danh sach
    void dequeue() {
        if (!head) return; // Neu danh sach rong, khong lam gi

        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    // Ham in danh sach theo dinh dang (value, priority)
    void printQueue() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->value << ", " << temp->priority << ")";
            if (temp->next) cout << "; ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n; // Doc so thao tac
    cin.ignore(); // Loai bo ki tu xuong dong

    PriorityQueue pq;

    for (int i = 0; i < n; i++) {
        string command;
        getline(cin, command);

        if (command.substr(0, 7) == "enqueue") {
            int x, p;
            sscanf(command.c_str(), "enqueue %d %d", &x, &p);
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }

    // In ket qua cuoi cung
    pq.printQueue();

    return 0;
}

