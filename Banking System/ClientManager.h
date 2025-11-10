#pragma once
#include "Person.h"
#include "Client.h"
class ClientManager
{
public:
	static void update();
	static void printClientMenu();
	static void edit_client_Password(Client* client, string password);
	static Client* login(int id, string password);
	static bool clientOptions(Client* client);
	static void updateClientBalance(int id, double depositAmount, double withdrawAmount , int transferId);
};

