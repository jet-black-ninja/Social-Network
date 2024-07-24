// See your wall
#ifndef VIEWPOST_H
#define VIEWPOST_H
//Local header files
#include "goback.h"
//declaration of variables from main.cpp
extern string name ;
extern string posts;
extern string Friend;
extern string namepost;
//TODO infinite loop issue in replying to friend post 

void viewposts(){
    //print all posts of the logged in user
    cout<<endl<<"Your posts are : " << endl << string(16, '=') << endl;

    ifstream allPosts;
    allPosts.open("posts");// open file containing all posts
    int lineCount = 1;
    //repeat process to print all of the user's posts
    while(!allPosts.eof()){
        getline(allPosts, name ,'\n');//read names 
        getline(allPosts,posts,'\n');//read posts
        if(name == logname ){
            cout<<"["<<lineCount << "]" << " " << posts << endl;
            lineCount++;
        }
        
    }

    allPosts.close();// close the file of posts
    //print all the posts that belong to the logged in user's friends
    cout << endl << "Your Friend's Posts are : " << endl <<string(24, '=');
    bool same ;
    ifstream user;
    user.open(logname.c_str());//open file of logged in user's friends

    while(!user.eof()){
        int i = 1;//counter
        same = false;
        getline(user,Friend,'\n');
        ifstream allPosts;
        allPosts.open("posts");
        while(!allPosts.eof()){
            getline(allPosts,name ,'\n');//read the names from post file
            getline(allPosts,posts,'\n');// read the posts from the post file
            if(Friend == name && same == true){
                cout<<" Post "<< i << " : " << posts << endl;
                i++;
            }else if(Friend == name && same == false & Friend != ""){
                cout << endl << "Friend : "<< name << endl;
                cout<< "Post " << i << " : " << posts << endl; 
                i++;
                same = true;
            }
        }
        allPosts.close();// close file of posts
    }
    user.close(); // close logged in user' file 

    //Print all conversations posts between logged in user and Friend 
    cout<< endl << "Conversations : " << endl << string(15,'=')<< endl;
    ifstream conversations;
    conversations.open("conversations");
    while(!conversations.eof()){
        getline(conversations,namepost);
        if(namepost.substr(0, namepost.find(':')) == logname){
            cout<<namepost << endl;
            while(getline(conversations,namepost)){
                if(namepost.substr(0,1)==" ")
                    cout<<namepost<<endl;
                else 
                    break;
            }
        }
        ifstream friends;
        friends.open(logname.c_str()); // open file with friends of the logged in user
        string userFriend;
        while(getline(friends,userFriend)){
            if(userFriend == namepost.substr(0,namepost.find(":")))
            {
                cout<<namepost<<endl;
                do{
                    getline(conversations, namepost);
                    if(namepost.find(logname.c_str())!=std::string::npos)
                        cout<<namepost<<endl;
                }while(namepost.substr(0,1) == " ");
            } else 
                break;
        }
    }
    conversations.close();//Close files of conversations
    cout<<endl <<"Number of Likes"<<endl << string(17,'=')<<endl;

    ifstream likesnum;
    likesnum.open("likes");
    int i=0;
    while(!likesnum.eof()){
        string mylikes;
        getline(likesnum,mylikes);
        int likescounter = 0; //Counter of likes for each post
        if(mylikes.find(":")!= std::string::npos){
            if(mylikes.substr(0,mylikes.find(":")) == logname){
                i++;
                string upost = mylikes.substr(mylikes.find(" "),mylikes.find('\n'));
                cout<<"["<< i << "]"<< upost << "(#Likes : ";
                while(getline(likesnum,mylikes)){
                    if(mylikes.find("LIKE")!= std::string::npos) // while LIKE is begin found , increase counter
                        likescounter++;
                    else 
                        break;
                }
                cout<<likescounter<<")"<<endl;
            }
        }
    }
    likesnum.close();//Close file of post with likes
    goback();//Check if user wants to continue or go back to main menu

}

#endif 