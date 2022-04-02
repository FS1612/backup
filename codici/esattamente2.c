#include <stdio.h>
#include <stdlib.h>
int esattamenteDue(int seq[], int l);
int main(){
	printf("ciao sono un programma che verifica ricorsivamente se in ogi sequenza di 3  numeri esistono 2 positivi\n");
	int lung;
	printf("inserisci lunghezza array di numeri\n");
	scanf("%d",&lung);
	int interi[lung];
	for(int i=0;i<lung;i++){
		printf("inserisci un numero\t");
		scanf("%d",&interi[i]);
	}
	if(esattamenteDue(interi,lung))
		printf("istanza verificata\n");
		else
			printf("istanza negativa, riprova\n");
}
int esattamenteDue(int seq[], int l){
	int verificato;
	if(l<3)
		verificato=1;
		else
			verificato=((seq[0]>0&&seq[1]>0&&seq[2]<=0)||(seq[0]>0&&seq[2]>0&&seq[1]<=0)||(seq[2]>0&&seq[1]>0&&seq[0]<=0))&&esattamenteDue(seq+1,l-1);
	return verificato;
}