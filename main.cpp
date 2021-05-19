/* 
 * v2.6
 */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

// variable declarations

std::string username;
std::string password;

std::ifstream fileRead;

// function declarations

void menu();
void login();
void signup();
int close();

int close() {
    std::cout << "Press enter to exit the program\n";
    std::cin.ignore();
    std::cin.get();
    system("clear");
    return 0;
}

void menu() {
    std::string menuSelect;

    std::cout << "-------------------------------------------\n\n";

    // if the user has no login data or the data.txt file doesn't exist, show this

    if (username == "" && password == "") {
        std::cout << "                 Sign Up [1]                 \n";
        std::cout << "             Close the program [2]         \n\n";
        std::cout << "-------------------------------------------\n";
        std::cin >> menuSelect;

        if (menuSelect == "1") {
            system("clear");
            std::cin.ignore();
            signup();
        } else if (menuSelect == "2") {
            system("clear");
            close();
        } else {
            system("clear");
            std::cout << "You entered an incorrect character. Select one that is presented.\n";
            std::cin.ignore();
            std::cin.get();
            system("clear");
            menu();
        }

        // if the user has existing login data then show this    

    } else {
        std::cout << "                  Login [1]                  \n";
        std::cout << "           Change Login Details [2]          \n";
        std::cout << "             Close the program [3]         \n\n";
        std::cout << "-------------------------------------------\n";
        std::cin >> menuSelect;

        if (menuSelect == "1") {
            system("clear");
            login();
        } else if (menuSelect == "2") {
            system("clear");
            std::cin.ignore();
            signup();
        } else if (menuSelect == "3") {
            system("clear");
            close();
        } else {
            system("clear");
            std::cout << "You entered an incorrect number. Select one of the three.\n";
            std::cin.ignore();
            std::cin.get();
            system("clear");
            menu();
        }
    }
}

void login() {
    std::string usernameInput;
    std::string loginInput;

    // assign the variables the lines using getline
    fileRead.open("data.txt");
    getline(fileRead, username);
    getline(fileRead, password);
    fileRead.close();

    std::cout << "-------------------------------------------\n\n";
    std::cout << "             Enter your username           \n\n";
    std::cout << "-------------------------------------------\n";
    getline(std::cin, usernameInput);
    system("clear");

    std::cout << "-------------------------------------------\n\n";
    std::cout << "             Enter your password           \n\n";
    std::cout << "-------------------------------------------\n";
    std::cin >> loginInput;
    system("clear");

    if (usernameInput == username && loginInput == password) {
        std::cout << "Successfully logged in\n";
        std::cin.ignore();
        std::cin.get();
        system("clear");

        /*
         * Change line 130 to launch your program that you are using this for
         * E.g.:
         * 1.
         * system(g++ yourProgramHere);
         * system(./a.out);
         * 
         * 2.
         * system(./yourProgramHere);
        */

        menu();
    } else {
        std::cout << "Incorrect password and/or username. Please try again\n";
        std::cin.ignore();
        std::cin.get();
        system("clear");
        login();
    }
}

void signup() {

    std::ofstream file;
    std::string newUsername;
    std::string newPassword;

    std::cout << "-------------------------------------------\n\n";
    std::cout << "             Enter your new username       \n\n";
    std::cout << "-------------------------------------------\n";
    getline(std::cin, newUsername);
    system("clear");
    std::cout << "-------------------------------------------\n\n";
    std::cout << "           Enter your new password         \n\n";
    std::cout << "-------------------------------------------\n";
    std::cin >> newPassword;

    if (newUsername == username || newPassword == password && newUsername == username || newPassword == password) {
        system("clear");
        std::cout << "Password does not meet the requirements.\n";
        std::cout << "You may view the requirements at https://phoebe-leong.github.io/req/index.html\n";
        std::cin.ignore();
        std::cin.get();
        system("clear");
        signup();
    } else if (newPassword.size() < 8) {
        system("clear");
        std::cout << "Password and/or username does not meet the requirements.\n";
        std::cout << "You may view the requirements at https://phoebe-leong.github.io/req/index.html\n";
        std::cin.ignore();
        std::cin.get();
        system("clear");
        signup();
    }

    // trying to make it as secure as possible without making it secure cause i dont know how

    int passwordNumberCheck;

    for (int i; i < newPassword.size(); i++) {
        if (isdigit(newPassword[i]) == false) {
            passwordNumberCheck++;
        } 
    }

    if (passwordNumberCheck == newPassword.size()) {
        system("clear");
        std::cout << "Password and/or username does not meet the requirements.\n";
        std::cout << "You may view the requirements at https://ph03be.glitch.me/login-github-project/passwordreqs.html\n";
        std::cin.ignore();
        std::cin.get();
        system("clear");
        signup();
    }

    int upperCasePasswordCheck;

    for (int i; i < newPassword.size(); i++) {
        if (isupper(newPassword[i]) == false) {
            upperCasePasswordCheck++;
        }
    }

    if (upperCasePasswordCheck == newPassword.size()) {
        system("clear");
        std::cout << "Password and/or username does not meet the requirements.\n";
        std::cout << "You may view the requirements at https://ph03be.glitch.me/login-github-project/passwordreqs.html\n";
        std::cin.ignore();
        std::cin.get();
        system("clear");
        signup();
    }

    username = newUsername;
    password = newPassword;

    file.open("data.txt");
    file << username << "\n";
    file << password;
    file.close();

    system("clear");
    std::cout << "Your username and password have been changed successfully!\n";
    std::cin.ignore();
    std::cin.get();
    system("clear");
    menu();
} 

int main() {
    std::srand(std::time(nullptr));

    fileRead.open("data.txt");

    getline(fileRead, username);
    getline(fileRead, password);
    fileRead.close();

    system("clear");
    menu();
}
