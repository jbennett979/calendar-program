//
// Created by Jess on 10/5/2024.
//

#include "Login.h"
#include <iostream>
#include <fstream>
using namespace std;

Login::Login(string choice, string username, string password){
    this->choice = choice;
    this->username = username;
    this->password = password;
}

void Login::user_pass_file(){
    if(choice == "sign up") {
        ofstream loginFile;
        loginFile.open("login_info.txt");
        loginFile << username << endl;
        loginFile << password << endl;
        loginFile.close();
        cout << "got here" << endl;
    }
    //did not have time to finish log in case
    /*else if(choice == "log in") {

    }*/
}