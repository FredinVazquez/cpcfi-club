
#include<bits/stdc++.h>
using namespace std;

int main()
    {
        string s; cin>>s;
        map<char,int> mapa;
        for(auto it : s)    mapa[it]++;

        string ans = s;
        int pointer_1=0,pointer_2=s.size()-1;
        int unique = 0;
        char letter;
        
        for(auto it : mapa){
            if(it.second % 2 != 0){
                if(unique == 1){
                    cout<<"NO SOLUTION";
                    return 0;
                }
                else{
                    unique = 1;
                    letter = it.first;
                    continue;
                }
            }

            for(int i=0; i<(it.second/2);i++){
                ans[pointer_1] = it.first;
                pointer_1++;
            }

            for(int i=0; i<(it.second/2);i++){
                ans[pointer_2] = it.first;
                pointer_2--;
            }
        }
        
        for(pointer_1;pointer_1<=pointer_2;pointer_1++) ans[pointer_1] = letter;
        
        cout<<ans;

        return 0;
    }