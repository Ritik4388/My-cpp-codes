include<iostream>
using namespace std ;
                          // defining function
int fact(int n){
    int fact2 ;
    if(n==0){
       return 1 ;
    }
    fact2 = n * fact(n-1) ; 
    return fact2 ;
}

 int main(){
    int n ;
    cin >> n ;
    cout << n << "!" << " = " << fact(n) ; // calling function
    return 0;
}
