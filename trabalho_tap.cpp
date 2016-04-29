
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> // calcular o Time

void constroiHeap( int *p_vetor, int tamanho, int indice_raiz )
{
	int ramal, valor;
	valor = p_vetor[indice_raiz];
	
	while(indice_raiz <= tamanho/2){
	ramal = 2 * indice_raiz;
	
	if(ramal < tamanho && p_vetor[ramal] < p_vetor[ramal + 1])
	ramal++;
	
	if(valor >= p_vetor[ramal])
	break;
	
	p_vetor[indice_raiz] = p_vetor[ramal];
	indice_raiz = ramal;
	}
	p_vetor[indice_raiz] = valor;
}

void shellSort(int *p_vetor, int tamanho)
{
   int i = (tamanho - 1) / 2;
   int chave, k, aux;
 
   while(i != 0)
   {
      do
      {
         chave = 1;
         for(k = 0; k < 100 - i; ++k)
         {
            if(p_vetor[k] > p_vetor[k + i])
            {
               aux = p_vetor[k];
               p_vetor[k] = p_vetor[k + i];
               p_vetor[k + i] = aux;
               chave = 0;
            }
         }
      }while(chave == 0);
      i = i / 2;
   }
}

void HeapSort( int *p_vetor, int tamanho )
{
	int indice, troca;
	for( indice = tamanho/2; indice >= 0; indice-- )
	constroiHeap( p_vetor, tamanho, indice );
	
	while( tamanho > 0 )
	{
		troca = p_vetor[ 0 ];
		p_vetor[ 0 ] = p_vetor[ tamanho ];
		p_vetor[ tamanho ] = troca;
		constroiHeap( p_vetor, --tamanho, 0 );
	}
}

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

int main()
{
	int escolha;
	int vetor [300]; // cria um vetor com 300 de armazenamento
	int i, j, aux, min;
	double tempo;
	clock_t Ticks [2];
	
	printf("|************** Metodos de Ordenacao: ******************|\n");
    printf("\n");
    printf("<1> - Insertion Sort\n");
    printf("<2> - Selection Sort\n");
    printf("<3> - Quick Sort\n");
    printf("<4> - Heap Sort\n");
    printf("<5> - Shell Sort\n");
    printf("<6> - Sair\n");
    printf("\n");
    printf("Opcao: ");
    scanf ("%d", &escolha);
    printf("\n"); // menu do usuario

	switch (escolha)
	{
		case 1:
			system ("cls"); // limpa o código do console

		    Ticks [0] = clock(); // tempo de inicio
			
			for (i=1; i < 300; i++) // gera números aleatórios até 300
			{
				vetor[i] = rand();
			}
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) // mostra na tela os numeros aleatorios gerados
			{
				printf ("%d ** ", vetor[i]);
			}
			for (i=1; i < 300; i++) // insertion sort
			{
				j = i;
				while ((j > 0) && (vetor[j-1] > vetor[j]))
				{
					aux = vetor[j-1]; 
					vetor[j-1] = vetor[j];
					vetor[j] = aux;
					j--;
				}
			}
			printf ("\n\n");
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) // numeros já com o insert sort 
			{
				printf ("%d ** ", vetor[i]);
			}
			
			Ticks[1] = clock(); // no [1] vai fica salvo o tempo final
			tempo = (Ticks[1] - Ticks[0] *1000.0 / CLOCKS_PER_SEC); // *1000.0 pra ser em milissegundos 
			printf("\n\n");
			printf("Time: %g ms", tempo);
			
			break;
		case 2:
			system ("cls");

		    Ticks [0] = clock(); // tempo inicial
			
			for (i=1; i < 300; i++) // // gera números aleatórios até 300
			{
				vetor[i] = rand();
			}
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) // mostra na tela os numeros aleatorios gerados
			{
				printf ("%d ** ", vetor[i]);
			}
			
			for (i - 0; i < 300 - 1; i++)
			{
				min = i;
				for (j = i+1; j < 300; j++)
				{
					if (vetor[j] < vetor[min])
					{
						min = j;
					}
				}
				aux = vetor[i];
				vetor[i] = vetor[min];
				vetor[min] = aux;
			}
			printf ("\n\n");
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) 
			{
				printf ("%d ** ", vetor[i]);
			}
			
			Ticks[1] = clock(); 
			tempo = (Ticks[1] - Ticks[0] *1000.0 / CLOCKS_PER_SEC);  
			printf("\n\n");
			printf("Time: %g ms", tempo);
			break;
		case 3:
			system ("cls");	
			
			Ticks [0] = clock(); 
			
			for (i=1; i < 300; i++) 
			{
				vetor[i] = rand();
			}
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) 
			{
				printf ("%d ** ", vetor[i]);
			}
			
			quick_sort(vetor, 0, 300 - 1);
			
			printf ("\n\n");
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) 
			{
				printf ("%d ** ", vetor[i]);
			}
			
			Ticks[1] = clock(); 
			tempo = (Ticks[1] - Ticks[0] * 1000.0 / CLOCKS_PER_SEC);  
			printf("\n\n");
			printf("Time: %g ms", tempo);
			
			break;
		case 4:
			system ("cls");
			
			Ticks [0] = clock(); 
			
			for (i=1; i < 300; i++) 
			{
				vetor[i] = rand();
			}
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) 
			{
				printf ("%d ** ", vetor[i]);
			}
			
			HeapSort(vetor, 300 - 1);
			
			printf ("\n\n");
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) 
			{
				printf ("%d ** ", vetor[i]);
			}
			Ticks[1] = clock(); 
			tempo = (Ticks[1] - Ticks[0] *1000.0 / CLOCKS_PER_SEC);  
			printf("\n\n");
			printf("Time: %g ms", tempo);
			break;
		case 5:
				system ("cls"); // limpa o código 
			
			Ticks [0] = clock(); 
			
			for (i=1; i < 300; i++) 
			{
				vetor[i] = rand();
			}
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) 
			{
				printf ("%d ** ", vetor[i]);
			}
			
			shellSort(vetor, 300 - 1);
			
			printf ("\n\n");
			printf ("******** Vetor ordenado: **********");
			printf ("\n\n");
			for (i=1; i < 300; i++) // esse for pega os números já ordenados pela troca de insertion sort e joga na tela pro usuário ver
			{
				printf ("%d ** ", vetor[i]);
			}
			Ticks[1] = clock(); // no [1] vai fica salvo o tempo final
			tempo = (Ticks[1] - Ticks[0] * 1000.0 / CLOCKS_PER_SEC); // *1000.0 pra ser em milissegundos 
			printf("\n\n");
			printf("Time: %g ms", tempo);
			
			break;
		case 6:
			exit(0);
			break;
		default:
			system ("cls");
			printf ("Nao existe essa opcao. Tente novamente");
			break;
	}
}

