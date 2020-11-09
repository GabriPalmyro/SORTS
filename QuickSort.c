#include <stdio.h>
#include <stdlib.h>

int quebra(int *vet, int ini, int fim){
    int i = ini, f = fim, menorT, maiorT, temp;
    int pivo = fim / 2;
    menorT = 0;
    maiorT = 0;
    while(i < f){

            if(vet[i] > vet[pivo]){
                maiorT = vet[i];
            } else {
                i++;
            }
            if(vet[f] < vet[pivo]){
                menorT = vet[f];
            } else {
                f--;
            }
        if(maiorT != 0 && menorT != 0){
            temp = vet[i];
            vet[i] = vet[f];
            vet[f] = temp;
            menorT = 0;
            maiorT = 0;
        }
    }
    return pivo;
}

void quicksort(int *vet, int ini, int fim){
    int i = ini, f = fim, q;
    while(i < f){
        q = quebra(vet, i, f);
        quicksort(vet, i, q - 1);
        quicksort(vet, q + 1, fim);

    }
}

int main()
{
    int vet[10] = {2, 12, 13, 3, 23, 26, 9, 6, 8, 1};
    quicksort(vet, 0, 9);


    int i;
    for(i = 0; i < 10; i++){
        printf("%d", vet[i]);
    }
    return 0;
}
