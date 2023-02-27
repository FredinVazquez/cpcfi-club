#include <iostream>
#include <bits/stdc++.h>
 
 
using namespace std;
 
template<typename ForwardIterator, typename T>
  ForwardIterator first_less_than (ForwardIterator first, ForwardIterator last, T value)
    {
      auto it = std::lower_bound(first, last, value);
      return (it == first ? last : --it);  
    }
  // Retonar un iterador, en caso de no encontrar un n�mero para la soluci�n retorna el iterador end.

 
int resultado=1;
int MOD = 1e9+7;
 
 

		//Algunos macros para ayudar
#define endl		'\n'

	//Definiciones de ciclos for: crementar, incrementar
#define FO(i, b)	for(int i = (a); i < (b); i++)
#define FOR(i, a, b)	for(int i = (a); i < (b); i++)
#define rFOR(i, a, b)	for(int i = (a); i > (b); i--) //a es nuestro valor de inicio

#define pint(x)			printf("%d\n",x);
#define pll(x)			printf("%lld\n",x); //imprimir un long long
#define si(x)			scanf("%d",&x);	    //Escaneo de un entero
#define sl(x)			scanf("%lld",&x);
#define TR(v, arr)      for(auto& (v) : (arr)) //Es como un for each


				//TYPEDEF YA NO ES MACROS
typedef vector<int> vi;
typedef vector<long long> vll;


bool numeroUnico(int numero1, int numero2)
    {
        int n,d;
        int tmp = numero1;
        int digitos;
        // Una cosa que puede suceder es que el denominador tenga solo 4 d�gitos, lo que provoca 
		// es que ya en la primera posici�n se tenga el n�mero 0, debido a que se va de 0 a 9.
		digitos = (numero1 <10000);     // Si esto sucede, probablemente se tiene un n�mero: 0xxxx.
		
        while(tmp)
		    {
		        d = tmp % 10;
		        if( (digitos & (1<<d)) != 0){
		            return false;
		        }   
		        digitos |= (1<<d);
		        tmp /= 10;
		    }
		
		tmp = numero2;
		while(tmp)
		    {
		        d = tmp % 10;
		        if( (digitos & (1<<d)) != 0){
		            return false;
		        }   
		        digitos |= (1<<d);
		        tmp /= 10;
		    }
		   
		if(digitos==((1<<10) -1))
		    return true;
		    
		return false;
    }

int main()
	{
	    int numero;    scanf("%d",&numero);
		while(numero!=0)
		    {
		        // se procede a realizar la busqueda completa
		        /*
		            El chiste dentro de estos problemas de b�squeda completa es buscar el campo de busqueda
		            en este caso el rango donde se va a buscar ser� de 01234 a 98765 ya que se puede ir de 
		            0 a 9, se debe de cumplir lo siguiente:
		                abcdf/fghij = N
		            Donde cada letra representa un d�gito diferente, o sea que ambos n�meros que representan 
		            a la divisi�n deben ser n�meros �nicos, cada d�gito debe ser diferente.
		            Debe de ver algo curioso, sabemos N pero desconocemos los n�meros, entonces es posible 
		            hacer un despeje:
		                abcdf = N * fghij;      a = N*b;
		            Entonces, se puede hacer iterar en fghij sobre el rango 01234 - 98765 e ir multiplicando
		            cada n�mero por N, esto es super f�cil solo que la dificultad recae en que los n�meros
		            deben ser �nicos.
		            Nota: la longitud debe ser �nicamente de 5 d�gitos.
		        */
		        int a,b;
		        int sol=0;
		        for(b=1234;b<98765;b++)
		            {
		                a = b*numero;   // Al parecer, aqu� se hace que sea a lo mucho 5 d�gitos por n�mero.
		                
		                
		                //Ahora checar si los d�gitos de cada n�mero son �nicos.
                        if(numeroUnico(b,a))
                            {
                                printf("%0.5d / %0.5d = %d\n", a, b, numero);
                                sol++;
                            }
                        
		            }
		        if(sol==0)  printf("There are no solutions for %d.\n",numero);  
		        scanf("%d",&numero);
		        if(numero!=0)   printf("\n");
		        
		    }
		
		return 0;
	}
	
