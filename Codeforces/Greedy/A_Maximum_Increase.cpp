#include<bits/stdc++.h>
using namespace std;



int main()
    {
        int t; cin>>t;
        
        int ans = -1e9;
        int length = 0;
        long long act,prev = -1e9;
        
        
        for(int i=0;i<t;i++){
            cin>>act;
            if(prev<act){
                prev = act;
                length++;
                ans = max(ans,length);
            }
            else{
                prev = act;
                ans = max(ans,length);
                length = 1;
            }
        }
        
        cout<<ans<<endl;
        return 0;
    }