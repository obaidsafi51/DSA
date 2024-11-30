#include <iostream>
#include <string>
using namespace std;

class student {
    int regNo;
    string name;
    float gpa;

public:
    void setter();
    void getter();
    int getreg() {
        return regNo;
    }
};

void student::setter() {
    cout << "Please enter your regNo : " << endl;
    cin >> regNo;
    cout << "Please enter your name : " << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter your gpa : " << endl;
    cin >> gpa;
}

void student::getter() {
    cout << "Your regNo is : " << regNo << endl;
    cout << "Your name is : " << name << endl;
    cout << "Your GPA is : " << gpa << endl;
}

void readData(student s[], int& n) {
    int num;
    cout << "Enter the number of records that you want : " << endl;
    cin >> num;
    for (int i = n; i < n + num; i++) {
        s[i].setter();
        s[i].getter();
    }
    n += num;
}
//end of readData function

//Start of append data function

void appendRecord(student s[], int& n) {
    s[n].setter();
    n++;
}//end of appendRecord function

//Start of search function 

int searchRecord(student s[], int n, int search) {

    for (int i = 0; i < n; i++) {
        if (search == s[i].getreg()) {
            cout << "Record found " << endl;
            s[i].getter();
            return i;
        }
    }
    return -1;
}

void updateRecord(student s[], int pos) {
    s[pos].setter();
}

void deleteRecord(student s[], int& n, int pos) {
    for (int i = pos; i < n - 1; i++) {
        s[i] = s[i + 1];
    }
    n--;
}


int main() {
    student s[3];
    int search, pos, ch;
    int n = 0;

    do {
        cout
            << "1. Create student database " << endl
            << "2. Append record " << endl
            << "3. Search record " << endl
            << "4. Update record " << endl
            << "5. Delete the record " << endl
            << "6. Exit " << endl;

        cout << "Enter the choice " << endl;
        cin >> ch;

        switch (ch) {
        case 1:
            if (n >= 3)
                cout << "Data overflow " << endl;
            else
                readData(s, n);
            break;
        case 2:
            appendRecord(s, n);
            break;
        case 3:
            cout << "Enter the reg No " << endl;
            cin >> search;
            pos = searchRecord(s, n, search);
            /*cout << "Your record is : " << endl;
            cout << pos << endl;*/
            if (pos == -1) {
                cout << "Record Not Found! " << endl;
             }
            break;
        case 4:
            cout << "Enter RegNo : " << endl;
            cin >> search;
            pos = searchRecord(s, n, search);

            if (pos != -1) {
                updateRecord(s, pos);
            }

            break;
        case 5:
            cout << "Enter the RegNo : " << endl;
            cin >> search;
            pos = searchRecord(s, n, search);
            if (pos != -1) {
                deleteRecord(s, n, pos);
            }

            break;
        case 6:
            break;
        default:
            cout << "Invalid choice" << endl;
        }

    } while (ch != 6);

    return 0;
}
