#include <stdlib.h>
#include <stdio.h>
void stampaArray(int a[], int dim);
int conta(int intero);
void creaArray(int intero,int l);
int main(){
	int l;
	printf("sono un programma che converte un numero in array\n");
	int intero;
	scanf("%d",&intero);
	l=conta(intero);
	creaArray(intero,l);
}
int conta(int intero){
	int totale;
	if((intero/10)==0)
		totale=1;
		else 
			totale=1+conta(intero/10);
			return totale;
}
void creaArray(int intero,int l){

	int array[l];
	if(l-1==0)
		array[l]=intero;
		else{
			array[l]=intero%10;
			creaArray(intero/10,l-1);
			
}
stampaArray(array,l);
}
void stampaArray(int a[], int dim){
	int i;
	printf("Array:");
	for(i=0; i<dim; i++)
		printf(" %d ",a[i]);
	printf("\n");
}