#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n % 7 == 0){
			cout << n << endl ;
		}
		else if(n>14){
			int rem;
			rem = n % 7;
			n = n - rem;
			cout << n << endl ;
	    }
		else if(n>=10){
			int rem;
			rem = n % 7;
			n = (7-rem) + n;
			cout << n << endl;
		}
   }
   	return 0;
}
