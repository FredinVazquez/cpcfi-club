#include<bits/stdc++.h>
using namespace std;

void solve()
    {
        int n; cin>>n;
        string s; cin>>s;
        char minimo = 'z';
        int index = 0;
        for(int i=0;i<n;i++)
            {
                if(minimo >= s[i])
                {
                    minimo = s[i];
                    index = i;
                }
                
            }
        
        string ans = s;
        
        // de 1 a i, en 0 está el movido
        //cout<<s.substr(0,index)<<endl;
        ans.replace(ans.begin()+1,ans.begin()+index+1,s.substr(0,index));
        
        //ans.replace(ans.begin()+index,ans.end(),s.substr(index,s.size()));
        
        ans[0] = minimo;
        cout<<ans<<endl;
    }

int main()
    {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int t; cin>>t;
        long long ans = 0;
        
        for(int i=0;i<t;i++)
            {
                solve();
                
            }
        
        return 0;
    }