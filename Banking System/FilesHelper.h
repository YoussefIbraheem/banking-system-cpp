#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Employee.h"
#include "Client.h"
#include "Admin.h"
#include "Parser.h"
#define Clients_Details "Clients.txt"
#define Employees_Details "Employees.txt"
#define Admins_Details "Admins.txt" 
#define Client_Id "ClientLastId.txt"
#define Employee_Id "EmployeeLastId.txt"
#define Admin_Id "AdminLastId.txt" 
using namespace std;
class FilesHelper
{
public:
	static void saveLast(string lastIdFile, int id);
	static int getLast(string lastIdFile);
	static void saveClient(Client c);
	static void saveEmployee(string fileName, string lastIdFile, Employee e);
	static void getClients();
	static void getEmployees();
	static void getAdmins();
	static void clearFile(string fileName, string lastIdFile);
};

//vector<Employee> allEmployees;