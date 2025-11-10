#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Employee.h"
//#include "FilesHelper.h"
#define Clients_Details "Clients.txt"
#define Employees_Details "Employees.txt"
#define Admins_Details "Admins.txt" 
#define Client_Id "ClientLastId.txt"
#define Employee_Id "EmployeeLastId.txt"
#define Admin_Id "AdminLastId.txt" 
using namespace std;
class Admin : public Employee
{

public:
    Admin() {}
    Admin(string name, string password, double salary) : Employee(name, password, salary)
    {


    }
     void show();
     bool check_employee(int id);
     void edit_employee(int id, string name, string password, double balance);
     void listEmployees();
     void addEmployee(Employee& employee);
};

extern vector<Admin> allAdmins;
extern vector<Admin>::iterator admitr;