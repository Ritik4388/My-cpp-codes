// In Insertion sort array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked
// and placed at the correct position in the sorted part.
// Algorithm 
// To sort an array of size n in ascending order: 
// 1: Iterate from arr[1] to arr[n] over the array. 
// 2: Compare the current element (key) to its predecessor. 
// 3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements
// one position up to make space for the swapped element.

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
    
     for(int i=1; i<n; i++){

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
