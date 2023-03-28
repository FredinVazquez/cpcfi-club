#include<bits/stdc++.h>
using namespace std;

void solve(int dif, map<char,int> &mapa){
    if(dif >2 && dif<=4){
       cout<<"4"<<endl;
       return;
   }
   
   int contador = 0;
    if(dif == 2){
        for(auto it : mapa){
            if(it.second == 2){
                contador++;
                
            }
        }
        
        if(contador == 2){
            cout<<"4"<<endl;
            return;
        }
        
        for(auto it: mapa){
            if(it.second > 2){
               cout<<"6"<<endl;
               return;
            }
       }
       
    }
    
    if(dif == 1){
        cout<<"-1"<<endl;
        return;
    }
}

int main()
    {
        int t; cin>>t;
        
        while(t--){
            string s; cin>>s;
            map<char,int> mapa;
            int diferentes = 0;
            for(int i=0;i<s.size();i++){
                if(mapa[s[i]] == 0){
                    mapa[s[i]]++;
                    diferentes++;
                }
                else{
                    mapa[s[i]]++;   
                }
            }
            
            solve(diferentes,mapa);
            
            
        }
        
        return 0;
    }