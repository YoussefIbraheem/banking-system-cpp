#include "Employee.h"
#include "FilesManager.h"
void Employee::set_salary(double salary)
{
	this->salary = salary;
}

double Employee::get_salary()
{
	return salary;
}

void Employee::display_employee()
{
	cout << endl;
	cout << "Employee " << id << " Information : " << endl;
	Person::display_info();
	cout << "Salary : " << salary << endl;
	cout << "-----------------" << endl;
}
bool Employee::check_client(int id) {
	auto lastClient = FilesManager::getLast(Client_Id);
	if (id <= lastClient && id >= 1) {
		return true;
	}
	else {
		return false;
	}
}

void Employee::addClient(Client& client) {
	FilesManager::addClient(client);
	client.set_id(FilesManager::getLast(Client_Id));
	allClients.push_back(client);
}

Client* Employee::search_client(int id) {
	
	for (cltitr = allClients.begin(); cltitr != allClients.end(); cltitr++) {
		if (cltitr->get_id() == id) return cltitr._Ptr;
	}
	return NULL;
}

void Employee::edit_client(int id, string name, string password, double balance)
{
	if (Employee::check_client(id)) {
		
		auto selectedClient = search_client(id);
		selectedClient->set_name(Validation::name_validation(name));
		selectedClient->set_password(Validation::password_validation(password));
		selectedClient->set_balance(Validation::balance_validation(balance));
		FilesManager::removeAllClients();
		for (int i = 0; i < allClients.size(); i++)
		{
			FilesManager::addClient(allClients[i]);
		}
	}
	else {
		cout << "Client Not Found!";
	}
}
void Employee::listClients() {
	
	for (int i = 0; i < allClients.size(); i++) {
		allClients[i].display_client();
	}
}