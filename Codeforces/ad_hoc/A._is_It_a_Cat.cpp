#include<bits/stdc++.h>
using namespace std;

bool isLower(char c)
    {
        if(c>=97 && c<=122) return true;
        return false;
    }

void solve(int n)
    {
        string s; cin>>s;
        for(int i=0;i<n;i++)
            {
                if(!isLower(s[i]))
                    s[i]+=32;
            }
            
        string v;    
        for(int i=0;i<n;i++)
            {
                if(v.size() != 0)
                    {
                        if(v.back() != s[i])
                        v += s[i];
                    }
                else
                    v += s[i];
            }
        if(v == "meow")
            {
                cout<<"YES"<<endl;
                return;
            }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
            
    }

int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t; cin>>t;
        while(t--)
            {
                int n; cin>>n;
                solve(n);
            }
        
        
        return 0;
    }