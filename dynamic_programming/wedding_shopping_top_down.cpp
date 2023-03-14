#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> memo(100,vector<int> (205,-1));

int pay = 1e5;

bool isValid(int test)
    {
        if(test>=0)  return true;
        else         return false;
    }

int backtrack(vector<vector<int>> &v, int next,int total,int badge)
    {
        if((next == total) )
            {
                return badge;
                
            }
        else
            {
                if(memo[next][badge]!=-1){
                    //cout<<"entra"<<endl;
                    return memo[next][badge];
                }
                    
                
                for(int i=1;i<=v[next][0];i++)
                    {
                        if(isValid(badge-v[next][i]))
                            {
                                pay = min(pay,backtrack(v,next+1,total,badge-v[next][i]));        
                            }
                    }
            }
        return memo[next][badge] = pay;
    }

int main()
    {
        int t; cin>>t;
        int k,c;
        int c_i,tmp; 
        for(int i=0;i<t;i++)
            {
               cin>>k>>c;
               vector<vector<int>> v(c);
                for(int j=0;j<c;j++)
                    {
                        cin>>c_i;
                        v[j].push_back(c_i);
                        for(int a=0;a<c_i;a++)
                            {
                                cin>>tmp;
                                v[j].push_back(tmp);
                            }
                    }
                // Se guardó todos los elementos
                pay = 100000;
                backtrack(v,0,c,k);
                if(pay==100000) cout<<"No solution."<<endl; 
                else            cout<<k-pay<<endl;
                memo.clear();
            }
        
        return 0;    
    }
