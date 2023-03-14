#include<bits/stdc++.h>
using namespace std;

vector<long long> memo(1e5,-1);

long long fibonacci(int n)
    {
        if(n==0)    return 0;
        if(n==1)    return 1;
        if(memo[n]!=-1)     return memo[n];
        else                return memo[n] = fibonacci(n-1)+fibonacci(n-2);
        //return fibonacci(n-1)+fibonacci(n-2);
    }

int main()
    {
        int n; cin>>n;
        cout<<fibonacci(n);
        
        return 0;
    }
