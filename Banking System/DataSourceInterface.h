#pragma once
#include "Employee.h"
#include "Admin.h"
#include "Client.h"

#include <vector>
using namespace std;
class DataSourceInterface
{
protected:
    virtual void addClient(Client clt) = 0;
    virtual void addEmployee(Employee emp) = 0;
    virtual void addAdmin(Admin adm) = 0;
    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee> getAllEmployee() = 0;
    virtual vector<Admin> getAllAdmins() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};