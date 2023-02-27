#include <bits/stdc++.h>
using namespace std;

// Se debe de hacer un despeje de la última ecuación proponiendo x=1 y y=2 C =10000

void solve(int A,int B,int C)
    {
        for(int x=-100;x<=100;x++)
            {
                for(int y=-100;y<=100;y++)
                    {
                        for(int z=-100;z<=100;z++)
                            {
                                if(x!=y && y!=z && x!=z)
                                    {
                                        if((x+y+z)==A)
                                            {
                                                if((x*y*z)==B)
                                                    {
                                                        if(((x*x)+(y*y)+(z*z))==C)
                                                            {
                                                                cout<<x<<" "<<y<<" "<<z<<endl;
                                                                return;
                                                            }
                                                    }
                                                
                                            }
                                    }
                                    
                                    
                            }
                    }
            }
        cout<<"No solution."<<endl;
        return;
    }


int main() {
    
    int t; cin>>t;
    int A,B,C;
    
    for(int i=0;i<t;i++)
        {
            cin>>A>>B>>C;
            solve(A,B,C);
        }
    
	return 0;
}

