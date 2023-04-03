#include<bits/stdc++.h>
using namespace std;

bool isLower(char c)
    {
        if(c>=97 && c<=122) return true;
        return false;
    }

int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t; cin>>t;
        while(t--)
            {
                int n,k; cin>>n>>k;
                string s; cin>>s;
                
                map<char,int> mapa;
                for(int i=0;i<n;i++)        mapa[s[i]]++;
                
                int ans = 0;
                for(int i=0;i<n;i++)
                    {
                        if(mapa[s[i]] == 0) continue;
                        if(isLower(s[i]))
                            {
                            
                                // Buscamos su versión upper
                                if(mapa[s[i]-32] > 0)
                                    {
                                        ans++;
                                        mapa[s[i]-32]--;
                                        mapa[s[i]]--;
                                        //cout<<s[i]<<endl;
                                    }
                                else
                                    {
                                        // En caso que no se estará buscando entonces 
                                        // otro para convertir, siempre y cuando k>0
                                        if(k>0 && mapa[s[i]] > 1)
                                            {
                                                ans++;
                                                mapa[s[i]]--;
                                                mapa[s[i]]--;
                                                k--;
                                                //cout<<s[i]<<endl;
                                            }
                                    }
                            }
                        else
                            {
                                // Buscamos su versión lower
                                if(mapa[s[i]+32] > 0)
                                    {
                                        ans++;
                                        mapa[s[i]+32]--;
                                        mapa[s[i]]--;
                                        //cout<<s[i]<<endl;
                                    }
                                else
                                    {
                                        // En caso que no se estará buscando entonces 
                                        // otro para convertir, siempre y cuando k>0
                                        if(k>0 && mapa[s[i]] > 1)
                                            {
                                                ans++;
                                                mapa[s[i]]--;
                                                mapa[s[i]]--;
                                                k--;
                                                //cout<<s[i]<<endl;
                                            }
                                    }
                            }
                    }
                cout<<ans<<endl;
            }
        
        return 0;
    }