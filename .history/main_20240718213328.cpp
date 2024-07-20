/* small Social Media Network in c++ by jet_black_ninja
no rights reserved
*/

//Header Files
#include <sstream>
#include "./headerFiles/listusers.h"
#include "./headerFiles/mainMenu.h"

using namespace std;
//Variables

string regname , regpass;
string logname , logpass;
string name , password;
string namepost , reply;
string posts;
string friendName , Friend;
int numOfUsers = -1;


//Main Function

int main{
    string graph_title = "||"+string(39,'=')+"||";
    cout<<graph_title <<endl;
    cout<<"||"+string(9,' ')+"\e[1mSOCIAL NETWORK IN C++ \e[0m"+string(9,' ')+"||"<<endl;
    cout<<"|| \e[3mA Social Network Project built in C++]\e[0m"<<endl;
    listusers();
    ostringstream tstr; 
}