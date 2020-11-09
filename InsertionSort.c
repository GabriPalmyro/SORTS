#include <stdio.h>
#include <stdlib.h>

void empurraVetor(int i, int *vet, int cont);

void insertionSort(int num, int *vet);

int main()
{
    int num, i;
    printf("INSERTION SORT\n Escolha o quanto de elementos deseja ordenar:\n");
    scanf("%d", &num);
    int vet[num];
    printf("Digite %d numeros para ordenar\n", num);
    for(i = 0; i < num; i++){
        scanf("%d", &vet[i]);
    }
    //ordenação
    insertionSort(num, vet);

    printf("Vetor ordenado: ");
    for(i = 0; i<num; i++){
        printf("%d", vet[i]);
    }

    return 0;
}

void empurraVetor(int i, int *vet, int cont){
    int k;
    for(k = 0; k >= cont; k++){
        vet[i-k+1] = vet[i-k];
    }
}

void insertionSort(int n, int *vet){
    int i, j, k, temp, cont;
    for(i = 1; i < n; i++){
        cont = 0;
        for(j = i-1; j>= 0; i--){
            if(vet[i] < vet[j]){
                cont++;
            } else if(vet[i] > vet[j]){
                if(cont != 0){
                    temp = vet[i];
                    empurraVetor(i, vet, cont);
                    vet[i-cont] = temp;
                    break;
                } else {
                    break;
                }
            }
        }
    puts("\n");
    for(k = 0; k<n; k++){
        printf("%d", vet[k]);
        }
    }
}



