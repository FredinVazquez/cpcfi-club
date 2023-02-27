#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<string> &v, string &s,int index,vector<string> &solution)
    {
        // Caso base
        if(solution.size() == s.size()){
            for(auto it: solution)    cout<<it;
            cout<<endl;
            return;  
        } 
        
        if(s[index] == '#')
            {
                for(int i=0;i<v.size();i++)
                    {
                        solution.push_back(v[i]);
                        backtrack(v,s,index+1,solution);
                        solution.pop_back();
                    }
            }
        else
            {
                if(s[index] == '0')
                    {
                        for(int d=0;d<=9;d++)
                            {
                                solution.push_back(to_string(d));
                                backtrack(v,s,index+1,solution);
                                solution.pop_back();
                            }
                    }
            }
    }


int main() {
    
    int t;
    
    while(cin>>t)
        {
            vector<string> v(t);
            
            
            for(int i=0;i<t;i++)    cin>>v[i];
            
            int n; cin>>n;
            string s;
            cout<<"--"<<endl;
            for(int i=0;i<n;i++)
                {
                    cin>>s; 
                    vector<string> sol;
                    
                    backtrack(v,s,0,sol);
                }
            
        }
    
	return 0;
}

