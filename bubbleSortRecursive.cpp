//using dynamic array.

#include<iostream>
using namespace std;


int bubbleSort(int a[], int n){
    if(n == 1){
        return a[0];
    }
    else{
        for(int j=0; j<n-1; j++){       //j<n-1 as (n-1)th index is last and we can't (j+1) there.
         if(a[j]>a[j+1]){
             int temp;
             temp = a[j] ;
             a[j] = a[j+1] ;
             a[j+1] = temp ;
           }
         }
         for(int i=0; i<n; i++){           //---   
         cout << a[i] << " ";               //|      to check arrangement of array before nxt recursive call.
         }                                  //|       you can ignore it , it was just for clarification.
         cout << endl ;                    //---
         return bubbleSort(a,n-1);        
    }
}

int main(){    
     int n;
     cin >> n;
     int *a = new int[n];
     for(int i=0; i<n; i++){
         cin >> a[i];
     }
     bubbleSort(a,n) ;
     for(int i=0; i<n; i++){
         cout << a[i] << " ";
     }
     delete [] a ;
 return 0;
}