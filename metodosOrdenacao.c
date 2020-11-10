#include <stdio.h>
#include <stdlib.h>

void selection(int *vet, int tam){
int i, j, min = 0, temp;

for(i = 0; i < tam-1; i++){

    min = i;

    for(j = i+1; j < tam; j++){
        if(vet[j] < vet[min])
            min = j; 
    }

    if(vet[i] != vet[min]){
        temp = vet[i];
        vet[i] = vet[min];
        vet[min] = temp;
        }
    }
}


void insertion(int *vet, int tam){
int i, j, min = 0, temp;

for(i =1; i < tam; i++){
    int j = i;

    while(j > 0 && vet[j-1] > vet[j]){
        temp = vet[j-1];
        vet[j-1] = vet[j];
        vet[j] = temp;

        j--;
    }
}
}

void bubble(int *vet, int tam){
    short int swapped = 0;
    int i = 0, j, temp;

    do{
        swapped = 0;
        for(j = tam-1; j > i; j--){
            if(vet[j-1] > vet[j]){
                temp = vet[j-1];
                vet[j-1] = vet[j];
                vet[j] = temp;
                swapped = 1;
            }
        }
        i++;
    }while(swapped = 1 && i < tam);

    }

void merge(int *vet, int min, int meio, int max){
    int i = min, j = meio + 1, k;
    int *aux;
    aux = malloc(sizeof(int) * (max+1));

    for(k = min; k <= max; k++)
        aux[k] = vet[k];
    
    for(k = min; k <= max; k++){
        if(i > meio)
            vet[k] = aux[j++];
        else if(j > max)
            vet[k] = aux[i++];
            else if(aux[j] < aux[i])
                vet[k] = aux[j++];
                else
                    vet[k] = aux[i++];

    }
    free(aux);
    return;
}

void mergesort(int *vet, int min, int max){
    int meio;

    if(max <= min)
        return;
    
    meio = (min + max) / 2;

    mergesort(vet, min, meio);
    mergesort(vet, meio+1, max);
    merge(vet, min, meio, max);
}

int escolhePivo(int *vet, int min, int max){
    int i = min, j = max + 1, temp;

    while(1){
        while(vet[++i] < vet[min]){
            if( i == max)
            break;
        }
        
        while(vet[min] < vet[--j]){
            if(j == min)
            break;
        }

        if(i >= j)
            break;

        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
    temp = vet[min];
    vet[min] = vet[j];
    vet[j] = temp;

    return j;
}

void quicksort(int *vet, int min, int max){
if(max <= min)
    return;

int pivo = escolhePivo(vet, min, max);
quicksort(vet, min, pivo-1);
quicksort(vet, pivo+1, max);
}

int main(void){

int tam, i;

printf("---METODO DE ORDENACAO---\n\n");
printf("Qual tamanho do vetor que deseja ordenar?\nTamanho = ");
scanf("%d", &tam);

int vet[tam];

printf("\nInsira o vetor a ser ordenado:\n");
for(i = 0; i < tam; i++)
scanf("%d", &vet[i]);

//funcao de ordenacao

printf("\nVetor ordenado:\n");
for(i = 0; i < tam; i++)
printf("%d ", vet[i]);

printf("\n\n");

system("pause");
return 0;
}