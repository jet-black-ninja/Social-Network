#ifndef MENU2_H
#define MENU2_H

#include "viewposts.h"
#include "viewfriendsposts.h"
#include "menu3.h"
#include "friendrequest.h"
#include "friends.h"
#include "deletefriends.h"
#include "exxit.h"

int mainmenu();
void viewfriendsposts();

void menu2(){
    cout<<endl << "\e[1mSOCIAL NETWORK MENU\e[0m" << endl << "\e[3m(Type the number of your choice)\e[0m" << endl << string(33, '=') << endl;
    cout << "[1] My wall" << endl;
    cout << "[2] Friend's wall" << endl;
    cout << "[3] Send friend request" << endl;
    cout << "[4] Accept/Reject friend request" << endl;
    cout << "[5] My friends" << endl;
    cout << "[6] Delete friend" << endl;
    cout << "[7] Back" << endl;
    cout << "[8] Log out" << endl;
    cout << "[9] Exit the program" << endl;
    cout << endl;

    int menuChoice ;
    cout<< "Choice : ";
    cin >>menuChoice;
    switch(menuChoice){
        case 1:
            viewposts();
            break;
        case 2:
            viewfriendsposts();
            break;
        case 3:
            menu3();
            break;
        case 4:
            friendrequest();
            break;
        case 5:
            friends();
            break;
        case 6:
            deleteFriends();
            break;
        case 7:
            mainmenu();
            break;
        case 8:
            cout<<"You have successfully Logged out"<<endl;
            mainmenu();
            break;
        case 9:
            exxit();
            break;
        default:
            cout<<"Invalid Choice. Try Again ..."<<endl;
            menu2();
            break;
    }
}
#endif 