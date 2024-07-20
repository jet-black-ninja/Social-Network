#ifndef LOGIN_H
#define LOGIN_H

#include menu2.h

int mainMenu();

extern string password;
extern string logpass;

void login(){
    ifstream data("database");

    if(!data.is_open()){
        cout<<endl;
        cout<<"You Have To Register First"<<endl;
        mainMenu();
    }

    cout<<endl<<"Write Your Username ";
    getline()
    cout<<endl<<"Write Your Password";

    
}