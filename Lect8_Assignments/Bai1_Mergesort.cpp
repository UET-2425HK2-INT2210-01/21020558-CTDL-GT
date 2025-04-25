#include <iostream>
#include <vector>
using namespace std;

// Ham tr?n hai n?a c?a m?ng ?a ???c s?p x?p
void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // T?o cac m?ng t?m th?i
    vector<double> L(n1), R(n2);
    
    // Sao chep d? li?u vao cac m?ng t?m th?i
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Tr?n cac m?ng t?m th?i l?i v?i nhau
    int i = 0;  // Ch? s? ban ??u c?a m?ng con ??u tien
    int j = 0;  // Ch? s? ban ??u c?a m?ng con th? hai
    int k = left;  // Ch? s? ban ??u c?a m?ng ?a ???c tr?n
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Sao chep cac ph?n t? con l?i c?a L[] n?u co
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Sao chep cac ph?n t? con l?i c?a R[] n?u co
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Ham Merge Sort
void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        // Tim ?i?m gi?a
        int mid = left + (right - left) / 2;
        
        // S?p x?p n?a ??u va n?a sau
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Tr?n hai n?a ?a s?p x?p
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Ap d?ng merge sort
    mergeSort(arr, 0, n - 1);
    
    // In k?t qu?
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}