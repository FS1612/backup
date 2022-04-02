#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int minuscola(char*stringa);
int main(){
/*input*/ 
char stringa[50];
printf("ciao sono un programma che verifica ricorsivamente se esiste un carattere minuscolo in una stringa inserita da tastiera\n\n");
printf("inserisci stringa:\t");
fgets(stringa,50,stdin);
stringa[strlen(stringa)-1]='\0';
printf("la stringa completa %c :\t%s",138, stringa);
if(minuscola(stringa))
	printf("esiste almeno una minuscola\n\n");
	else 
		printf("non esistono minuscole\n\n");
}
int minuscola(char*stringa){
	int verificato;
	if(strlen(stringa)==0)
		verificato=0;
		else
			verificato=(stringa[0]>'a'&&stringa[0]<'z')||minuscola(stringa+1);
			return verificato;
}
