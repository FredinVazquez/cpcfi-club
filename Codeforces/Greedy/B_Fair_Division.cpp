#include<bits/stdc++.h>
using namespace std;


int main()
    {
        int t; cin>>t;
        
        while(t--)
            {
                int n; cin>>n;
                int tmp;
                int sum1 = 0;
                int sum2 = 0;
                map<int,int> mapa;
                
                for(int i=0;i<n;i++){
                    cin>>tmp;
                    mapa[tmp]++;
                    sum1 += tmp;
                //cout<<tmp<<endl;
                    
                }
                
                sum1/=2;
                sum2 = sum1;
                
                //cout<<sum1<<endl;
                
                while((sum1-2 >= 0) && mapa[2]>0){
                    sum1-=2;
                    //cout<<sum1<<endl;
                    mapa[2]--;
                }
                
                 while(sum1-1 >= 0 && mapa[1]>0){
                    sum1-=1;
                    mapa[1]--; 
                }
                
                
                
                if(sum2 == ((mapa[1] * 1) + (mapa[2] * 2))){
                    if(sum1 == 0) cout<<"YES"<<endl;
                    else          cout<<"NO"<<endl;
                }
                else{
                    //cout<<mapa[1]<<" "<<mapa[2]<<endl;
                    cout<<"NO"<<endl;
                }          
                
            }
        return 0;
    }