#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> linkedList;
    
    for (int i = 0; i < n; i++) {
        string op;
        int p, x;
        cin >> op >> p;
        
        if (op == "insert") {
            cin >> x;
            list<int>::iterator it = linkedList.begin();
            advance(it, p);
            linkedList.insert(it, x);
        } else if (op == "delete") {
            list<int>::iterator it = linkedList.begin();
            advance(it, p);
            if (it != linkedList.end()) {
                linkedList.erase(it);
            }
        }
    }
    
    for (list<int>::iterator it = linkedList.begin(); it != linkedList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}

