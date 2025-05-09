#include <iostream>
#include <vector>
using namespace std;

// Ham de quy de kiem tra co ton tai tap con co tong bang X khong
bool checkSubsetSum(const vector<int>& ages, int index, int target) {
    if (target == 0) return true; // Neu tong can tim bang 0 => da tim ra tap con
    if (index == ages.size() || target < 0) return false; // Het hoc sinh hoac tong am => khong hop le

    // 2 lua chon: chon hoac khong chon hoc sinh tai vi tri 'index'
    // Chon hoc sinh nay
    if (checkSubsetSum(ages, index + 1, target - ages[index])) return true;

    // Khong chon hoc sinh nay
    if (checkSubsetSum(ages, index + 1, target)) return true;

    return false; // Khong co cach nao thoa man
}

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> ages(n);

    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }

    if (checkSubsetSum(ages, 0, X)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}


