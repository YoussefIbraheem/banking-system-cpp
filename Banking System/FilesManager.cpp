#include "FilesManager.h"
 void FilesManager::addClient(Client c)
{
    FilesHelper::saveClient(c);
}
 void FilesManager::addEmployee(Employee e)
{
    FilesHelper::saveEmployee(Employees_Details, Employee_Id, e);
}
 void FilesManager::addAdmin(Admin a)
{
    FilesHelper::saveEmployee(Admins_Details, Admin_Id, a);
}

 void FilesManager::getAllClients()
{
    FilesHelper::getClients();
}
 void FilesManager::getAllEmployees()
{
    FilesHelper::getEmployees();
}
 void FilesManager::getAllAdmins()
{
   FilesHelper::getAdmins();
}
 void FilesManager::removeAllClients()
{
    FilesHelper::clearFile(Clients_Details, Client_Id);
    
}
 void FilesManager::removeAllEmployees()
{
    FilesHelper::clearFile(Employees_Details, Employee_Id);
}
 void FilesManager::removeAllAdmins()
{
    FilesHelper::clearFile(Admins_Details, Admin_Id);
}
 int FilesManager::getLast(string lastIdFile) {
    return FilesHelper::getLast(lastIdFile);
}