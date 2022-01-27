//using dynamic array.

#include<iostream>
using namespace std;

int main(){    
     int n;
     cin >> n;
     int *a = new int[n];
     for(int i=0; i<n; i++){
         cin >> a[i];
     }
    
     for(int i=2; i<n; i++){

         while(a[i]<a[i-1]){

             int temp;
             temp = a[i];
             a[i] = a[i-1];
             a[i-1] = temp;
             i--;
             if(i==0){
                 break;
             }
         }
     }

     for(int i=0; i<n; i++){
         cout << a[i] << " ";
     }
     delete [] a ;
 return 0;
}