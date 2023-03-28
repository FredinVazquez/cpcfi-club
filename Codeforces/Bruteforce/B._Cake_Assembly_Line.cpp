#include<bits/stdc++.h>
using namespace std;

int main()
    {
        int t; cin>>t;
        int n,w,h; 
        
        while(t--){
            cin>>n>>w>>h;
            
            vector<int> limite_pastel(n);
            vector<int> limite_dispenser(n);
            
            for(int i=0;i<n;i++)        cin>>limite_pastel[i];
            
            for(int i=0;i<n;i++)        cin>>limite_dispenser[i];
            
            /*
                La intersecciones entre todas las distancias de los pasteles 
                será la respuesta, es necesario observar que se va a tener que encontrar
                que existe una intersección con todos los pasteles. Se tiene que encontras
                n intersecciones. En caso que existe quiere decir entonces que existe
                un rango 'k' tal que pueden ir los pasteles ahí en ese rango. En caso que
                las intersecciones sea un conjunto vacío (que no exista), no hay solución.
            */
            
            int left = -1e9;
            int right = 1e9;
            
            for(int i=0;i<n;i++)
                {
                    left = max(left,limite_dispenser[i]+h-limite_pastel[i]-w);
                    right = min(right,limite_dispenser[i]-h-limite_pastel[i]+w);
                }
            
            if(left <= right)    cout<<"YES"<<endl;
            else                cout<<"NO"<<endl;
        }
        
        return 0;
    }
