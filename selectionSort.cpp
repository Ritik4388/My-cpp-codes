//using dynamic array

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
         int min = i;
         for(int j=i+1; j<n; j++){
            if(a[j]<a[min]){
                min = j;
            }
         }
         int temp;
         temp = a[i];
         a[i] = a[min];
         a[min] = temp;

         for(int i=0; i<n; i++){          // to check what is going on each step
         cout << a[i] << " ";
         }
         cout << endl << endl ;
     }
     for(int i=0; i<n; i++){
         cout << a[i] << " ";
     }
     delete [] a ;
 return 0;
}
