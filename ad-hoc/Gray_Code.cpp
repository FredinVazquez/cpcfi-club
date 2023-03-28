#include<bits/stdc++.h>
using namespace std;

void backtrack(int n,string &s)
    {
        if(s.size() == n){
            cout<<s<<endl;
            return; 
        }
        else{
            s += '0';
            backtrack(n,s);
            s.pop_back();
            
            s += '1';
            backtrack(n,s);
            s.pop_back();
        }
        return;
    }

int main()
    {
        int n; cin>>n;
        string s = "";
        backtrack(n,s);

        return 0;
    }