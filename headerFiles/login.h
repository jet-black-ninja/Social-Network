#ifndef LOGIN_H
#define LOGIN_H

#include "./menu2.h"

int mainmenu();

extern string password;
extern string logpass;

void login(){
    ifstream data("database");

    if(!data.is_open()) {
        cout<<endl;
        cout<<"You Have To Register First"<<endl;
        mainmenu();
    }

    cout<<endl<<"Write Your Username : ";
    getline(cin, logname );
    cout<<endl<<"Write Your Password : ";
    getline(cin, logpass);


    int j;
    while(!data.eof()) {
        getline(data,name ,'\n');
        getline(data,password,'\n');

        if(logname == name && logpass == password){
            cout<<endl;
            cout<<"Successful Login "<<endl;
            cout<<"\e[3m Welcome ,\e[0m"<<logname <<"\e[3m !\e[0m" <<endl;
            menu2();
            break;
        } 
        else if(logname != name && logpass == password ) {j=1;}
        else if(logname == name  && logpass != password) {j=2;}
        
    }
    if(j==1){
        cout<<endl <<"Wrong username " <<endl <<"Try Again ..."<<endl;
        login();
    }
    if(j==2){
        cout<< endl << "Wrong Password" <<endl << "Try Again ..."<<endl;
        login();
    }
    data.close();
    
}
#endif