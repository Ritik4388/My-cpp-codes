#include<iostream>
using namespace std;

int fib(int n){      
    if(n==0){
        return 0 ;
    }
    if(n==1){
        return 1 ;
    }
    int pre = fib(n-1) + fib(n-2) ;     //In recursion keep 3 things in mind :
    return pre ;                        //1.  determine base cases  
}                                       //2.  according to mathematical induction assume that       
int main(){                             //    whenever f(k) is true f(k-1) will be also true ,
    int n;                              //    so call for f(k-1) and don't deep dive into it .
    cin >> n;                           //3.  At last dry code for smaller values of k .
    cout << fib(n) ;
}