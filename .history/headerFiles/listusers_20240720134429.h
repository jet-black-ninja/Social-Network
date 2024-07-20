#ifndef LISTUSERS_H
#define LISTUSERS_H

#include <fstream>
using namespace std;

extern string name;
extern string password;
extern int numOfUsers;

void listusers(){
    ifsteam data;
    data.open("database");
    while(!data.eof()){
        getline(data,name,"\n');
        getline(data,password,'\n')
    }
}
#endif 