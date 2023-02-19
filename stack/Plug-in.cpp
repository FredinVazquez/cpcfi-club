#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s; cin>>s;
    stack<int> pila;
    
    for(int i=0;i<s.size();i++)
        {
            if(!pila.empty() && (pila.top() == s[i]) )
                {
                    // Se elimina
                    pila.pop();
                }
            else
                {
                    // Se agrega
                    pila.push(s[i]);
                }
        }
    
    vector<char> ans;
    while (!pila.empty())
        {
            ans.push_back(pila.top());  pila.pop();
        }
    
    reverse(ans.begin(), ans.end());
    
    // Ans:
    for(int i=0;i<ans.size();i++)   cout<<ans[i];
    
	return 0;
}
