#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int i=l, j=mid+1 ,k=l;
    vector<int> v;
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            v[k] = arr[i];
            j++;
        }
        else{
            v[k] = arr[j];
            i++;
        }
        k++;
    }

    if(i>mid){
        while(j<=r){
            v[k] = arr[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid){
            v[k] = arr[i];
            k++;
            i++;
        }
    }

    for(k=l; k<=r; k++){
        arr[k] = v[k];
    }
    
    for(int i=l; i<=r; i++){
        cout << arr[i] << " " ;
    }
    cout << endl << endl ;
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = l/2 + r/2 ;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr,l,mid,r);
    for(int i=l; i<=r; i++){
        cout << arr[i] << " " ;
    }
    cout << endl << endl ;
    }
    else return;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i] ;
    }

    mergeSort(arr , 0 , n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " " ;
    }

    delete []arr;
 return 0;
}