#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <synchapi.h>
#include "AdminManager.h"
#include "EmployeeManager.h"
#include "ClientManager.h"
#include "FilesManager.h"
#define WE_Bank "webank.txt"
#define  Welcome "welcome.txt"
using namespace std;
class Screens
{
public:

static void bankName();
static void welcome();
static void loginOptions();
static int loginAs();
static void invalid(int c);
static void logout();
static void loginScreen(int c);
static void runApp();
static void printASCII(string fileName);
};

