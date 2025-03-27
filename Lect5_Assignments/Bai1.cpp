#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// Khai bao cau truc du lieu cho cay
struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x) : val(x) {}
};

// Tim nut goc cua cay
TreeNode* findRoot(map<int, TreeNode*>& nodes, set<int>& children) {
    for (auto& pair : nodes) {
        if (children.find(pair.first) == children.end()) {
            return pair.second;
        }
    }
    return nullptr;
}

// Tinh chieu cao cua cay
int treeHeight(TreeNode* root) {
    if (!root) return 0;
    int maxHeight = 0;
    for (auto child : root->children) {
        maxHeight = max(maxHeight, treeHeight(child));
    }
    return maxHeight + 1;
}

// Duyet tien tu
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    for (auto child : root->children) {
        preorder(child);
    }
}

// Duyet hau tu
void postorder(TreeNode* root) {
    if (!root) return;
    for (auto child : root->children) {
        postorder(child);
    }
    cout << root->val << " ";
}

// Kiem tra cay nhi phan va duyet trung tu
bool isBinaryTree(TreeNode* root, map<int, TreeNode*>& nodes, vector<int>& inorder) {
    if (!root) return true;
    if (root->children.size() > 2) return false;
    
    if (root->children.size() > 0) {
        if (!isBinaryTree(root->children[0], nodes, inorder)) return false;
    }
    inorder.push_back(root->val);
    if (root->children.size() > 1) {
        if (!isBinaryTree(root->children[1], nodes, inorder)) return false;
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    map<int, TreeNode*> nodes;
    set<int> children;
    
    // Tao cac nut
    for (int i = 1; i <= N; i++) {
        nodes[i] = new TreeNode(i);
    }
    
    // Doc cac canh
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        nodes[u]->children.push_back(nodes[v]);
        children.insert(v);
    }
    
    // Tim nut goc
    TreeNode* root = findRoot(nodes, children);
    
    // Tinh chieu cao cua cay
    cout << treeHeight(root) - 1 << endl;
    
    // In duyet tien tu
    preorder(root);
    cout << endl;
    
    // In duyet hau tu
    postorder(root);
    cout << endl;
    
    // Kiem tra cay nhi phan va in duyet trung tu
    vector<int> inorder;
    if (isBinaryTree(root, nodes, inorder)) {
        for (int val : inorder) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }
    
    // Giai phong bo nho
    for (auto& pair : nodes) {
        delete pair.second;
    }
    
    return 0;
}