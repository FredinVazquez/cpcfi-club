#include<bits/stdc++.h>
using namespace std;


int main()
    {
        string s; cin>>s;
        int contador = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(s[i]=='Q'){
                    if(s[j]=='A'){
                        for(int k=j+1;k<s.size();k++){
                            if(s[k]=='Q') contador++;
                        }
                    }
                }
            }    
        }
        cout<<contador;
        return 0;
    }