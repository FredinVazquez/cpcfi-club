#include<bits/stdc++.h>
using namespace std;

void fibonacci(int n)
    {
        vector<long long> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        if(n>=2)
            {
                for(int i=2;i<=n;i++)
                    {
                        dp[i] = dp[i-1]+dp[i-2];
                    }
            }
        cout<<dp[n];
    }

int main()
    {
        int n; cin>>n; fibonacci(n);
        return 0;
    }
