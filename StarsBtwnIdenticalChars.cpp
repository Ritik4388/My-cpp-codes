//Given a string S, compute recursively a new string where identical chars that are 
//adjacent in the original string are separated from each other by a "*".


#include<iostream>
#include<string.h>
using namespace std;

string modstr(string str){
    if(str.length() == 1){
        return str;
    }
    if(str[0] == str[1]){
        return str.substr(0,1) + "*" + modstr(str.substr(1)) ;
    }
    else{
        return str[0] + modstr(str.substr(1)) ;
    }
}

int main(){
    string str;
    cin >> str ;
    cout << modstr(str) ;
}