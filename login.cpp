/**
 * @file login.cpp
 * @author PH03be (phoebeleong8@gmail.com)
 * @brief A simple login project
 * @version 0.1
 * @date 28-02-21
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <fstream>
#include <string>
#include "login.h"
using namespace std;

int menuSelect;
string username = "fjfjdjdj";
string password = "asjfjfjfj";
string usernameInput;
string loginInput;


// Find a secure hashing algorithm? - SHA-256?

int close() {
    return 0;
}

void save() {

}

void menu() {
    cout << "-------------------------------------------\n\n";
    cout << "                  Login [1]                  \n";
    cout << "                 Sign Up [2]                 \n";
    cout << "             Close the program [3]         \n\n";
    cout << "-------------------------------------------\n\n";
    cin >> menuSelect;

    switch (menuSelect) {
        case 1:
        login();
        break;
        case 2:
        signup();
        break;
        case 3:
        close();
        break;
        default:
        cout << "You entered an incorrect number. Select one of the three.\n\n";
        menu();
    }
}

void login() {
    cout << "-------------------------------------------\n\n";
    cout << "             Enter your username           \n\n";
    cout << "-------------------------------------------\n\n";
    cin >> usernameInput;
    cout << "\n\n";

    cout << "-------------------------------------------\n\n";
    cout << "             Enter your password           \n\n";
    cout << "-------------------------------------------\n\n";
    cin >> loginInput;

    if (loginInput == password && usernameInput == username) {
        cout << "Logging you in...";
        cout << "Logged in as" << username;
    } else {
        cout << "Your password is incorrect.\n\n";
        menu();
    }
}

void signup() {
    cout << "-------------------------------------------\n\n";
    cout << "             Enter your new username       \n\n";
    cout << "-------------------------------------------\n\n";
    cin >> username;
    cout << "-------------------------------------------\n\n";
    cout << "           Enter your new password         \n\n";
    cout << "-------------------------------------------\n\n";
    cin >> password;
    cout << "Your username and password have been changed successfully!\n";
    menu();
} 

int main() {
    cout << "";
    cout << "Designed (badly) and Developed (badly) by PH03be\n";
    cout << "#currentlyconsideringotherskills";
}
