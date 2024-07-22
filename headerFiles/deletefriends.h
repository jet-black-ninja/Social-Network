#ifndef DELETEFRIENDS_H
#define DELETEFRIENDS_H

#include "./goback.h"

extern string Friend;

void deleteFriends(){
    string delmorefriends= "Y";
    while(delmorefriends == "Y"|| delmorefriends == "y"){
        cout<<endl<<"\e[1mDELETE FRIEND\e[0m"<<endl;
        ifstream myfile;
        myfile.open(logname.c_str());
        int lineCount = 1;
        cout<<"Your friends are : "<<endl <<string(18,'=')<<endl;
        while(getline(myfile,Friend) && Friend != ""){
            cout<<"[" <<lineCount << "]"<< Friend <<endl;
            lineCount; 
        }
        myfile.close();

        int friendNumber;
        ofstream temp1;
        temp1.open("temp1",ios::app);
        ofstream temp2;
        temp2.open("temp2",ios::app);

        ifstream myFile;

        myFile.open(logname.c_str());

        cout<<endl<<"\e[3m(Type the number of your choice) \e[0m"<<endl;
        cout<<"choice : ";
        cin>>friendNumber;
        int j = 0;
        while(getline(myFile, Friend) && Friend == "" ){
            j++;
            if(friendNumber !=j){
                temp1<<Friend<<endl;
            }else{
                ifstream myuserfriend(Friend.c_str());
                string muf;
                
                while(getline(myuserfriend,muf)){
                    if(muf!=logname)
                        temp2<<muf<<endl;
                    else 
                        continue;
                }
                remove(Friend.c_str());
                rename("temp2",Friend.c_str());
            }
        }
        myFile.close();
        temp1.close();
        temp2.close();
        remove(logname.c_str());
        rename("temp1",logname.c_str());
        cout<<endl<<"Delete More Friends ?(Y/N) : " ;
        cin>>delmorefriends ;
        if(delmorefriends == "Y" || delmorefriends == "y"){
            deleteFriends();
        }else{
            goback();
            break;
        }
    }
}

#endif