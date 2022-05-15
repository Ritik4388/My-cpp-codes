#include<iostream>
#include "hashmap.h"
using namespace std;

int main(){
    Bucket<int> b;
    for(int i=0; i<10; i++){
        string s = "abc";
        char c = '0'+ i;
        s = s + c;
        int value = i + 1;
        b.insert(s, value);
        cout << b.loadFactor() << endl;
    }

    for(int i=0; i<10; i++){
        string s = "abc";
        char c = '0'+ i;
        s = s + c;
        cout << s << " : " << b.getValue(s) << endl;
    }

     cout << b.size();
    return 0;
}