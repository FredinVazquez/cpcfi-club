#include<bits/stdc++.h>
using namespace std;

void solve(long long ans, vector<long long> &v,int n)
    {
        long long comparer = 0;
        vector<long long> comp(v.size()+10,0);
        
        for(int j=0;j<n;j++)
            {
                
                comp[j] = ans ^ v[j];
                //cout<<"comparer: "<<v[j]<<endl; 
            }
        
        comparer = 0;
        for(int j=0;j<n;j++)
            {
                comparer ^= comp[j];
            }
        
        if(comparer == 0)   cout<<ans<<endl;
        else            cout<<"-1"<<endl;
    }

int main()
    {
        int t; cin>>t;
        long long ans = 0;
        
        for(int i=0;i<t;i++)
            {
                int n; cin>>n;
                ans = 0;
                vector<long long> v(n+10);
                
                for(int j=0;j<n;j++)
                    {
                        cin>>v[j];
                        ans ^= v[j];    
                    }
                //cout<<ans<<endl;
                solve(ans,v,n);                
                             
                
            }
        
        return 0;
    }