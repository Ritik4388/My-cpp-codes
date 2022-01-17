//Count no. of digits in a given number .

#include<iostream>
using namespace std;            

int nDigits(int n,int a=0){
    if(n==0){
         return a ;
    }
    return nDigits(n/10,a+1) ;
}

int main(){
    int n;
    cin >> n;
    cout << nDigits(n) ;              //for n>=1
}