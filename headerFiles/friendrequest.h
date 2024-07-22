#ifndef FRIENDREQUEST_H
#define FRIENDREQUEST_H

#include "./goback.h"

void friendrequest(){
    cout<<"\e[1mACCEPT / REJECT FRIEND REQUEST\e[0m"<<endl;
    string line;
    string moreRequests = "Y";
    ofstream tempreq("TempReq");
    ifstream freq;
    freq.open("Requests");
    ofstream mytemp;
    mytemp.open("Temp");

    while(getline(freq, line)){
        if((line.find(logname) != std::string::npos) && ((line.substr(0,line.find(" "))!=logname)))
            tempreq<<line.substr(0,line.find(" ")) <<endl;
        else 
            mytemp<<line<<endl;
    }

    mytemp.close();
    remove("Request");
    rename("Temp","Requests");
    tempreq.close();

    while(moreRequests != "Y" || moreRequests!="y"){
        ifstream tempReq;
        tempReq.open("TempReq");

        cout<<"Request From : " << endl <<string(14,'=')<<endl;
        int lineCount = 1;
        while(getline(tempReq,line ) && line != ""){
            cout<<"[]"<<lineCount <<"]" <<line <<endl;
            lineCount++;
        }
        tempReq.close();
        int friendNumber;
        cout<<endl<<"\e[3m(Type the number of user you want to accept )\e[0m"<<endl;
        cout<<"Choice : ";
        cin >> friendNumber;
        ifstream TempReq;
        TempReq.open("TempReq");
        int j = 0;
        ofstream userFile(logname.c_str(), ios::app);
        ofstream temporary("MyTemp");
        while(getline(tempReq, line) && line !=""){
            j++;
            if(friendNumber==j){
                userFile << line << endl;
                ofstream otherfile(line.c_str(), ios::app);
                otherfile.close();

                temporary<<" " <<endl;
            }else{
                temporary<<line<<endl;
            }
        }
        temporary.close();
        TempReq.close();
        remove("TempReq");
        rename("MyTemp","TempReq");
        userFile.close();

        cout<< endl <<"Accept More Request ? (Y/N) : ";
        cin>>moreRequests;
        if(moreRequests == "Y" || moreRequests =="y"){
            continue;
        }else {
            goback();
            break;
        }
    }
}

#endif