#include <iostream>
#include <unordered_map>
using namespace std;

// Khai bao cau truc Student de luu tru thong tin sinh vien
struct Student {
    string name;
    string className;
};

// Khai bao unordered_map de luu danh sach sinh vien voi ID la key
unordered_map<int, Student> studentList;

// Ham them sinh vien
void Insert(int id, string name, string className) {
    studentList[id] = {name, className};
}

// Ham xoa sinh vien
void Delete(int id) {
    studentList.erase(id);
}

// Ham lay thong tin sinh vien
string Infor(int id) {
    if (studentList.find(id) != studentList.end()) {
        return studentList[id].name + "," + studentList[id].className;
    }
    return "NA,NA";
}

int main() {
    string command;
    while (getline(cin, command)) { // Doc tung lenh tu ban phim
        if (command.substr(0, 6) == "Insert") {
            int id;
            string name, className;
            sscanf(command.c_str(), "Insert(%d,%[^,],%[^)])", &id, &name[0], &className[0]);
            Insert(id, name, className);
        } else if (command.substr(0, 6) == "Delete") {
            int id;
            sscanf(command.c_str(), "Delete(%d)", &id);
            Delete(id);
        } else if (command.substr(0, 5) == "Infor") {
            int id;
            sscanf(command.c_str(), "Infor(%d)", &id);
            cout << Infor(id) << endl;
        }
    }
    return 0;
}
