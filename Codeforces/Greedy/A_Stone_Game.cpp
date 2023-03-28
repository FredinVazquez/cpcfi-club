#include<bits/stdc++.h>
using namespace std;



int main()
    {
        int t; cin>>t;
        while(t--){
            int n; cin>>n;
            vector<int> v(n);
            
            int maximo = -1e9;
            int minimo = 1e9;
            
            for(int i=0;i<n;i++){
                cin>>v[i];
                maximo = max(maximo,v[i]);
                minimo = min(minimo,v[i]);
            }
            
            int movimientos = 0;
            int ans = 1e9;
            
            // opción 1:
            for(int i=0;i<n;i++){
                movimientos++;
                if(v[i] == maximo) break;
            } 
            for(int i=(v.size()-1);i>=0;i--){
                movimientos++;
                if(v[i] == minimo) break;
            } 
            
            ans = min(ans,movimientos);
            
            // opción 2:
            movimientos = 0;
            for(int i=0;i<n;i++){
                movimientos++;
                if(v[i] == minimo) break;
            } 
            for(int i=(v.size()-1);i>=0;i--){
                movimientos++;
                if(v[i] == maximo) break;
            } 
            ans = min(ans,movimientos);
            
            // opción 3:
            movimientos = 0;
            int e1=0,e2=0;
            for(int i=0;i<n;i++){
                if(v[i]==maximo) e1 = 1;
                if(v[i]==minimo) e2 = 1;
                movimientos++;
                if(e1==1 && e2==1) break;
            }
            ans = min(ans,movimientos);
            
            //opción 4
            movimientos = 0;
            e1=0,e2=0;
            for(int i=v.size()-1;i>=0;i--){
                if(v[i]==maximo) e1 = 1;
                if(v[i]==minimo) e2 = 1;
                movimientos++;
                if(e1==1 && e2==1) break;
            }
            ans = min(ans,movimientos);
            
            cout<<ans<<endl;
        }
        return 0;
    }