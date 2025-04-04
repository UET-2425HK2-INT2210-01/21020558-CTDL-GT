#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ham heapify t?i index i (Min-Heap)
void heapify(vector<int>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;   // con trai
    int right = 2 * i + 2;  // con ph?i

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Xay d?ng Min-Heap t? m?ng ban ??u
void buildMinHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}

// Them ph?n t? m?i vao heap
void insertValue(vector<int>& heap, int value) {
    heap.push_back(value);
    int i = heap.size() - 1;
    // S?a l?i heap t? d??i len
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Xoa ph?n t? b?t k? kh?i heap
void deleteValue(vector<int>& heap, int value) {
    int n = heap.size();
    auto it = find(heap.begin(), heap.end(), value);
    if (it == heap.end()) return;  // Khong tim th?y
    int index = it - heap.begin();

    // ??a ph?n t? c?n xoa v? cu?i r?i pop_back
    heap[index] = heap.back();
    heap.pop_back();
    buildMinHeap(heap);
}

// In heap theo c?p ?? (level order)
void printHeap(const vector<int>& heap) {
    for (int val : heap)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> heap = {2, 1, 10, 6, 3, 8, 7, 13, 20};

    cout << "Heap ban dau: ";
    buildMinHeap(heap);
    printHeap(heap);

    // Them cac gia tr?: 14, 0, 35
    insertValue(heap, 14);
    insertValue(heap, 0);
    insertValue(heap, 35);

    cout << "Sau khi chen 14, 0, 35: ";
    printHeap(heap);

    // Xoa cac gia tr?: 6, 13, 35
    deleteValue(heap, 6);
    deleteValue(heap, 13);
    deleteValue(heap, 35);

    cout << "Sau khi xoa 6, 13, 35: ";
    printHeap(heap);

    return 0;
}
