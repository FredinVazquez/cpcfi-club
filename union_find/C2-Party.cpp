#include<bits/stdc++.h>
using namespace std;


// UNION - FIND
int numSets = 0;

int find_set(int x,vector<int> &linked,vector<int> &size)
    {
        while(x != linked[x])   x = linked[x];
        return x;
    }

bool isSameSet(int u,int v,vector<int> &linked,vector<int> &size)
    {
        if(find_set(u,linked,size)==find_set(v,linked,size))
            return true;
        else
            return false;
    }

void union_set(int u, int v,vector<int> &linked,vector<int> &size)
    {
        // Counting sets
        if(!isSameSet(u,v,linked,size))
            {
                numSets--;
        
        // Find their representatives
        int a = find_set(u,linked,size);
        int b = find_set(v,linked,size);
        
        // who is greater?
        if(size[a]<size[b])
            {
                swap(a,b);      // Standar, always chained with a
            }
        
        // In other case
        linked[b] = a;
        
        // Increase the size
        size[a] += size[b];
            }
    }


int numDisjointSets()
    {
        return numSets;
    }




int main()
    {
        int n; cin>>n;
        numSets = n;
        
        
        vector<int> linked(n+1);
        vector<int> size(n+1,1);
        
        for(int i=1;i<=n;i++)   linked[i] = i;
        
        int u,v;
        int t1; cin>>t1;
        for(int i=0;i<t1;i++)
            {
                cin>>u>>v;
                union_set(u,v,linked,size);
            }
        
        int setOk = numDisjointSets();
        
        //cout<<setOk;
        
        // Delete bad sets
        int t2; cin>>t2;
        
        // Se va a aceptar el que tenga más y se rechaza el que tiene menos
        vector<int> checando(n+1,1);
        
        for(int i=0;i<t2;i++)
            {
                cin>>u>>v;
                
                if(isSameSet(u,v,linked,size))
                    {
                        checando[find_set(u,linked,size)] = 0;
                    }
                
            }
        
        // Checar los que no están apagados
        int ans = 0;
        for(int i=1;i<=n;i++)
            {
                if(checando[find_set(i,linked,size)] == 1)
                    {
                        ans = max(ans,size[find_set(i,linked,size)]);
                    }
            }
        
        cout<<ans;
        
        return 0;
    }


