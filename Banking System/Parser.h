#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Client.h"
#include "Admin.h"
using namespace std;
class Parser
{
public:
	static vector<string> split(string line);
	static Client parsetoClient(string line);
	static Employee parsetoEmployee(string line);
	static  Admin parsetoAdmin(string line);
};

