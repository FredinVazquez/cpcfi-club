#include<bits/stdc++.h>
using namespace std;

/*
                    Sol hay necesidad de checar si es posible, lo de abajo nace a partir
                    de que la intersección entre una parabola y linea se obtieen por medio
                    de la igualdad de ambas expresiones (parabola y linea) y encontrando sus
                    roots, y si al sustituir en ambas expresiones se obtiene el mismo resultado
                    'y' entonces hay intersección. Por ende, lo único importante es ver 
                    que siempre que se cumpla lo de abajo (siempre que se pueda resolver 
                    el sistema de ecuaciones cuadrático o siempre que existan roots en la e.c
                    igualada de ambas expresiones) 
                    quiere decir que se tiene intersecciones, en caso que no se cumpla no existen.
*/

void solve(vector<long long> &lines,long long a,long long b,long long c )
    {
        // Real zeros?
        for(auto it: lines)
            {
                if( (b-it)*(b-it) < (4*a*c) )
                    {
                        cout<<"YES"<<endl;
                        cout<<it<<endl;
                        return;
                    }
            }
        cout<<"NO"<<endl;
        return;
    }

/*
    La solución de arriba da TLE, por ende otra solución es simplemente encontrar un número que sea inmediatamente menor,
    igual o mayor al valor buscado, para esto podemos usar lower_bound el cual nos da el inmediato mayor o igual al valor
    buscado. Lo buscamos y checamos si corresponde y cumple con esa condición, en caso que no existe o que no cumpla
    entonces no hay linea que cumpla
*/

int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t; cin>>t;
        
        for(int i=0;i<t;i++)
            {
                int n,m; cin>>n>>m;
                vector<long long> lines(n);
                for(int a=0;a<n;a++)
                    {
                        cin>>lines[a];
                    }
                
                sort(lines.begin(),lines.end());
                
                
                long long n1,n2,n3;
                for(int a=0;a<m;a++)
                    {
                        cin>>n1>>n2>>n3;
                        
                        //solve(lines,n1,n2,n3); Time limit
                        
                        auto it = lower_bound(lines.begin(),lines.end(),n2);
                        //cout<<"buscado: "<<n2<<" "<<*it<<endl;
                        
                        if(it!=(lines.begin()-1) && it != lines.end() && ((n2-(*it))*(n2-(*it)) < (4*n1*n3)))
                            {
                                cout<<"YES"<<endl;
                                cout<<*it<<endl;
                            }
                        else
                            {
                                it--;
                                if(it!=(lines.begin()-1) && it != lines.end() && ((n2-(*it))*(n2-(*it)) < (4*n1*n3)))
                                    {
                                        cout<<"YES"<<endl;
                                        cout<<*it<<endl;
                                    }
                                else    cout<<"NO"<<endl;
                            }
                        
                    }
                cout<<endl;
            }
        
        return 0;
    }