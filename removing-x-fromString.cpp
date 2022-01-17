#include<iostream>
#include<string.h>
using namespace std;

string modstr(string str){
    if(str[0] == 'x' && str.length() == 1){
        return "\0";
    }
    if(str.length() == 1){
        return str;
    }
    if(str[0] == 'x'){
        return modstr(str.substr(1)) ;
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