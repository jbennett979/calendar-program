//
// Created by Jess on 10/5/2024.
//

#ifndef M2OEP_LOGIN_H
#define M2OEP_LOGIN_H
#include <string>
using namespace std;


class Login {
private:
    string choice;
    string username;
    string password;

public:
    Login(string choice, string username, string password);
    void user_pass_file();
};


#endif //M2OEP_LOGIN_H
