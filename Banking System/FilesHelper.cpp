#include "FilesHelper.h"
vector<Employee> allEmployees;
vector<Employee>::iterator empitr;
vector<Client> allClients;
vector<Client>::iterator cltitr;
vector<Admin> allAdmins;
vector<Admin>::iterator admitr;
 void FilesHelper::saveLast(string lastIdFile, int id) {
	ofstream file;
	file.open(lastIdFile, ios::out);
	file << id;
	file.close();
}
 int FilesHelper::getLast(string lastIdFile) {
	ifstream file;
	file.open(lastIdFile);
	int id;

	if (file.peek() == ifstream::traits_type::eof()) {
		id = 0;
	}
	else {
		file >> id;
	}
	file.close();
	return id;
}
 void FilesHelper::saveClient(Client c) {
	int id = getLast(Client_Id);

	fstream file;
	file.open(Clients_Details, ios::out | ios::app);
	file << id + 1 << "-" << c.get_name() << "-" << c.get_password() << "-" << c.get_balance() << "\n";
	saveLast(Client_Id, id + 1);
	file.close();
}
 void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e) {
	int id = getLast(lastIdFile);
	fstream file;
	file.open(fileName, ios::out | ios::app);
	file << id + 1 << "-" << e.get_name() << "-" << e.get_password() << "-" << e.get_salary() << "\n";
	saveLast(lastIdFile, id + 1);
	file.close();
	
}
 void FilesHelper::getClients() {
	ifstream file;
	string token;
	//vector<Client> allClients;

	file.open(Clients_Details);
	while (getline(file, token)) {
		Client clt = Parser::parsetoClient(token);
		allClients.push_back(clt);
	}
	file.close();
	//return allClients;
}
 void FilesHelper::getEmployees() {
	ifstream file;
	string token;
	//extern vector<Employee> allEmployees;
	file.open(Employees_Details, ios::in);
	while (getline(file, token)) {
		Employee emp = Parser::parsetoEmployee(token);
		allEmployees.push_back(emp);
	}
	file.close();
	//return allEmployees;
}
 void FilesHelper::getAdmins() {
	ifstream file;
	string token;
	//vector<Admin> allAdmins;
	file.open(Admins_Details);
	while (getline(file, token)) {
		Admin adm = Parser::parsetoAdmin(token);
		allAdmins.push_back(adm);
	}
	file.close();
	//return allAdmins;
}
 void FilesHelper::clearFile(string fileName, string lastIdFile) {
	fstream file, lastFileId;
	file.open(fileName, ios::out | ios::trunc);
	file.close();
	lastFileId.open(lastIdFile, ios::out | ios::trunc);
	lastFileId.close();
}