#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// ===== REGISTRATION FUNCTION =====
void registerUser() {
    string username, password;

    cout << "\n===== REGISTRATION =====" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check for duplicate username
    ifstream checkFile("users.txt");
    string storedUser, storedPass;

    while (checkFile >> storedUser >> storedPass) {
        if (storedUser == username) {
            cout << "Username already exists! Try another." << endl;
            checkFile.close();
            return;
        }
    }
    checkFile.close();

    // Save to files
    ofstream outFile("users.txt", ios::app);  // append mode
    outFile << username << " " << password << endl;
    outFile.close();

    cout << "Registration successful!" << endl;
}

// ===== LOGIN FUNCTION =====
void loginUser() {
    string username, password;

    cout << "\n===== LOGIN =====" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream inFile("users.txt");
    string storedUser, storedPass;
    bool found = false;

    while (inFile >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            found = true;
            break;
        }
    }
    inFile.close();

    if (found)
        cout << "Login successful! Welcome, " << username << "!" << endl;
    else
        cout << "Invalid username or password!" << endl;
}

// ===== MAIN MENU =====
int main() {
    int choice;

    do {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: registerUser(); break;
        case 2: loginUser();    break;
        case 3: cout << "Goodbye!" << endl; break;
        default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}