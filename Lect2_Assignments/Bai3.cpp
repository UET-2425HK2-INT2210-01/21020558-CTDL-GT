#include <iostream>
#include <list>
using namespace std;

int count_triplets(list<int>& linkedList) {
    if (linkedList.size() < 3) return 0;
    
    int count = 0;
    list<int>::iterator prev = linkedList.begin();
    list<int>::iterator curr = prev;
    ++curr;
    list<int>::iterator next = curr;
    ++next;
    
    while (next != linkedList.end()) {
        if (*prev + *curr + *next == 0) {
            count++;
        }
        ++prev;
        ++curr;
        ++next;
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    list<int> linkedList;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        linkedList.push_back(x);
    }
    
    cout << count_triplets(linkedList) << endl;
    
    return 0;
}
