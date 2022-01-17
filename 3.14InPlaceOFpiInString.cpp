#include<iostream>
#include<string.h>
using namespace std;

string modstr(string str){
    int x = str.length() ;
    string modString;
    if(x==0 || x==1){
        return str ;
    }
    if(str[0] == 'p' && str[1]== 'i'){
        modString = modstr(str.substr(2)) ;              //str.substr(index), here index indicates from which position 
        return "3.14" +  modString ;                     //you want your sub-string .
    }                                                    //Ex:  let str ="mycode"
    else{                                                //  index  ->    012345 
        return str[0] + modstr(str.substr(1)) ;          // so, str.substr(3) = "ode"
    }
}

int main(){
    string str;
    cin >> str ;
    cout << modstr(str) ;
}