#include "Screens.h"  
#include <synchapi.h>  
#include <limits>  

// Fix for the 'max' macro conflict
#ifdef max
#undef max
#endif

void Screens::printASCII(string fileName){  
    string getLine = "";  
    ifstream txtFile;  
    txtFile.open(fileName);  
    if (txtFile.is_open()) {  
        while(getline(txtFile , getLine)) {  
            cout << getLine << endl;  
        }  
    }  
    else {  
        cout << "File Not Found Try Again" << endl;  
    }  
    txtFile.close();  
}  

void Screens::logout() {  
    system("cls");  
    loginScreen(loginAs());  
}  

void Screens::welcome(){  
    Screens::printASCII(Welcome);  
    Sleep(3000);  
    system("cls");  
}  

void Screens::bankName() {  
    Screens::printASCII(WE_Bank);  
    Sleep(3000);  
    system("cls");  
}  

void Screens::loginOptions() {  
    cout << "Login as:\n";  
    cout << "(1)Admin\n";  
    cout << "(2)Employee\n";  
    cout << "(3)Client\n";  
}  

int Screens::loginAs() {
    int choice;
    while (true) {
        Screens::loginOptions();
        cout << "Please choose 1 of the 3 options: ";
        if (cin >> choice && (choice == 1 || choice == 2 || choice == 3)) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
        else {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
        }
    }
}

void Screens::invalid(int c){  
    cout << "Incorrect User ID or Password Try Again !\n";  
    loginScreen(c);  
}  

void Screens::loginScreen(int c) {
    long long id;
    string password;
    cout << "Enter a valid ID: ";
    while (!(cin >> id)) {
        cout << "Invalid ID. Please enter numbers only: ";
        cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    cout << "Enter Password: ";
    getline(cin, password); // safer than cin >> password

    switch (c) {
    case 1:
        if (AdminManager::login(id, password)) {
            while (AdminManager::adminOptions(AdminManager::login(id, password)))
                logout();
        }
        else invalid(1);
        break;
    case 2:
        if (EmployeeManager::login(id, password)) {
            while (EmployeeManager::employeeOptions(EmployeeManager::login(id, password)))
                logout();
        }
        else invalid(2);
        break;
    case 3:
        if (ClientManager::login(id, password)) {
            while (ClientManager::clientOptions(ClientManager::login(id, password)))
                logout();
        }
        else invalid(3);
        break;
    default:
        system("cls");
        loginScreen(loginAs());
    }
}


void Screens::runApp() {  
    FilesManager::getAllAdmins();  
    FilesManager::getAllEmployees();  
    FilesManager::getAllClients();  
    Screens::bankName();  
    Screens::welcome();  
    Screens::loginScreen(loginAs());  
}