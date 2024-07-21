#ifndef MENU3_H
#define MENU3_H

#include "goback.h"

void menu3(){
    string line; 
    ofstream users("users");

    ifstream data;
    data.open("database");

    cout<<endl<<"Registered (non friends) users : "<<endl<< string(32,"=") <<endl;
    
}

#endif