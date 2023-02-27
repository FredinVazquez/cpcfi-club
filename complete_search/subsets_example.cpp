#include <bits/stdc++.h>
using namespace std;

void backtrack(int t,int number,vector<int> &solution)
    {
        // Caso base
        if(number == t)
            {
                for(auto it: solution)
                    cout<<it;
                cout<<endl;
                return;
            }
        
        // Tomar número - izquierda
        solution.push_back(number+1);
        backtrack(t,number+1,solution);
        
        // No tomarlo - derecha
        solution.pop_back();
        backtrack(t,number+1,solution);
    }

int main() {
    
    int t;  cin>>t;
    vector<int> solution;
    //Subsets:
    backtrack(t,0,solution);
    
	return 0;
}

