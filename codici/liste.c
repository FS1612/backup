#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*strutture*/
typedef struct Auto{
	char marca[20];
	char modello[20];
	int quanti;
	float prezzo;
	}AUTO;
	typedef struct nodo{
		AUTO macchina;
		struct nodo*next;
	}NODO;
/*invocazioni funzioni secondarie*/
void  leggiAuto( AUTO*a);
NODO* inserisciCoda( NODO*head);
void visualizzaAuto(AUTO* a);
void visualizza(NODO* head) ;
NODO* acquisizione();
void salvataggio(NODO* head);
NODO*acquistaAuto(NODO*head);
void visualizzaAuto2(AUTO* a);
/* funzione principale*/
int main(){
	NODO* head =acquisizione();
	int richiesta;//*per l'interazione con l'utente
	richiesta=-1;
	while(richiesta!=0){
		printf("ciao sono un programma che gestisce un autosalone\n");
		printf("come posso aiutarti?\n");
		printf("1->inserisci nuova auto\n");
		printf("2->acquista auto \n");
		printf("3->stampa catalogo auto\n");
		scanf("%d%*c", &richiesta);//*scansione di un intero e scansione a vuoto per liberare buffer(%*c) input
		if(richiesta==1)
			head = inserisciCoda(head);

		else  if(richiesta==2)
			head=acquistaAuto(head);

		else  if(richiesta==3)
		visualizza(head);
		else  if(richiesta!=0)
			printf("prova di nuovo\n");

		else {
			printf("alla prossima!\n");
			salvataggio(head);
		}
		
	}
}

/*funzioni secondarie*/
void leggiAuto(AUTO*a){//*funzione per la letuura delle variabili appartenenti al campo dati del nodo
	printf("inserisci dettagli auto\n");
	printf("inserisci marca della nuova auto\t");
	fgets(a->marca,20,stdin);
	printf("inserisci modello della nuova auto\t");
	fgets(a->modello,20,stdin);
	printf("inserisci  quantita auto disponibili\t");
	scanf("%d",&a->quanti);
	printf("inserisci costo della nuova auto\t");
	scanf("%f",&a->prezzo);
//* stringa[strlen(stringa)-1]='\0'; cancellazione ultimo elemento
}
NODO* inserisciCoda(NODO*head){
	struct nodo* nuovonodo=malloc(sizeof(struct nodo));
	leggiAuto(&(nuovonodo->macchina));//*passo a leggiauto l'indirizzo di memoria in cui deve salvare la nuova auto introdotta
	nuovonodo->next=NULL;
	if(head==NULL)//*se la testa ha come valore null,la testa assume il valore del nuovo nodo
		head=nuovonodo;
		else
		{
			struct nodo*nodo=head; 
			while(nodo->next!=NULL){
				nodo=nodo->next;
			}
			nodo->next=nuovonodo;
		}
		return head;
}
void visualizzaAuto(AUTO* a){
printf("ecco i dettagli della macchina\n");
printf("la marca dell'auto %c:\t %s",138,a->marca);
printf("il modello dell'auto %c:\t%s",138,a->modello);
printf("abbiamo a disposizione %d auto\n",a->quanti);
printf("l'auto costa:\t %f\n\n",a->prezzo);

}
void visualizzaAuto2(AUTO* a){
printf("ecco i dettagli della macchina\n");
printf("la marca dell'auto %c:\t %s",138,a->marca);
printf("il modello dell'auto %c:\t%s",138,a->modello);
printf("abbiamo a disposizione %d auto\n",a->quanti-1);
printf("l'auto costa:\t %f\n\n",a->prezzo);

}
void visualizza(NODO* head) {
	if(head==NULL)
		printf("Lista vuota!\n\n");
	else {
		printf("Ecco la lista!\n");
		while(head!=NULL) {
			visualizzaAuto(&(head->macchina));
			head = head->next;
		}
	}
}

NODO* acquisizione() {
	FILE* fp = fopen("autosalone.dat", "rb");					// per la lettura di un file binario
	NODO* head = NULL;										// testa della lista
	NODO* corrente;
	NODO* prec;	
	AUTO a;	
	int letto;																// lettura OK o no
	/* apertura fallita, nulla da fare */
	if(fp!=NULL) {
		/* leggi la prima auto della lista */
		letto = fread(&a, sizeof(AUTO), 1, fp);
		if(letto) {		// almeno un'auto è presente nel file
			/* memorizza nell'heap il primo nodo della lista */
			head = malloc(sizeof(NODO));
			head->macchina = a;
			/* devi tenere traccia dell'ultimo nodo letto, per collegarlo al successivo nella lista */
			prec = head;
			/* adesso leggi tutti gli altri nodi */
			do {
				/* leggi un nuovo nodo */
				letto = fread(&a, sizeof(AUTO), 1, fp);
				if(letto) {		// lo hai effettivamente letto?
					/* memorizza nell'heap il nuovo nodo */
					corrente = malloc(sizeof(NODO)) ;
					corrente->macchina = a;
					/* collega il nuovo nodo al precedente */
					prec->next = corrente;
					/* il nuovo nodo diventa il precedente */
					prec = corrente;
				}
				else // il file è terminato, setta il campo next dell'ultimo nodo
					prec -> next = NULL;
			}
			while(letto);
		}
	}
	else
		printf("Non %c possibile aprire il file!\n", 138);
return head;
}
/* SALVATAGGIO DATI SU FILE */
void salvataggio(NODO* head) {
	FILE* fp = fopen("autosalone.dat", "wb");									// per la scrittura di un file binario
	if(fp!=NULL) {
		while(head!= NULL) {													// procedi fino a che hai nodi
			fwrite(&(head->macchina), sizeof(AUTO), 1, fp);					// ciò che scrivi è una macchina
			head= head->next;											// passa al prossimo nodo
		}
		printf("Salvataggio riuscito!\n");
	}
	else
		printf("Salvataggio non riuscito!\n");
}
NODO*acquistaAuto(NODO*head){
	NODO* prec=head;
	NODO*suc=head->next;
	char marca[20];
	char modello[20];
	printf("che marca di auto stai cercando?\t");
	fgets(marca,20,stdin);
	printf("che modello di auto stai cercando?\t");
	fgets(modello,20,stdin);
	/*lista vuota*/
	if(head==NULL)
		printf("nel vatalogo non %c presente nessuna macchina\n",138);
		else{//*se nella lista esiste almeno un nodo
			if(head->macchina.marca==marca&&head->macchina.modello==modello){
				visualizzaAuto2(&(head->macchina));
		}
				else{
					
				while(suc!=NULL &&(suc->macchina.marca!=marca&&suc->macchina.modello!=modello))
				prec=prec->next;
				}
					if(suc==NULL)
						printf("non trovo nulla\n");
						else{//*trovato
						prec->next=suc->next;
						visualizzaAuto2(&(suc->macchina));
						free(suc);
					}
		}
		return head;
}
