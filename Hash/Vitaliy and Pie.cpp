#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n; cin>>n;   
    n+=(n-2);
    int ans=0;
    char l;
    map<char,int> mapa;
    for(int i=1;i<=n;i++)
        {
           cin>>l;
           
           //odd
           if(i%2!=0) mapa[toupper(l)]++;
           else{
               //even
               if(mapa[l]==0)   ans++;
               else             mapa[l]--;
           }
        }
        cout<<ans<<endl;

	return 0;
}
