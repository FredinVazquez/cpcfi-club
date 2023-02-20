#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int n; cin>>n;
    map<string,int> mapa;
    vector<pair<string,int>> v(n);
    map<string,int> players;
    string s;
    int score;
    
    // winner;
    string winner;
    int max_=-1e9;
    
    for(int i=0;i<n;i++)
        {
            cin>>s>>score;
            v[i] = make_pair(s,score);
            mapa[s]+=score;
            
        }
	
	for(auto it: mapa)
	    {
	        max_ = max(max_,it.second);
	    }
	//cout<<"winner score: "<<max_<<endl;
	// Ahora buscar 
	
	for(auto it: v)
	    {
	        players[it.first] += it.second;
	        
	        if(players[it.first] >= max_ && mapa[it.first]==max_)
	            {
	                cout<<it.first<<endl;
	                break;
	            }
	                
	    }
	
	return 0;
}
