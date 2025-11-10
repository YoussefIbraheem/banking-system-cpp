#include "Parser.h"
 vector<string> Parser::split(string line)
{
    stringstream str_strm(line);
    vector<string> words;
    string token;
    while (getline(str_strm, token, '-')) {
        words.push_back(token);
    }
    return words;
}


 Client Parser::parsetoClient(string line) {
    //first , we have to split the line into  4 attributes (string)
    vector<string> v = Parser::split(line);
    Client clt;
    clt.set_id(stoi(v[0]));
    clt.set_name(v[1]);
    clt.set_password(v[2]);
    clt.set_balance(stod(v[3]));
    return clt;
}

 Employee Parser::parsetoEmployee(string line) {
    vector<string> v = Parser::split(line);
    Employee emp;

    emp.set_id(stoi(v[0]));
    emp.set_name(v[1]);
    emp.set_password(v[2]);
    emp.set_salary(stod(v[3]));
    return emp;
}

  Admin Parser::parsetoAdmin(string line) {
    vector<string> v = Parser::split(line);

    Admin adm;

    adm.set_id(stoi(v[0]));
    adm.set_name(v[1]);
    adm.set_password(v[2]);
    adm.set_salary(stod(v[3]));

    return adm;
}