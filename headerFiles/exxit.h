#ifndef EXXIT_H
#define EXXIT_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;


extern string logname ;

int exxit(){
    cout<<endl << "Program Termination ..." <<endl;
    std::this_thread::sleep_for(std::chrono::microseconds(500ms));
    cout<<"Thanks for visiting "+ logname <<endl;
    exit(1);
    return 0;
}

#endif