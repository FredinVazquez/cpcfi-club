#include<bits/stdc++.h>
using namespace std;
 
int main()
    {
        int n; cin>>n;
        vector<string> v;
        v.push_back("0");
        v.push_back("1");
        
        int times = (1<<n);
        
        
        // Subset 2n - Increase in power of two, that's why is possible recover the previous solutions
        for(int i=2;i<(1<<n);i = (i<<1))
            {
                // The previous soluytions:}
                for(int j=(i-1);j>=0;j--)
                    {
                        v.push_back(v[j]);
                    }
                int tamano = v.size();
                // Add 0 the first half
                for(int j=0;j<(tamano/2);j++)
                    {
                        v[j] += "0"; 
                    }
                
                
                // Add 1 the second half
                for(int j=tamano/2;j<(tamano);j++)
                    {
                        v[j] += "1"; 
                    }
            }
        
        // PRint the all solutions:
        for(auto it: v)
            {
                cout<<it<<endl;
            }
        
        return 0;
    }