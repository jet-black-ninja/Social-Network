#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "./login.h"

extern string password;
extern string regname;
extern string regpass;

int registration(){
    ifstream data("database");
    cout<< endl <<"Write Desired Username : ";
    getline(cin,regname);
    while(!data.eof()){
        getline(data,name,'\n');
        getline(data,password,'\n');
        while(regname == name ){
            cout<<"The Username already exist! Try again"<< endl;
            registration();
        }
    }

    data.close();

    cout<<"Write the desired password : ";

    getline(cin,regpass);

    while(regpass.length()<4){
        cout<<endl<<"The chosen password is too short!"<<endl;
        cout<<"The password needs to be alreast 4 characters long."<<endl <<endl;
        cout<<"Try another Password : ";
        getline(cin,regpass);
    }

    ofstream newData("database",ios::app);

    ofstream newfile(regname.c_str(), ios::app);
    newfile.close();

    newData<<regname<<'\n';
    newData<<regpass<<'\n';

    newData.close();

    cout<<endl;
    cout<<regname+ ", you have successfully registered!" <<endl<<endl;
    cout<<"What would you like to do: "<<endl<< string(24, '=')<<endl;
    cout<<"[1] Log In"<<endl;
    cout<<"[2] Return to Main Menu"<<endl;
    cout<<"[3] Exit the Program"<<endl;
    cout<<"Choice : ";

    int regChoice ;
    cin >> regChoice;
    cin.ignore();
    switch(regChoice){
        case 1:
            login();
            break;
        case 2:
            mainmenu();
            break;
        case 3:
            exxit();
            break;
        default:
            cout<<"Invalid Choice. Try Again ..."<<endl;
            mainmenu();
            break;
    }
return 0;
}

#endif