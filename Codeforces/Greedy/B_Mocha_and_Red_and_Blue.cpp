#include<bits/stdc++.h>
using namespace std;

void solve(string &s,int n){
    
    char letter = '?';
    
    // 4 cases
    ///Fourht case
    int all = 0;
        for(int i=0;i<n;i++) if(s[i] == '?') all++;
    
    if(all == s.size())
        {
            letter = 'B';
            for(int i=0;i<n;i++){
                s[i] = letter;
                if(letter == 'R') letter = 'B';
                else                letter = 'R';
            }
        }
    
    for(int i=0;i<n;i++){
        
        if(s[i] == '?'){
            
            for(int j=i;j<n;j++){
                // First and third ??? ... ?? (R||B) 
                if(s[j] == 'R' || s[j] == 'B')
                    {
                        if(s[j] == 'R') letter = 'B';
                        else            letter = 'R';
                        for(int a = (j-1);a>=i;a--)
                            {
                                if(s[a] == '?') s[a] = letter;
                                if(letter == 'R') letter = 'B';
                                else                letter = 'R';
                            }
                        break;
                    }
                
                // Second (R||B)??? ... ??
                if(j+1 ==n && s[j]== '?')
                    {
                        if(s[i-1] == 'R') letter = 'B';
                        else            letter = 'R';
                        for(int a = i;a<=j;a++)
                            {
                                if(s[a] == '?') s[a] = letter;
                                if(letter == 'R') letter = 'B';
                                else              letter = 'R';
                            }
                    }
            }
            
        }
    }
    cout<<s<<endl;
    
    
}

int main(){
    
    int t; cin>>t;
    
    for(int i=0;i<t;i++){
        int n; string s; cin>>n>>s;
        
        solve(s,n);
        
    }
    
    return 0;
}