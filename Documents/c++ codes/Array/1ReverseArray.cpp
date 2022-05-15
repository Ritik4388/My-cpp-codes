#include<bits/stdc++.h>
using namespace std;

int fight(long long int hc, long long int dc, long long int hm, long long int dm){
    
    int win = 0;
    hm = hm - dc ;
    cout << endl << hc << " " << hm << endl ;
    if(hm <= 0){
        win = 1;
    }
    if(win == 0){
        hc = hc - dm ;
        cout << endl << hc << " " << hm << endl ;
        if(hc <= 0){
        win = -1;
    }
        if(win == 0){
        fight(hc,dc,hm,dm);
    }
    }
    return win ;
}

int main() {
   long long int t;
   cin >> t;
   while(t--){
       long long int hc ,dc, hm, dm ,k ,w,a,temp ;
       cin >> hc >> dc ;
       cin >> hm >> dm ;
       cin >> k >> w >> a;
       int count = 0;
       if(count == 0){
           dc = k*w + dc ;
           temp = fight(hc,dc,hm,dm);
       }
       if(temp == 1){
           cout << "YES" << endl ;
       }
       else{
           hc = k*a + hc ;
           temp = fight(hc,dc,hm,dm);
       }
       if(temp == 1){
           cout << "YES" << endl ;
       }
       else{
           cout << "NO" << endl ;
       }
   }
   return 0;
}