#include <iostream>
using namespace std;

// Dinh nghia mot node trong danh sach lien ket
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Lop danh sach lien ket don
class LinkedList {
private:
    Node* head; // Con tro den dau danh sach
public:
    LinkedList() : head(nullptr) {}

    // Ham chen phan tu vao cuoi danh sach
    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Ham tim kiem vi tri dau tien cua phan tu x trong danh sach
    void search(int x) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == x) {
                cout << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "NO" << endl;
    }

    // Ham dao nguoc danh sach lien ket
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Ham in danh sach lien ket
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Ham huy danh sach lien ket
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "append") {
            int x;
            cin >> x;
            list.append(x);
        } else if (command == "search") {
            int x;
            cin >> x;
            list.search(x);
        } else if (command == "reverse") {
            list.reverse();
        }
    }

    list.printList();
    return 0;
}

