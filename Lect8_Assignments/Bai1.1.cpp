#include <iostream>
#include <vector>
using namespace std;

// Ham hoan ??i 2 ph?n t?
void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

// Ham chia m?ng (partition)
int partition(vector<float> &arr, int low, int high) {
    float pivot = arr[high];  // ch?n ph?n t? cu?i lam pivot
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Ham Quick Sort
void quickSort(vector<float> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // ch? s? chia m?ng
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<float> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (float x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}
