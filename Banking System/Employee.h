#pragma once
#include <iostream>
#include "Person.h"
#include "Client.h"
#define Client_Id "ClientLastId.txt"
#define Clients_Details "Clients.txt"
#define Employees_Details "Employees.txt"
#define Admins_Details "Admins.txt" 
#define Employee_Id "EmployeeLastId.txt"
#define Admin_Id "AdminLastId.txt" 
using namespace std;

class Employee : public Person
{
protected:
	 double salary;
public:
	Employee() {}
	Employee(string name, string password, double salary) : Person(name, password)
	{

		set_salary(salary);
	}
	 void set_salary(double salary);
	 double get_salary();
	 void edit_client(int id, string name, string password, double balance);
	 bool check_client(int id);
	 void listClients();
	 void display_employee();
	 void addClient(Client& Client);
	 Client* search_client(int id);

};

extern vector<Employee> allEmployees;
extern vector<Employee>::iterator empitr;