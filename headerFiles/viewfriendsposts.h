//see yours friends wall and posts
#ifndef VIEWFRIENDSPOSTS_H
#define VIEWFRIENDSPOSTS_H
//local header files
#include "menu2.h"
#include "goback.h"
#include <conio.h>
void viewfriendsposts(){
    cout<<endl<<"\e[1mYOUR FRIENDS WALL\e[0" << endl <<"\e[3m(Type the number of your choice) \e[0m"<<endl<< string(32,'=')<<endl;
    cout << "[1] Post a message on your wall" << endl;
    cout << "[2] Reply to a post" << endl;
    cout << "[3] Leave a Like" << endl;
    cout << "[4] Main menu" << endl << endl;
    cout << "Choice : ";
    int choiceType;
    cin >> choiceType;

    if(choiceType ==1){//post a message on your wall
        string post;
        ofstream newPost("posts",ios::app);//create file to save' users posts without deleting the existing ones
        cout<<"Write the post you want :"<<endl;
        cin.ignore();
        getline(cin,post);

        //write inside the posts' file the logged in user's name and his post under it
        newPost <<logname <<'\n';
        newPost<<post<<'\n';
        newPost.close();
        //close the file and go back to main menu
        goback();
    }else if(choiceType==2){
        string myChoice = "Y";
        //repeat the process to choose friend and check his posts
        while(myChoice == "y" || myChoice == "Y"){
            ifstream friends;
            friends.open(logname.c_str());//open file of logged in users friends
            cout<< endl <<"Your Friends are : "<< endl << string(19,'=') << endl;
            int j = 1 ;
            while(getline(friends,Friend) && Friend != ""){
                    cout << "[" << j << "] "<< Friend << endl;
                    j++;
            }
            friends.close();

            string tempFriend;

            cout<< endl << "Choose the number of friend you want to view post of : ";
            int friendNum;
            cin >> friendNum;

            int l = 0;
            ifstream  myFriends(logname.c_str());
            ofstream  postTemp("Temp");

            while(!myFriends.eof()){
                l++;
                getline(myFriends,Friend);
                //check the number the user typed
                if(friendNum == l){
                    cout<< endl << "Friend : "<<Friend << endl << string(Friend.size(),'=')+"==========" << endl;
                    int i = 1;
                    ifstream allPosts;
                    allPosts.open("posts");
                    while(!allPosts.eof()){
                        getline(allPosts,name,'\n');
                        getline(allPosts,posts,'\n');
                        if(name== Friend){
                            cout<<" Post " << i <<" : "<< posts << endl;
                            postTemp << posts << endl;
                            i++;
                        }
                        tempFriend= Friend;
                    }
                    allPosts.close();
                }else{
                    continue;
                }
            }
            postTemp.close();
            string moreReplies = "Y";

            // process to reply to a friend's posts
            while(moreReplies== "Y"|| moreReplies == "y"){
                cout << endl << "Choose the post you wish to reply to \e[3m(type the number)\e[0m : ";
                int numReply;
                cin>>numReply;
                
                ifstream postTemp("Temp");
                int a = 0;
                while(!postTemp.eof()){
                    a++;
                    getline(postTemp , posts);
                    if(numReply == a){
                        ifstream repost;
                        repost.open("conversations");

                        ofstream temprepost("TempRePost");
                        bool b = false;
                        while(!repost.eof()){
                            getline(repost, namepost);
                            if(namepost.substr(0,namepost.find(":"))==tempFriend && namepost.find(posts)!= std::string::npos)
                                b=true;
                            temprepost<< namepost <<endl;
                        }
                        temprepost.close();

                        ifstream tempPosts;
                        tempPosts.open("TempRePost");
                        
                        ofstream postreplies("conversations");
                        string post ; 
                        cout<<"Enter Your Reply ... " << endl;
                        cin.ignore();
                        string userReply;
                        getline(cin, userReply);//logged in user enters his reply to post
                        while(getline(tempPosts,post) && post!= ""){
                            if(b == true){
                                if(post.substr(0,post.find(":")) == tempFriend && post.find(posts) != std::string::npos){
                                    postreplies << post << endl <<string((tempFriend.size()+2),' ')<<userReply<< " ("+ logname+")"<<endl;
                                    continue;
                                }else{
                                    postreplies<<post<<endl;
                                }
                            }else if(b==false){
                                postreplies<<post<<endl;
                            }
                            
                        }
                        if(b == false)
                            postreplies <<tempFriend<<": "<<posts<< endl<<string((tempFriend.size()+2),' ')<< userReply << "( "+ logname +")"<<endl;
                        // Close Files
                        tempPosts.close();
                        postreplies.close();
                        remove("TempRePost");
                    }
                }
                cout<<endl <<"Reply To other posts of the same friend? (Y/N) :";
                cin >>  moreReplies;
                if(moreReplies== "y" || moreReplies=="Y"){
                    continue;
                }else{
                    postTemp.close();
                    remove("Temp");
                    break;
                }        
            }
            cout<<endl<<"See Other Friend's Wall ? (Y/N) :";
            cin>>myChoice;
            if((myChoice == "Y") || (myChoice == "y"))
                continue;
            else{
                myFriends.close();
                goback();
                break;
            }
        }
    }else if(choiceType== 3){
        string myChoice = "Y";
        //Repeat process to choose Friend to view Posts
        while(myChoice=="Y" || myChoice=="y"){
            ifstream friends;
            friends.open(logname.c_str()); // Open file of logged in user's friends
            
            cout << "Your friends are : " << endl << string(19, '=') << endl;
            int j=1;
            // Process to print a numbered list of logged in user's friends
            while(getline(friends, Friend) && Friend!="")
            {
                cout << "[" << j << "] " << Friend << endl;
                j++;
            }
            friends.close();
            
            string tempFriend;
            cout << endl << "Choose the number of friend you want to view his posts : ";
            int friendNum;
            cin >> friendNum; // Enter number of friend
            ifstream myFriends(logname.c_str());
            ofstream postTemp("Temp");

            int l = 0;
            while(!myFriends.eof()){
                l++;
                if(friendNum == l){
                    cout<< endl << "Friend : " << Friend << endl<< string(Friend.size(),'=')+"========"<<endl;
                    int i = l;
                    ifstream allPosts;
                    allPosts.open("posts");
                    while(!allPosts.eof()){
                        getline(allPosts,name,'\n');
                        getline(allPosts,posts,'\n');
                        if(name == Friend){
                            cout<<" Post" << i << " : "<< posts<< endl;
                            postTemp << posts << endl;
                            i++; 
                        }
                        tempFriend = Friend;
                    }
                    allPosts.close();
                }
                else    
                    continue;
            }
            postTemp.close();
            string moreReplies ="Y";

            while(moreReplies== "Y" || moreReplies == "y"){
                cout << endl << "Choose the post you wish to leave a Like \e[3m(type it's number\e[0m) : ";
                int numReply;
                cin >> numReply;

                ifstream posttemp("Temp");
                int a = 0;
                while(!posttemp.eof()){
                    a++;
                    getline(posttemp,posts);
                    if(numReply == a ){
                        ifstream likes;
                        likes.open("likes");
                        string namepost;

                        ofstream templikes("TempLikes");
                        bool b = false; // Variable to check if friend and posts exists on file
                        while(!likes.eof()){
                            getline(likes, namepost);
                            if(namepost.substr(0,namepost.find(":"))== tempFriend && namepost.find(posts)!= std::string::npos)
                                b = true;
                            templikes << namepost << endl;
                        }
                        templikes.close();

                        ifstream tempLikes;
                        tempLikes.open("TempLikes");
                        ofstream replies("likes");
                        string like;
                        while(getline(tempLikes,like) && like!= ""){

                            //check if friends  post already exist . then leave a like under the post and before the latest likes.
                            if(b== true){
                                if(like.substr(0,like.find(":"))== tempFriend && like.find(posts) != std::string::npos){
                                    replies<<like<<endl<<string((tempFriend.size()+2),' ') << "LIKE!"<< " ("+logname+")"<< endl;
                                    continue;
                                }else 
                                replies << like << endl;
                            }else if(b== false)//if friends post doesn't exist write the name of the friend and his post to leave a like under it 
                                replies << like << endl;
                            
                        }
                        if(b== false)
                            replies << tempFriend << ": "<< posts << endl << string((tempFriend.size()+2),' ')<<"LIKE!"<< " ("+logname+")" <<endl;

                        tempLikes.close();
                        replies.close();
                        remove("TempLikes");
                    }
                }
                cout << endl << "Leave  a LIKE to to other posts of the same friend ? (Y/N) : ";
                cin >> moreReplies;
                if((moreReplies == "Y") || (moreReplies == "y"))
                    continue;
                else{
                    posttemp.close();
                    remove("Temp");
                    break;
                }
            }

            cout << endl << "See other friends wall ? (Y/N) :";
            cin >> myChoice;
            if(myChoice == "y" || myChoice == "Y"){
                cout<<endl;
                continue;
            }
            else{
                myFriends.close();
                goback();
            }
        }
    }else {
        menu2();
    }
}

#endif //VIEWFRIENDSPOSTS_H