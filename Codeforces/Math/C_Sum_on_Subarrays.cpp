#include<bits/stdc++.h>
using namespace std;

/*
    Simplemente se observan los casos
    k == 0 todo es negativo
    
    k == n entonces se puede agregar el último numero igual a k o n, esto es debido
    a que poner todo en -1 hará que la suma de estos sea siempre menor a 'n' debido a que
    se tiene -1 desde el índice 0 a n-2. La cantidad de subarrays positivos será simplemente
    k
    
    k<n 
    aquí lo que se deberá de observar es solo que se deberá de cuidar dde tener sumas con 
    ceros, esto es debido a que si se aplica la mismos técnica que el anterior caso se tendrá
    sumas donde de el resultado 0. Entonces lo que se hace es colocar ese número k en la
    posición tal cual de k, por ende la suma de -1 de su lado izquierdo será siempre
    menor a k. Pero la posición sigueinte no puede ser .-1 ya que esto haría de nuevo una 
    suma de 0, por ende se debe de poner un inmediato mayor a k, el cual es simplemente 2*k
    o incluso k+1
    
    En caso de no cumplir con ningún caso entonces se tendrá que restar n-1 y k-1, esto se 
    deduce viendo la formula de gauss en donde tenemos que la formula de gauss para n+1
    es la misma que aplicando gauss en n y sumando n. Por ende solo queda ver que colocando
    un número muy grande en esa posición se estará generando esas 'n' subarrays, o sea 
    el 'n' que se le estaría sumando a la formula de gauss para que sea igual a n-1.
*/

void solve(int n, int k,vector<int> &v)
    {
        if(k == 0)  return;
        if(k==n)
            {
                v[n-1] = k;
                return;
            }
        if(k<n)
            {
                
                v[k-1] = k;
                v[k] = -(2*k);
                return;
            }
        else
            {
                solve(n-1,k-n,v);
                v[n-1] = 1000;  // Esto genera las n subarrays faltantes, según gauss
            }
        return;
    }

int main()
    {
        int t; cin>>t;
        
        for(int i=0;i<t;i++)
            {
                int n,k; cin>>n>>k;
                vector<int> ans(n,-1);
                solve(n,k,ans);
                
                for(auto it: ans) cout<<it<<" ";
                cout<<endl;
            }
        
        return 0;
    }