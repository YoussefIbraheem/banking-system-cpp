#include "EmployeeManager.h"
#include "FilesManager.h"
void EmployeeManager::printEmployeeMenu()
{
	system("cls");
	cout << "(1) Display My Info" << endl;
	cout << "(2) Update Password" << endl;
	cout << "(3) Add New Client" << endl;
	cout << "(4) Search For a Client" << endl;
	cout << "(5) List All Clients" << endl;
	cout << "(6) Edit Client Info" << endl;
	cout << "(7) logout" << endl;
}

void EmployeeManager::newClient(Employee* employee) {
	Client client;
	string cltName;
	string cltPassword;
	double cltBalance;
	cout << "set Client Name" << endl;
	cin.ignore();
	getline(cin, cltName);
	client.set_name(Validation::name_validation(cltName));
	cout << "set Client Password" << endl;
	cin >> cltPassword;
	client.set_password( Validation::password_validation(cltPassword));
	cout << "set Client balance" << endl;
	cin >> cltBalance;
	client.set_balance( Validation::balance_validation(cltBalance));
	employee->addClient(client);
}

void EmployeeManager::searchForClient(Employee* employee) {
	int id;
	system("cls");
	cout << "Enter the ID You're Looking for" << endl;
	cin >> id;
	while (!employee->check_client(id)) {
		cout << "Client Not Found Try Again" << endl;
		cin >> id;
	}
	auto searchedClient = employee->search_client(id);
	searchedClient->display_client();
}

void EmployeeManager::listAllClients(Employee* employee) {
	system("cls");
	cout << "All Clients: \n";
	employee->listClients();
}

void  EmployeeManager::editClientInfo(Employee* employee) {
	system("cls");
	int id;
	string name;
	string password;
	double balance;

	cout << "enter Client ID\n";
	cin >> id;
	while (!employee->check_client(id)) {
		cout << "Client Not Found Try Again\n";
		cin >> id;
	}
	cout << "Please Enter Client Name\n";
	cin.ignore();
	getline(cin, name);
	cout << "Please Enter Client Password\n";
	cin >> password;
	cout << "Please Enter Client Balance\n";
	cin >> balance;
	employee->edit_client(id , name , password , balance);
}



void EmployeeManager::edit_employee_password()
{
	
		FilesManager::removeAllEmployees();
		for (int i = 0; i < allEmployees.size(); i++)
		{
			FilesManager::addEmployee(allEmployees[i]);
		}
	
}


Employee* EmployeeManager::login(int id, string password) {
	
	for (empitr = allEmployees.begin(); empitr != allEmployees.end(); empitr++) {
		if (empitr->get_id() == id && empitr->get_password() == password) return empitr._Ptr;
	}
	return NULL;
}
bool EmployeeManager::employeeOptions(Employee* employee)
{
	EmployeeManager::printEmployeeMenu();
	int choice;
	int id;
	string password;
	cout << "Enter the Number of the Requested Service" << endl;
	cin >> choice;
	switch (choice) {
	case 1 :
		system("cls");
		employee->display_employee();
		break;
	case 2:
		system("cls");
		cout << "Please Enter the New Password" << endl;
		cin >> password;
		employee->set_password(Validation::password_validation(password));
		edit_employee_password();
		break;
	case 3:
		system("cls");
		EmployeeManager::newClient(employee);
		break;
	case 4:
		system("cls");
		EmployeeManager::searchForClient(employee);
		break;
	case 5:
		system("cls");
		EmployeeManager::listAllClients(employee);
		break;
	case 6:
		system("cls");
		EmployeeManager::editClientInfo(employee);
		break;
	case 7:
		system("cls");
		return false;
		break;
	default:
		system("cls");
		employeeOptions(employee);
		return true;
		break;
	}
	system("pause");
	employeeOptions(employee);
}
