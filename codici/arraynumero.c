#include <stdio.h>
#include <stdlib.h>
int converti(int array[],int lungh);
int main(){
	printf("ciao cono un programma che converte un array in numero\n");
	int l;
	printf("inserisci lunghezza array:\t");
	scanf("%d",&l);
	printf("\n");
	int numeri[l];
	for (int i=0; i<l;i++){
		printf("inserisci un numero:\t");
		scanf("%d",&numeri[i]);
		printf("\n");
	}
	printf("il tuo numero %c:\t %d\n",138,converti(numeri,l));
}
int converti(int array[],int lungh){
	int numero;
	if(lungh==1)
		numero=array[0];
		else 
			numero=converti(array,lungh-1)*10+array[lungh-1];
			return numero;
}