//using dynamic array.

#include<iostream>
using namespace std;
int main()
{    
     int n;
     cin >> n;
     int *a = new int[n];
     for(int i=0; i<n; i++){
         cin >> a[i];
     }
     int swap = 1;
     while(swap!=0){
         swap = 0;
         for(int j=0; j<n-1; j++){       //j<n-1 bcoz at (n-1)th index is last and we can't (j+1) there.
         if(a[j]>a[j+1]){
             int temp;
             temp = a[j] ;
             a[j] = a[j+1] ;
             a[j+1] = temp ;
             cout << a[j] << endl ;
             swap++;
           }
         }
     }
     for(int i=0; i<n; i++){
         cout << a[i] << " ";
     }
     delete [] a ;
 return 0;
}