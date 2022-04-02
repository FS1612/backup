#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inverti(char *stringa);
void invertiStringa(char *st1, int i ;int j);
int main(){
	printf("ciao sono un programma che inverte ricorsivamente le stringhe\n");
	char stringa[20];
	printf("inserisci stringa\t");
	fgets(stringa,20,stdin);
	stringa[strlen(stringa)-1]='\0';
	printf("la stringa iniziale era \t%s",stringa);
	inverti(stringa);
	printf("quella invertita e' %s\t",stringa);
}
void invertiStringa(char *st1,int i,int j){
	if(i<j){
		char temp;
		temp=st1[i];
		st1[i]=st1[j];
		st1[j]=temp;
		invertiStringa(st1,i+1,j-1);
	}
}
void inverti(char *stringa){
	int l;
	l=strlen(stringa)-1;
	invertiStringa(stringa,0,l);
}