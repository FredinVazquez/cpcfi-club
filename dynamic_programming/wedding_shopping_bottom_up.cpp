#include<bits/stdc++.h>
using namespace std;


void solve(int k, int c,vector<vector<int>> &prices)
	{	
		vector<vector<int>> dp(2, vector<int> (k+1,0));
        
        int rowA = 1; // previous
        int rowB = 0; // actual
        
		// Base case
		
				for(int i=1;i<=prices[0][0];i++)
					{
						if(k-prices[0][i]>=0){
						    dp[0][k-prices[0][i]] = 1;
						}
						
					}	
    
		for(int row=1;row<c;row++)
			{
			    swap(rowA,rowB);
				for(int price_rest=0;price_rest<=k;price_rest++)
					{
						// Check for each price
						for(int i=1;i<=prices[row][0];i++)
							{
							    if(dp[rowA][price_rest]==1)
							    {
							        if(price_rest-prices[row][i]>=0)
    							        {
    							            dp[rowB][price_rest-prices[row][i]] = 1;
    							        }    
							    }
							}
						dp[rowA][price_rest] = 0;
						
					}	
			}

		int ans;
		for(ans=0;ans<=k && dp[rowB][ans]==0;ans++);
		if(k-ans==-1){
		    cout<<"no solution"<<endl; return;
		}
		cout<<k-ans<<endl;
		return;
	}


int main()
	{
		
		int t,k,c,tmp; cin>>t;
		
		while(t--)
			{
				cin>>k>>c;
				vector<vector<int>> prices(c);
				for(int i=0;i<c;i++)
					{
						cin>>tmp;
						prices[i].push_back(tmp);
						for(int j=0;j<prices[i][0];j++)
							{
								cin>>tmp;
								prices[i].push_back(tmp);
							}
					}
				solve(k,c,prices);
			}
		return 0;
	}
