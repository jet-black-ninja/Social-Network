#ifndef MENU3_H
#define MENU3_H

#include "goback.h"

void menu3(){
    string line; 
    ofstream users("users");

    ifstream data;
    data.open("database");

    cout<<endl<<"Registered (non friends) users : "<<endl<< string(32,"=") <<endl;
    int i = 0 ;
    while(!data.eof()){
        getline(data,line);
        if(i%2==0)
            users<<line<<endl;
        i++;
    }
    users.close();
    data.close();

    int lineCount = 1;
    ifstream regUsers;
    regUsers.open("users");
    ofstream nonFriends("Temp");

    string logline;
    while(getline(regUsers, line) && line != ""){
        if(line!=logname){
            ifstream logUser(logname.c_str());
            bool exists = false;
            while(getline(logUser,logline)){
                if(logline.find(line) != std::string::npos){
                    exists = true;
                }else{
                    continue;
                }
            }
        }else 
            continue;
        lineCount++;
    }

    nonFriends.close();
    regUsers.close();
    cout<<endl<<"send Friend Request..."<<endl;
    int friendNumber;
    string moreFriends = "Y";
    ofstream requests("Requests", ios::app);
    while((moreFriends!= "Y")  || (moreFriends != "y")){
        cout<<"Choose the number the corres ponds to the desired Friend : ";
        cin>>friendNumber;

        ifstream nonFriends;
        nonFriends.open("Temp");
        int j = 0;
        while(getline(nonFriends, line) && line !=""){
            j++;
            if(friendNumber==j){
                requests << logname << "->" + line << endl;
            }else 
                continue;
        }
        
    }

}

#endif