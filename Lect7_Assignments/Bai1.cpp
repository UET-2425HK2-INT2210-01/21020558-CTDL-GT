#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("numbers.txt");
    ofstream output("numbers.sorted");

    vector<double> numbers;
    double num;

    // ??c cac s? th?c t? file input
    while (input >> num) {
        numbers.push_back(num);
    }

    // S?p x?p cac s? theo th? t? t?ng d?n
    sort(numbers.begin(), numbers.end());

    // Ghi k?t qu? ra file output, cach nhau b?ng d?u cach
    for (size_t i = 0; i < numbers.size(); ++i) {
        output << numbers[i];
        if (i != numbers.size() - 1) {
            output << " ";
        }
    }

    input.close();
    output.close();

    cout << "?a s?p x?p va ghi vao file 'numbers.sorted'.\n";
    return 0;
}
