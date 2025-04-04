#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Ham t?o node m?i
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Ham chen vao BST
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Ham tim node nh? nh?t ben ph?i (inorder successor)
Node* findMin(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// Ham xoa ph?n t? trong BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node c?n xoa ???c tim th?y
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node co 2 con
        Node* temp = findMin(root->right);
        root->data = temp->data;  // Gan gia tr? inorder successor
        root->right = deleteNode(root->right, temp->data);  // Xoa node duplicate
    }
    return root;
}

// Duy?t cay inorder ?? in cay
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // B??c 1: T?o cay BST ban ??u
    int initialValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int val : initialValues)
        root = insert(root, val);

    cout << "Inorder BST ban dau: ";
    inorderTraversal(root);
    cout << endl;

    // B??c 2: Chen them 14, 0, 35
    int insertValues[] = {14, 0, 35};
    for (int val : insertValues)
        root = insert(root, val);

    cout << "Sau khi chen 14, 0, 35: ";
    inorderTraversal(root);
    cout << endl;

    // B??c 3: Xoa 6, 13, 35
    int deleteValues[] = {6, 13, 35};
    for (int val : deleteValues)
        root = deleteNode(root, val);

    cout << "Sau khi xoa 6, 13, 35: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
