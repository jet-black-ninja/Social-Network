#ifndef LISTUSERS_H
#define LISTUSERS_H

#include <fstream>
using namespace std;

extern string name;
extern string password;
extern int numOfUsers;
;
void listusers(){
    ifstream data;
    data.open("database");
    numOfUsers= 0;
    while(!data.eof()){
        getline(data,name,'\n');
        getline(data,password,'\n');
        numOfUsers++;
    }
    data.close();
}
#endif 