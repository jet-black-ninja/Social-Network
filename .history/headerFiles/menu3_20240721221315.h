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
            users<<line<<
    }
}

#endif