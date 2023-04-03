#include<bits/stdc++.h>
using namespace std;

int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t; cin>>t;
        while(t--)
            {
                int n; cin>>n;
                string s; cin>>s;
                int r=0;
                for(int i=2;i<n;i++)
                    {
                        //aaabcc
                        //aa
                        // aa
                        //a a
                        // Nos damos cuenta que el de en medio coincide (siempre se elimina), así que solo nos
                        // fijamos en i y i+2
                        if(s[i-2] == s[i])
                            r++;
                    }
                cout<<(n-1)-r<<endl;
            }
        
        return 0;
    }