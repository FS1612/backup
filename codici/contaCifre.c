#include<stdio.h>
#include<stdlib.h>
int contaCifre(int numero){
	int totale;
	if((numero/10)==0)//* un qualsiasi numero ad una cifra diviso per dieci ha come risultato 0 poiche in una divisione intera i decimali non contano
		totale=1;
		else
			totale=1+contaCifre(numero/10);
			return totale;
}
int main(){
	printf("ciao sono un programma che dato un numero in input ne calcola le cifre di cui e composto\n");
	int numero;
	printf("inserisci un numero intero\n");
	scanf("%d",&numero);
	printf("il tuo numero ha %d cifre\n",contaCifre(numero));
}
