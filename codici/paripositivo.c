#include <stdio.h>
#include <stdlib.h>
int pariPositivo(int seq[],int l);
int main(){
	printf("sono un programma che verifica ricorsivamente se esiste almeno 1 coppia di consecutivi 1 pari e uno positivo\n");
	int l;
	printf("inserisci lunghezza array\n");
	scanf("%d",&l);
	int interi[l];
	for(int i=0; i<l;i++){
		printf("inserisci numero\n");
		scanf("%d",&interi[i]);
	}
	if(pariPositivo(interi,l))
		printf("istanza verificata\n");
		else
			printf("istanza negativa,riprova\n");
}
int pariPositivo(int seq[],int l){
	int verificato;
	if(l<2)
		verificato=0;
		else
			verificato=((seq[0]>0&&seq[1]%2==0)||(seq[1]>0&&seq[0]%2==0))||pariPositivo(seq+1,l-1);
			return verificato;
}