#include <iostream>
#include <vector>
using namespace std;

// Hoare Partition
int hoarePartition(vector<float> &arr, int low, int high) {
    float pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            ++i;
        } while (arr[i] < pivot);
        do {
            --j;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSortHoare(vector<float> &arr, int low, int high) {
    if (low < high) {
        int pi = hoarePartition(arr, low, high);
        quickSortHoare(arr, low, pi);
        quickSortHoare(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<float> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    quickSortHoare(arr, 0, n - 1);

    for (float x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}
