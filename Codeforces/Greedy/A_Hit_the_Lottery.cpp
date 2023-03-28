#include<bits/stdc++.h>
using namespace std;

// 1, 5, 10, 20, 100

int main()
    {
        int n; cin>>n;
        vector<int> bills(5);
        bills[0] = 1;   bills[1] = 5;   bills[2] = 10;   bills[3] = 20;   bills[4] = 100;
        
        int ans = 0;
        int pointer1=4;
        
        while(n>0){
            if((n-bills[pointer1]) >= 0) n-=bills[pointer1], ans++;
            else                      pointer1--;
        }
        
        cout<<ans<<endl;
        return 0;
    }