#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int t; cin>>t;
    vector<int> v(t+1);
    int even = 0;
    int odd  = 0;
    
    for(int i=0;i<t;i++)
        {
            cin>>v[i];
            if(v[i]%2==0) even++;
            else        odd++;
        }
    
    if(even>odd)
        {
            for(int i=0;i<t;i++)
                {
                    if(v[i]%2!=0)
                        {
                            cout<<i+1<<endl;
                            break;
                        }
                }
        }
    else
        {
            for(int i=0;i<t;i++)
                {
                    if(v[i]%2==0)
                        {
                            cout<<i+1<<endl;
                            break;
                        }
                }
        }
    
	return 0;
}

