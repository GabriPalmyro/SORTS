#include <stdio.h>

void selectionSort(int tam, int *vet){
	int i, j, *menor, temp, valid = 0;
	for(i = 0; i < tam; i++){
		temp = vet[i];
		menor = &vet[i];
		for(j = i+1; j < tam; j++){
			if(vet[j] < *menor){
				menor = &vet[j];
				valid = 1;
			}
		}
		if(valid){
			vet[i] = *menor;
			*menor = temp;
		}
	}
}

void imprimir(int *vet, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", vet[i]);
	}
}

int main(){
	int tam, i;
	scanf("%d", &tam);
	int vet[tam];
	for(i = 0; i < tam; i++){
		scanf("%d", &vet[i]);
	}
	
	selectionSort(tam, vet);
	
	imprimir(vet, tam);
	
	
	return 0;
}
