#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int contaOccorrenze(char*stringa, char c);
int main(int argc, char **argv) {
	char stringa[20];
	char c;
    printf("sono un programma che verifica ricorsivamente se esiste 1 minuscola in una stringa\n");
	printf("inserisci una bella stringa\n");
	fgets(stringa,20,stdin);
	stringa[strlen(stringa)-1]='\0';
	printf("inserisci il carattere da cercare\n");
	scanf("%c",&c);
	printf("nella stringa %s il carattere %c %c presente %d volte\n",stringa,c,138,contaOccorrenze(stringa,c));
}
int contaOccorrenze(char*stringa, char c){
	int numero;
	if(strlen(stringa)==0)
		numero =0;
		else
			numero=(stringa[0]==c)+contaOccorrenze(stringa+1,c);
			return numero;
}