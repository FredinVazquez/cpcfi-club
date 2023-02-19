#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	
	for(int i=0;i<t;i++)
	    {
	        // rooms and bottles
	        int n,m; cin>>n>>m;
	        
	        vector<int> v(m+1);
	        vector<priority_queue<int>> litros_por_botella(n+1);
	        
	        
	        // First, the order of rooms visited
	        for(int a=0;a<m;a++)        cin>>v[a];
	        
	        // Second, the number of bottles and litres each of them.
	        for(int b=0;b<n;b++)
	            {
	                int bottles; cin>>bottles;
	                int litre;
	                
	                for(int c=0;c<bottles;c++)
	                    {
	                        cin>>litre;    
	                        litros_por_botella[b].push(litre);
	                    }
	            }
	            
	        int ans = 0;
	        // Order of visited
            for(int a=0;a<m;a++)
                {
                    if(!litros_por_botella[v[a]].empty())
                        {
                            ans += litros_por_botella[v[a]].top();
                            litros_por_botella[v[a]].pop();
                        }
                }
            cout<<ans<<endl;
	    }
	
	return 0;
}

