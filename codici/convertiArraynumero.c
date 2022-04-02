#include<stdio.h>
#include<stdlib.h>
int converti(int interi[],int l){
	int numero;
	if (l==1)
		numero=interi[0];//*se la lunghezza di array è 1 allora numero corrispode al valore di array in [0]
		else
			numero=interi[l-1]+converti(interi,l-1)*10;
			return numero;
}
int main(){
	printf("ciao sono un programma che converte ricorsivamente un array in un numero\n");
	int lunghezza;
	printf("quanti interi vuoi nel tuo array\n");
	scanf("%d",&lunghezza);
	int interi[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("inserisci un numero\t");
		scanf("%d",&interi[i]);
	}
	printf("il numero associato al tuo array e': \t %d",converti(interi,lunghezza));
}