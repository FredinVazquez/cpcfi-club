/*DSU SOLUTION*/

/*
    El problema consiste en tal cual observar que se puede encontrar conjuntos o tener 
    conjuntos tal que esos conjuntos contengan los elementos que pueden hacer swap.
    
    Por ende se estarían creando conjuntos que pueden hacerse swap entre ellos. Así que solo
    basta con checar que cada elmento del segundo arreglo (el modificado) se encuentra en
    esos conjuntos en donde está el caracter del primer arreglo. En caso de ser sí entonces
    se puede entender que es posible hacer ese cambio.
    En caso que no esté se entiende que no es posible hacer ese cambio.
    
    Considerar que se tiene que cuidar tres cosas:
        1. Es posible tener repeticiones de un mismo valor por lo cual se puede confundir
        que un elemento pertenece al conjunto de intercambiables cuando no es así, y esto
        sucede simplemente con el hecho que se trata del mismo conjunto, la forma de distinguir
        será usando la posición y la ocurrencias de ese elemento
        
        2. Se debe de entender que cada objeto que es posible de intercambiar debe ser usado,
        así que al tener las ocurrencias de cada elemento se deberá de restar su ocurrencia
        en caso de que fue usado, y eso es que simplemente se encuentre en ese conjunto de 
        intercambiables.
        
        3. También aquellos elementos que pueden ser intercambiados PERO NO LO HICIERON, se 
        estará entendiendo por aquellos que conservan su posición original. Para ello
        también se tendrá que resta de esa cantidad de ocurrencias debido a que es posible
        de intercambiar pero no es usado, así que simplemente los restamos.
*/

#include<bits/stdc++.h>
#include <algorithm>    // std::count
using namespace std;

// UNION - FIND
int numSets = 0;
 
int find_set(int x,vector<int> &linked,vector<int> &size)
    {
        while(x != linked[x])   x = linked[x];
        return x;
    }
 
bool isSameSet(int u,int v,vector<int> &linked,vector<int> &size)
    {
        if(find_set(u,linked,size)==find_set(v,linked,size))
            return true;
        else
            return false;
    }
 
void union_set(int u, int v,vector<int> &linked,vector<int> &size)
    {
        // Counting sets
        if(!isSameSet(u,v,linked,size))
            {
                numSets--;
        
        // Find their representatives
        int a = find_set(u,linked,size);
        int b = find_set(v,linked,size);
        
        // who is greater?
        if(size[a]<size[b])
            {
                swap(a,b);      // Standar, always chained with a
            }
        
        // In other case
        linked[b] = a;
        
        // Increase the size
        size[a] += size[b];
            }
    }
 
 
int numDisjointSets()
    {
        return numSets;
    }


int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t; cin>>t;
        
        while(t--)
            {
                int n,k; cin>>n>>k;
                numSets = n;
                string s; cin>>s;
                string s2; cin>>s2;
                string check = s;
                map<char,int> mapa; // ocurrences
                
                vector<int> linked(122+1000);
                vector<int> size(122+1000,1);
                
                
                
                for(int i=97;i<=122;i++){
                    linked[i] =i;
                }   
                
                int u,v;
                for(int i=0;i<n;i++)
                    {
                        if(i+3 < n){
                            u = (int)s[i];
                            v = (int)s[i+3];
                            //cout<<(char)u<<" "<<(char)v<<endl;
                            union_set(u,v,linked,size);
                            
                            // Add in the structure
                            if(check[i] != '1')
                                {
                                    mapa[check[i]]++;
                                    check[i] = '1';
                                }
                            
                            if(check[i+3] != '1')
                                {
                                    mapa[check[i+3]]++;
                                    check[i+3] = '1';
                                }
                        }
                        
                        
                        if(i+4 < n){
                            u = (int)s[i];
                            v = (int)s[i+4];
                            //cout<<(char)u<<" "<<(char)v<<endl;
                            union_set(u,v,linked,size);
                            
                            if(check[i] != '1')
                                {
                                    mapa[check[i]]++;
                                    check[i] = '1';
                                }
                            
                            if(check[i+4] != '1')
                                {
                                    mapa[check[i+4]]++;
                                    check[i+4] = '1';
                                }
                        }
                        
                    }
                
                
                bool flag = true;
                
                for(int i=0;i<n;i++)
                    {
                        if(s[i] == s2[i])
                            {
                                if(check[i] == '1')
                                    {
                                        // Quiere decir que ese sí se puede cambiar
                                        // entonces se quita
                                        mapa[s[i]]--;
                                    }
                                continue;
                            }
                        
                        
                        u = (int)s[i];
                        v = (int)s2[i];
                        //cout<<(char)u<<" "<<(char)v<<endl;
                        if(isSameSet(u,v,linked,size) == false){
                            
                            
                            cout<<"NO"<<endl; 
                            flag = false;
                            break;
                        }
                        else
                            {
                                if(mapa[s2[i]] > 0) mapa[s2[i]]--;
                                else
                                    {
                                        cout<<"NO"<<endl; 
                                        flag = false;
                                        break;
                                    }
                            }
                    }
                //for(auto it: mapa)  cout<<it.second<<" ";
                //cout<<endl;
                if(flag)
                    {
                        // Si se usó todo es yes, caso contrario no
                        for(auto it: mapa)
                            {
                                if(it.second != 0)
                                    {
                                        cout<<"NO"<<endl; 
                                        flag = false;
                                        break;
                                    }
                            }
                        
                        if(flag)
                        cout<<"YES"<<endl;
                    }
            }
        return 0;
    }