#include<bits/stdc++.h>
using namespace std;

int bandera = 0;

void definir_ceros(int &n, int &m, int &renglon_actual, int &columna_actual, vector<vector<int>> &A)
    {
        for(int i=0;i<m;i++)
            {
                A[renglon_actual][i] = 0;
            }
        
        for(int i=0;i<n;i++)
            {
                A[i][columna_actual] = 0;
            }
    }
    
    

bool checar(vector<vector<int>> &A, int &valor,int &n,int &m,int &renglon_actual, int &columna_actual)
    {
        int or_operation = 0;
        
        for(int i=0;i<m;i++)
            {
                or_operation = (or_operation || A[renglon_actual][i]);
            }
            
        for(int i=0;i<n;i++)
            {
                 or_operation = (or_operation || A[i][columna_actual]);
            }
        
        return or_operation == valor;
    }
    
    

int main()
    {
            int n,m;

            cin>>n>>m;
            vector<vector<int>> B(n+1,vector<int>(m+1));
            vector<vector<int>> A(n+1,vector<int>(m+1,1));            
            
            for(int i=0;i<n;i++)
                {
                    int dato;
                    for(int j=0;j<m;j++)
                        {
                            cin>>dato;
                            B[i][j]=dato;
                            
                            if(dato==0)
                                {
                                    definir_ceros(n,m,i,j,A);
                                }
                        }
                }
            
            
            for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                        {
                            if(checar(A,B[i][j],n,m,i,j)==false)
                                {
                                    cout<<"NO";
                                    return 0;
                                }
                        }
                }
            
            
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                        cout<<A[i][j]<<" ";
                    cout<<endl;
                        
                }
        return 0;
    }
    
