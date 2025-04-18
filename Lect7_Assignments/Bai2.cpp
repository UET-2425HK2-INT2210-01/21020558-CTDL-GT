#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

// Ham tim ?o?n con co t?ng l?n nh?t trong 1 chi?u
void kadane(const vector<int>& arr, int& start, int& finish, int& max_sum) {
    int sum = 0, local_start = 0;
    max_sum = INT_MIN;
    finish = -1;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if (sum < arr[i]) {
            sum = arr[i];
            local_start = i;
        }
        if (sum > max_sum) {
            max_sum = sum;
            start = local_start;
            finish = i;
        }
    }
}

int main() {
    ifstream input("matrix.txt");
    ofstream output("matrix.out");

    int m, n;
    input >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            input >> matrix[i][j];

    int max_sum = INT_MIN;
    int final_r1, final_c1, final_r2, final_c2;

    for (int top = 0; top < m; ++top) {
        vector<int> temp(n, 0);

        for (int bottom = top; bottom < m; ++bottom) {
            for (int col = 0; col < n; ++col) {
                temp[col] += matrix[bottom][col];
            }

            int c1, c2, sum;
            kadane(temp, c1, c2, sum);

            if (sum > max_sum) {
                max_sum = sum;
                final_r1 = top;
                final_r2 = bottom;
                final_c1 = c1;
                final_c2 = c2;
            }
        }
    }

    // Xu?t k?t qu? theo format: r1 c1 r2 c2 s (s? dong/c?t tinh t? 1)
    output << final_r1 + 1 << " " << final_c1 + 1 << " "
           << final_r2 + 1 << " " << final_c2 + 1 << " " << max_sum << endl;

    input.close();
    output.close();

    cout << "?a ghi k?t qu? vao file 'matrix.out'.\n";
    return 0;
}
