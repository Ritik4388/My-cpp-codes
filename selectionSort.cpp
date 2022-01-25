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
     for(int i=0; i<n; i++){
         for(int j=i+1; j<n; j++){
             if(a[i]>a[j]){
                 int temp;
                 temp = a[i] ;
                 a[i] = a[j] ;
                 a[j] = temp ;
             }
         }
     }
     for(int i=0; i<n; i++){
         cout << a[i] << " ";
     }
     delete [] a ;
 return 0;
}