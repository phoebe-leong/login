/**
 * @file login.cpp
 * @author Phoebe Leong (dariusleong8@gmail.com)
 * @brief A simple login project
 * @version 0.1
 * @date 28-02-21
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <string>
#include "login.h"
using namespace std;

// uwu :3

int menuSelect;
std::string password = "password";
std::string loginInput;
std::string usernameInput;
std::string username = "user";


int close() {
    return 3;
}

void login() {
    std::cout << "-------------------------------------------\n\n";
    std::cout << "             Enter your username           \n\n";
    std::cout << "-------------------------------------------\n\n";
    std::cin >> usernameInput;
    std::cout << "\n\n";

    std::cout << "-------------------------------------------\n\n";
    std::cout << "             Enter your password           \n\n";
    std::cout << "-------------------------------------------\n\n";
    std::cin >> loginInput;

    if (loginInput == password && usernameInput == username) {
        std::cout << "Logging you in...";
        std::cout << "Logged in as" << username;
    } else {
        std::cout << "Your password is incorrect.\n\n";
        menu();
    }
}

void signup() {
    std::cout << "-------------------------------------------\n\n";
    std::cout << "             Enter your new username       \n\n";
    std::cout << "-------------------------------------------\n\n";
    std::cin >> username;
    std::cout << "-------------------------------------------\n\n";
    std::cout << "           Enter your new password         \n\n";
    std::cout << "-------------------------------------------\n\n";
    std::cin >> password;
    std::cout << "\n\n Your new password is " << password << " and your username is " << username << ".\n\n";
}

void menu() {
    std::cout << "-------------------------------------------\n\n";
    std::cout << "                  Login [1]                  \n";
    std::cout << "                 Sign Up [2]                 \n";
    std::cout << "             Close the program [3]         \n\n";
    std::cout << "-------------------------------------------\n\n";
    std::cin >> menuSelect;

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
        std::cout << "You entered an incorrect number. Select one of the three.\n\n";
        menu();
    }
} 

int main() {
    std::cout << "Designed & Developed by PH03be.\n\n";
    menu();
}