#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }
    
    int count = 0;
    for (map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        int f = it->second;
        count += (f * (f - 1)) / 2; // Công th?c tính s? c?p
    }
    
    cout << count << endl;
    return 0;
}

