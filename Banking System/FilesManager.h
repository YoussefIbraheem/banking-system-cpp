#pragma once
#include "DataSourceInterface.h"
#include <fstream>
#include <string>
#include "FilesHelper.h"
#define Clients_Details "Clients.txt"
#define Employees_Details "Employees.txt"
#define Admins_Details "Admins.txt" 
#define Client_Id "ClientLastId.txt"
#define Employee_Id "EmployeeLastId.txt"
#define Admin_Id "AdminLastId.txt" 
using namespace std;
class FilesManager : public DataSourceInterface
{
public:
	 static void addClient(Client c);
	 static void addEmployee(Employee e);
	 static void addAdmin(Admin a);
	 static void getAllClients();
	 static void getAllEmployees();
	 static void getAllAdmins();
	 static void removeAllClients();
	 static void removeAllEmployees();
	 static void removeAllAdmins();
	 static int getLast(string lastIdFile);
};

