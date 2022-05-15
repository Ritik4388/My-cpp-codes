#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		long int count = 0,n = str.length();
		for(long int i=0; i<n;i++){
		    if(str[i] == '0'){
		        count++;
		    }
		}
		long int one = abs(n-count);
        if(count == one){
            cout << "0" << endl;
        }
		else {
            cout << min(count,one) << endl ;
        }
   }
   	return 0;
}
