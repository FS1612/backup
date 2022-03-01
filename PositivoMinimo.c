#include <stdio.h>

/* funzione che restituisce 1 se la sequenza contiene almeno un intero positivo, 0 altrimenti */
int esistePositivo(int seq[], int lungh) {
	// pre: lungh>=0, lungh è la lunghezza di seq
	int res = 0;			// valore da calcolare
	int i= 0;				// indice nella sequenza
 
	/* cerca interi positivi, se ne trovi uno ti puoi fermare 
	 * altrimenti vai a guardare il prossimo */
	while(i<lungh && !res)
		if(seq[i]>0)
			res = 1;
		else
			i++;
	return res;
}

/* funzione che restituisce il minimo valore positivo in una sequenza */
int positivoMinimo(int seq[], int lungh) {
	// pre: lungh>=1, lungh è la lunghezza di seq, seq contiene almeno un intero positivo

	int min=-1;			// valore da calcolare
	int i= 0;		    // indice nella sequenza
 
	/* cerca il primo intero positivo, che esiste per le precondizioni */
	while(min<0)
		if(seq[i]>0)
			min=seq[i];
		else
			i++;
	
	/* ora dentro min c'è un valore positivo, guarda tutti gli altri interi 
	 * e vedi se ce n'è uno positivo più piccolo */
	for(i++; i<lungh; i++)
		if(seq[i]>0 && seq[i]<min)
			min=seq[i];
		i++;
	
	return min;	
}

/* funzione principale */ 
int main(){
	int lunghezza;		// per la lunghezza della sequenza
	
	/* input */
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	printf("Introduci %d interi: ", lunghezza);
	for(int i=0; i<lunghezza; i++)
		scanf("%d", &sequenza[i]);

	/* verifica se esiste almeno un intero positivo  */
	if(!esistePositivo(sequenza,lunghezza))
		printf("Non hai introdotto neanche un intero positivo!\n");
	else
		printf("L'intero positivo minimo fra quelli da te introdotti vale %d\n", positivoMinimo(sequenza,lunghezza));
}
