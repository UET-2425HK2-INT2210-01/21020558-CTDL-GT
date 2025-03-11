#include <iostream>
#include <stack>

using namespace std;

// Ham kiem tra dau ngoac mo co khop voi dau ngoac dong khong
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Ham kiem tra tinh hop le cua xau dau ngoac
bool isValidParentheses(string s) {
    stack<char> st;

    for (char c : s) {
        // Neu la dau ngoac mo thi dua vao stack
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } 
        // Neu la dau ngoac dong
        else {
            // Neu stack rong hoac ngoac khong khop, tra ve false
            if (st.empty() || !isMatching(st.top(), c)) {
                return false;
            }
            st.pop(); // Xoa cap ngoac hop le
        }
    }
    // Neu stack rong thi chuoi hop le
    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if (isValidParentheses(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}

