//Tower Of Hanoi Problem


#include<iostream>
using namespace std;

int firstIndex(int arr[], int n, int key){
    int start = 0 ,end =n-1, ans = -1;
    int mid = start/2 + end/2 ;
    while(start <= end){

        if(arr[mid] == key) {
            ans = mid ;
            end = mid - 1 ;
        }

        else if(arr[mid] > key) {
            end = mid - 1 ;
        }

        else if(arr[mid] < key) {
            start = mid + 1 ;
        }
        
        mid = (start/2) + (end/2) ;

    }
    return ans ;
}

int lastIndex(int arr[], int n, int key){
    int start = 0 ,end =n-1, ans = -1;
    int mid = start/2 + end/2 ;
    while(start <= end){

        if(arr[mid] == key) {
            ans = mid ;
            start = mid + 1 ;
        }

        else if(arr[mid] > key) {
            end = mid - 1 ;
        }

        else if(arr[mid] < key) {
            start = mid + 1 ;
        }
        
        mid = (start/2) + (end/2) ;

    }
    return ans ;
}

int main(){                         
   
    int arr[10] = {3,4,2,3,4,5,4,6,2,7};
    cout << firstIndex(arr,10,6) << " " << lastIndex(arr,10,6) ;
    return 0 ;
}                                 