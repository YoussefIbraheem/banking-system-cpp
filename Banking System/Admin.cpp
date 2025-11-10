#include "Admin.h"
#include "FilesManager.h"
bool Admin::check_employee(int id) {
	auto lastEmployee = FilesManager::getLast(Employee_Id);
	if (id <= lastEmployee && id >= 1) {
		return true;
	}
	else {
		return false;
	}
}



void  Admin::edit_employee(int id, string name, string password, double balance)
{
	if (check_employee(id)) {
		//FilesManager::getAllEmployees();

		//allEmployees[id - 1].display();
		allEmployees[id - 1].set_name(name);
		allEmployees[id - 1].set_password(password);
		allEmployees[id - 1].set_salary(balance);
		FilesManager::removeAllEmployees();
		for (int i = 0; i < allEmployees.size(); i++)
		{
			FilesManager::addEmployee(allEmployees[i]);
		}
	}
	else {
		cout << "Employee Not Found!";
	}
}
void  Admin::listEmployees() {
	//FilesManager::getAllEmployees();
	for (int i = 0; i < allEmployees.size(); i++) {
		allEmployees[i].display_employee();
	}
}

void Admin::addEmployee(Employee& employee)
{
	FilesManager::addEmployee(employee);
	employee.set_id(FilesManager::getLast(Employee_Id));
	allEmployees.push_back(employee);
}
