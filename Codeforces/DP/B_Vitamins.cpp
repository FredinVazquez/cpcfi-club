#include<bits/stdc++.h>
using namespace std;

int get_bits(string &s)
    {
        int bits = 0;
        for(auto it: s){
            if(it == 'A'){
                bits |= 1; 
            }
            
            if(it == 'B'){
                bits |= 2;
            }
            
            if(it == 'C'){
                bits |= 4;
            }
        }
        return bits;
    }


void imprimir(vector<vector<int>> &dp,int t){
    cout<<endl;
    for(int i=0;i<t+1;i++){
        for(int j=0;j<8;j++)
            {
                cout<<dp[i][j]<<" ";
            }
        cout<<endl;
    }
    return;
}


int main()
    {
        int t; cin>>t;
        
        vector<vector<int>> dp(t+1, (vector<int> (8,1e9)));
        dp[0][0] = 0;
        for(int i=0;i<t;i++){
            int cost; cin>>cost;
            string s; cin>>s;
            int bits = get_bits(s);
            
            for(int j=0;j<8;j++){
                // Este sería para ver que no se toma: pero si es mejor el actual o previo
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
                // Este es para ver en caso que se toma, sería sumar la parte anterior con la 
                // parte que se suma, se tiene que acceder al costo original y asignarle al
                // la posición nueva tras hacer or
                dp[i+1][j | bits] = min(dp[i+1][j | bits],dp[i][j]+cost);
                //
            }
            //imprimir(dp,t);
        }
        int ans = dp[t][7];
        
        if( ans == (1e9)){
            cout<<"-1";
        }
        else{
            cout<<ans;
        }
        
        return 0;
    }