#ifndef MAINMENU_H
#define MAINMENU_H

#include "registration.h"

int mainmenu(){
    cout<<endl<<"\e[1mMAIN MENU\e[0m" <<endl << "\e[3m (Type The Number of Your Choice)\e[0m"<<endl <<string(33,'=')<<endl;
    cout << "[1] Register" << endl;
    cout << "[2] Log In" << endl;
    cout << "[3] Exit the Program" << endl << endl;

    
}

#endif