#include <bits/stdc++.h>
using namespace std;

class temp {
    string username, Email, password;
    string searchname, searchpassword, searchemail;
    fstream file;

public:
    void login();
    void signup();
    void forgot();
} obj;

int main() {
    while (true) {
        cout << endl << "1. Login";
        cout << endl << "2. Signup";
        cout << endl << "3. Forgot password";
        cout << endl << "4. Exit";
        cout << endl << "Enter choice: ";

        char choice;
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case '1':
                obj.login();
                break;
            case '2':
                obj.signup();
                break;
            case '3':
                obj.forgot();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Selection. Try Again." << endl;
        }
    }
}

// ------------------------- SIGNUP -------------------------
void temp::signup() {
    cout << "Enter your username:" << endl;
    getline(cin, username);
    cout << "Enter your Email:" << endl;
    getline(cin, Email);
    cout << "Enter your Password:" << endl;
    getline(cin, password);

    file.open("login.txt", ios::out | ios::app);
    file << username << '*' << Email << '*' << password << endl;
    file.close();

    cout << "Signup successful!" << endl;
}

// ------------------------- LOGIN -------------------------
void temp::login() {
    cout << "____Login____" << endl;
    cout << "Enter your username: ";
    getline(cin, searchname);
    cout << "Enter your password: ";
    getline(cin, searchpassword);

    file.open("login.txt", ios::in);
    bool found = false;

    while (getline(file, username, '*')) {
        getline(file, Email, '*');
        getline(file, password);

        if (username == searchname && password == searchpassword) {
            cout << "__Login Success__" << endl;
            cout << "Your username: " << username << endl;
            cout << "Your Email: " << Email << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Something is wrong. Please try again." << endl;
    }

    file.close();
}

// ------------------------- FORGOT -------------------------
void temp::forgot() {
    cout << "____Password Recovery____" << endl;
    cout << "Enter your username: ";
    getline(cin, searchname);
    cout << "Enter your Email: ";
    getline(cin, searchemail);

    file.open("login.txt", ios::in);
    bool found = false;

    while (getline(file, username, '*')) {
        getline(file, Email, '*');
        getline(file, password);

        if (username == searchname && Email == searchemail) {
            cout << "Your password is: " << password << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No matching account found." << endl;
    }

    file.close();
}

