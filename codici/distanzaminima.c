#include <stdlib.h>
#include  <stdio.h>
int numeriConsecutivi(int s[],int l);
int main(){
	int l;
	printf("lunghezza sequenza?\n");
	scanf("%d",&l);
	int seq[l];
	for (int i=0;i<l;i++){
		printf("inserisci numero\n");
		scanf("%d",&seq[i]);
	}
	if(numeriConsecutivi(seq,l))
		printf("istanza verificata");
		else 
			printf("istanza negativa");
}
int numeriConsecutivi(int s[],int l){

	int verificato;
	if(l==0)
		verificato=0;
		else
			if(s[0]==s[1])
				verificato=1;
				else
					verificato=numeriConsecutivi(s+1,l-1);
			return verificato;
}