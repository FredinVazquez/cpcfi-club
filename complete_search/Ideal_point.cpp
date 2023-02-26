#include <bits/stdc++.h>
using namespace std;

bool solve(vector<pair<int,int>> &v,int &x)
    {
        // Primero se elimina todos los segmentos que no se tenga k, tal que los restantes
        // serán los que tenga k, por ende solo vamos a poder tener dos respuestas, que sea k el maximo
        // o tener otro máximo de la misma cantidad de intersecciones como k
        unordered_map<int,int> intersections;
        
        
            
        for(int i=0;i<v.size();i++)
            {
                if(x>=v[i].first && x<=v[i].second )
                    {
                        for(int j=v[i].first;j<=v[i].second;j++)
                            {
                                intersections[j]++;
                            }
                    }
            }
        
        for(int i=1;i<=50;i++)
            {
                if(i==x) continue;
                
                if(intersections[i] >= intersections[x])
                    {
                        return false;
                    }
            }
        return true;
        
    }


int main() {
    
    int t; cin>>t;
    for(int i=0;i<t;i++)
        {
            int n,x; cin>>n>>x;
            vector<pair<int,int>> v;
            
            for(int j=0;j<n;j++)
                {
                    int a,b; cin>>a>>b;
                    v.push_back(make_pair(a,b));
                    
                }
            
            if(solve(v,x))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            
        }
    
	return 0;
}

