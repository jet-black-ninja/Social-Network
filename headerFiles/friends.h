#ifndef FRIENDS_H
#define FRIENDS_H
#include "goback.h"

extern string Friend;
void friends(){
    cout<<endl<<"Your Current Friends Are : "<<endl<<string(18,'=')<<endl;
    ifstream logUser;
    logUser.open(logname.c_str());
    while(!logUser.eof()){
        getline(logUser, Friend);
        cout<<Friend<<endl;
    }
    goback();

}
#endif 