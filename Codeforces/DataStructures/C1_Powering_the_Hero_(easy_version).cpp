#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &v,int n,long long ans)
    {
        priority_queue<long long> p;
        for(int i=0;i<n;i++)
            {
                if(v[i] == 0)
                {
                    if(p.empty())   continue;
                    else
                        {
                            ans += p.top();
                            p.pop();
                        }
                }
                else
                {
                    p.push(v[i]);
                }
            }
        cout<<ans<<endl;
        return;
    }


int main()
    {
        int t; cin>>t;
        while(t--)
            {
                int n; cin>>n;
                vector<int> v(n);
                for(int i=0;i<n;i++)    cin>>v[i];
                
                solve(v,n,0);
            }
        
        return 0;
    }