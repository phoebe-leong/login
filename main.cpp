/* 
 * v3.1
 */

#include <iostream>
#include <fstream>
#include <string>
#include "cryptor/cryptor.hpp"

// variable declarations

std::string username;
std::string password;
std::ifstream fileRead;

std::string reqURL = "https://phoebe-leong.github.io/login-proj/req/index.html";

std::string decryptedUsername;
std::string decryptedPassword;

// function declarations

int menu();
void login();
void signup();

int menu() {
    std::string menuSelect;

    std::cout << "-------------------------------------------\n\n";

    // if the user has no login data or the data.txt file doesn't exist, show this

    if (username.empty() && password == "") {
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

            return 0;
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
            std::cin.ignore();
            login();
        } else if (menuSelect == "2") {
            system("clear");
            std::cin.ignore();
            signup();
        } else if (menuSelect == "3") {
            system("clear");

            return 0;
        } else {
            system("clear");
            std::cout << "You entered an incorrect number. Select one of the three.\n";
            std::cin.ignore();
            std::cin.get();
            system("clear");
            menu();
        }
    }

    return 0;
}

void login() {

    fileRead.open("data.txt");
    getline(fileRead, username);
    getline(fileRead, password);
    fileRead.close();

    auto decryptedUsername = cryptor::decrypt(username);
    auto decryptedPassword = cryptor::decrypt(password);

    username = decryptedUsername;
    password = decryptedPassword;

    std::string usernameInput;
    std::string loginInput;

    std::cout << "-------------------------------------------\n\n";
    std::cout << "             Enter your username           \n\n";
    std::cout << "-------------------------------------------\n";
    std::cin >> usernameInput;
    system("clear");

    if (usernameInput != username) {
        system("clear");
        std::cout << "Incorrect Username. Press enter to try again.\n";
        std::cin.get();
        system("clear");
        login();
    }

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
         * Change the following line to launch your program that you are using this for
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
    std::cin >> newUsername;
    system("clear");
    std::cout << "-------------------------------------------\n\n";
    std::cout << "           Enter your new password         \n\n";
    std::cout << "-------------------------------------------\n";
    std::cin >> newPassword;

    if (newUsername == username || newPassword == password && newUsername == username || newPassword == password) {
        system("clear");
        std::cout << "Password does not meet the requirements.\n";
        std::cout << "You may view the requirements at " << reqURL << "\n";
        std::cin.ignore();
        std::cin.get();
        system("clear");
        signup();
    } else if (newPassword.size() < 8) {
        system("clear");
        std::cout << "Password and/or username does not meet the requirements.\n";
        std::cout << "You may view the requirements at " << reqURL << "\n";
        std::cin.ignore();
        std::cin.get();
        system("clear");
        signup();
    }

    int passwordNumberCheck;

    for (int i; i < newPassword.size(); i++) {
        if (isdigit(newPassword[i]) == false) {
            passwordNumberCheck++;
        } 
    }

    if (passwordNumberCheck == newPassword.size()) {
        system("clear");
        std::cout << "Password and/or username does not meet the requirements.\n";
        std::cout << "You may view the requirements at " << reqURL << "\n";
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
        std::cout << "You may view the requirements at " << reqURL << "\n";
        std::cin.ignore();
        std::cin.get();
        system("clear");
        signup();
    }

    username = newUsername;
    password = newPassword;

    auto encryptedUsername = cryptor::encrypt(username);
    auto encryptedPassword = cryptor::encrypt(password);

    file.open("data.txt");
    file << encryptedUsername << "\n";
    file << encryptedPassword;
    file.close();

    system("clear");
    std::cout << "Your username and password have been changed successfully!\n";
    std::cin.ignore();
    std::cin.get();
    system("clear");
    menu();
} 

int main() {

    cryptor::set_key("Jette");

    system("clear");
    menu();
}
