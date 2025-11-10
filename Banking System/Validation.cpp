#include "Validation.h"


 string Validation::name_validation(string name) {

     while (true) {

         if (regex_match(name, regex("^[a-zA-Z ]+$")) && (name.size() >= 5 && name.size() <= 20)) {

                 return name;

         }
         else {
             cout << " the name must be alphabetic chars and min size 5 and max size 20 \n";
             cout << "name : ";
             cin.ignore();
             getline(cin, name);
         }

     }
}
 string Validation::password_validation(string password) {

     while (true) {
         if (password.size() >= 8 && password.size() <= 20) {
             
             return password;
         }
         else {
             cout << "Password must be with min size 8 and max size 20 \n";
             cout << "password : ";
             cin >> password;
         }

     }
}
 double Validation::salary_validation(double salary) {
     while (true) {
         if (salary >= 5000) {
             return salary;
         }
         else {
             cout << "Minimum Salary Must be Not Less Than 5000!\n";
             cout << "salary : ";
             cin >> salary;
         }
     }
}
 double Validation::balance_validation(double balance) {
    while (true)
    {
        if (balance >= 1500)
        {
            return balance;
        }
        else
        {
            cout << "you must enter at least 1500  in balance \n";
            cout << "balance : ";
            cin >> balance;
        }
    }
}
