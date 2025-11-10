#include "ClientManager.h"
#include "FilesManager.h"
using namespace std;
void ClientManager::printClientMenu() {
	system("cls");
	cout << "(1) Display Info" << endl;
	cout << "(2) Check Balance" << endl;
	cout << "(3) Update Password" << endl;
	cout << "(4) Withdraw" << endl;
	cout << "(5) Deposit" << endl;
	cout << "(6) Transfer Amount" << endl;
	cout << "(7) Logout " << endl;
}

void ClientManager::update() {
	//int id = client.get_id();
	//FilesManager::getAllClients();
	//allClients[id - 1] = client;
	//auto& selectedClient = allClients[id - 1];
	//selectedClient.set_name(client.get_name());
	//selectedClient.set_password(client.get_password());
	//selectedClient.set_balance(client.get_balance());
	FilesManager::removeAllClients();
	for (int i = 0; i < allClients.size(); i++)
	{
		FilesManager::addClient(allClients[i]);
	}
}




Client* ClientManager::login(int id , string password) {
	//FilesManager::getAllClients();
	for (cltitr = allClients.begin(); cltitr != allClients.end(); cltitr++) {
		if (cltitr->get_id() == id && cltitr->get_password() == password) return cltitr._Ptr;
	}
	return NULL;
}

bool ClientManager::clientOptions(Client* client) {
	ClientManager::printClientMenu();
	int choice;
	int id;
	Employee emp;
	double amount;
	Client* selectedClient;
	bool  clientCheck;
	string password;
	cout << "Please Enter Your Choice" << endl;
	cin >> choice;
	switch (choice) {
	case 1 :
		system("cls");
		client->display_client();
		break;
	case 2:
		system("cls");
		client->checkBalance();
		break;
	case 3:
		system("cls");
		cout << "Enter Password" << endl;
		cin >> password;
		client->set_password(password);
		//edit_client_Password(client, password);
		update();
		break;
	case 4:
		system("cls");
		cout << " Enter Required Amount" << endl;
		cin >> amount;
		//updateClientBalance(client->get_id(), 0, amount, 0);
		client->withdraw(amount);
		update();
		break;
	case 5:
		system("cls");
		cout << " Enter Required Amount" << endl;
		cin >> amount;
		//updateClientBalance(client->get_id(),amount,0, 0);
		client->deposit(amount);
		update();
		break;
	case 6:
		system("cls");
		cout << " Enter user id" << endl;
		cin >> id;
		selectedClient = emp.search_client(id);
		while (selectedClient == NULL) {
			system("cls");
			cout << "invalid ID try again" << endl;
			cin >> id;
			selectedClient = emp.search_client(id);
		}
		//selectedClient->display_client();
		cout << " Enter Required Amount" << endl;
		cin >> amount;
		//updateClientBalance(client->get_id(), 0, amount, id);
		client->transfer_to(amount, *selectedClient);
		update();
		break;
	case 7:
		system("cls");
		return false;
		break;
	default:
		system("cls");
		clientOptions(client);
		return true;
	}
	system("pause");
	clientOptions(client);
}


