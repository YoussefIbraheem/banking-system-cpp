#pragma once
#include"Admin.h"
class AdminManager 
{
public:

	static void printClientMenu();
	static Admin* login(int id, string password);
	static bool adminOptions(Admin* Admin);
	static void newClient(Admin* admin);
	static void newEmployee(Admin* admin);
	static void searchForClient(Admin* Admin);
	static Employee* searchForEmployee(int id);
	static void editClientInfo(Admin* Admin);
	static void listEmployees();
	static void editEmployeeInfo();
};

