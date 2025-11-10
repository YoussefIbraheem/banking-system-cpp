#include "AdminManager.h"
#include "FilesManager.h"
void AdminManager::printClientMenu()
{
	system("cls");
	cout << "(1) Display My Info\n" ;
	cout << "(2) Update Password\n" ;
	cout << "(3) Add New Client\n" ;
	cout << "(4) Search For Client\n" ;
	cout << "(5) List All Clients\n" ;
	cout << "(6) Edit Client Info\n" ;
	cout << "(7) Add New Employee\n" ;
	cout << "(8) Search For Employee\n" ;
	cout << "(9) List All Employees\n" ;
	cout << "(10) Edit Employee Info\n" ;
	cout << "(11) Logout \n\n" ;
}

Admin* AdminManager::login(int id, string password)
{
		for (admitr = allAdmins.begin(); admitr != allAdmins.end(); admitr++) {
			if (admitr->get_id() == id && admitr->get_password() == password) return admitr._Ptr;
		}
		return NULL;
}

void AdminManager::newClient(Admin* Admin) {
	Client client;
	string cltName;
	string cltPassword;
	double cltBalance;
	cout << "set Client Name\n";
	cin.ignore();
	getline(cin, cltName);
	client.set_name(Validation::name_validation(cltName));
	cout << "set Client Password\n";
	cin >> cltPassword;
	client.set_password(Validation::password_validation(cltPassword));
	cout << "set Client balance\n" ;
	cin >> cltBalance;
	client.set_balance(Validation::balance_validation(cltBalance));
	Admin->addClient(client);
}

void AdminManager::newEmployee(Admin* admin)
{
	Employee employee;
	string empName;
	string empPassword;
	double empSalary;
	cout << "Enter Employee's Name";
	cin.ignore();
	getline(cin, empName);
	employee.set_name(Validation::name_validation(empName));
	cout << "Enter Employee's Password\n" ;
	cin >> empPassword;
	employee.set_password(Validation::password_validation(empPassword));
	cout << "Enter Employee's Salary\n" ;
	cin >> empSalary;
	employee.set_salary(Validation::salary_validation(empSalary));
	admin->addEmployee(employee);
}

void AdminManager::searchForClient(Admin* Admin) {
	int id;
	system("cls");
	cout << "Enter the ID You're Looking for\n" ;
	cin >> id;
	while (!Admin->check_client(id)) {
		cout << "Client Not Found Try Again\n" ;
		cin >> id;
	}
	auto searchedClient = Admin->search_client(id);
	searchedClient->display_client();
}

Employee* AdminManager::searchForEmployee(int id) {
	system("cls");
	for (empitr = allEmployees.begin(); empitr != allEmployees.end(); empitr++) {
		if (empitr->get_id() == id) return empitr._Ptr;
	}
	return NULL;
}

void  AdminManager::editClientInfo(Admin* Admin) {
	system("cls");
	int id;
	string name;
	string password;
	double balance;

	cout << "enter Client ID\n";
	cin >> id;
	while (!Admin->check_client(id)) {
		cout << "Client Not Found Try Again\n";
		cin >> id;
	}
	cout << "Please Enter Client Name\n";
	getline(cin, name);
	cout << "Please Enter Client Password\n";
	cin >> password;
	cout << "Please Enter Client Balance\n";
	cin >> balance;
	Admin->edit_client(id, name, password, balance);
}

void updateAdminInfo() {
	FilesManager::removeAllAdmins();
	for (admitr = allAdmins.begin(); admitr != allAdmins.end(); admitr++) {
		FilesManager::addAdmin(*admitr);
	}
}

void AdminManager::editEmployeeInfo() {
	int id;
	string name, password;
	double salary;
	cout << "Enter Searched Employee Id\n";
	cin >> id;
	auto selectedEmployee = AdminManager::searchForEmployee(id);
	while (selectedEmployee == NULL) {
		cout << "ID Not Found Try Again\n";
		cin >> id;
		selectedEmployee = AdminManager::searchForEmployee(id);
	}
	cout << "Enter Employee Name\n";
	cin.ignore();
	getline(cin, name);
	selectedEmployee->set_name( Validation::name_validation(name));
	cout << "Enter Employee Password\n";
	cin >> password;
	selectedEmployee->set_password(Validation::password_validation(password));
	cout << "Enter Employee Salary\n";
	cin >> salary;
	selectedEmployee->set_salary(Validation::salary_validation(salary));
	FilesManager::removeAllEmployees();
	for (empitr = allEmployees.begin(); empitr != allEmployees.end(); empitr++) {
		FilesManager::addEmployee(*empitr);
	}
}

void AdminManager::listEmployees() {
	for (empitr = allEmployees.begin(); empitr != allEmployees.end(); empitr++) {
		empitr->display_employee();
	}
}

bool AdminManager::adminOptions(Admin* Admin)
{
	system("cls");
	AdminManager::printClientMenu();
	int choice;
	string password;
	int id;
	Employee* searchedEmployee;
	cout << "Enter The Number Of Service\n" ;
	cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		Admin->display_employee();
		break;
	case 2:
		system("cls");
		cout << "Enter New password\n" ; 
		cin >> password;
		Admin->set_password(Validation::password_validation(password));
		updateAdminInfo();
		break;
	case 3:
		system("cls");
		AdminManager::newClient(Admin);
		break;
	case 4:
		system("cls");
		AdminManager::searchForClient(Admin);
		break;
	case 5:
		system("cls");
		Admin->listClients();
		break;
	case 6:
		system("cls");
		AdminManager::editClientInfo(Admin);
		break;
	case 7:
		system("cls");
		AdminManager::newEmployee(Admin);
		break;
	case 8:
		system("cls");
		cout << "Enter Searched Employee ID\n";
		cin >> id;
		searchedEmployee = AdminManager::searchForEmployee(id);
		while (searchedEmployee == NULL) {
			cout << "ID Not Found Try Again\n";
			cin >> id;
			searchedEmployee = AdminManager::searchForEmployee(id);
		}
		searchedEmployee->display_employee();
		break;
	case 9:
		system("cls");
		AdminManager::listEmployees();
		break;
	case 10:
		system("cls");
		AdminManager::editEmployeeInfo();
		break;
	case 11:
		system("cls");
		return false;
		break;
	default:
		system("cls");
		adminOptions(Admin);
		return true;
		break;
	}
	system("pause");
	adminOptions(Admin);
}
