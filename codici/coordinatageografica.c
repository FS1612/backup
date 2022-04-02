#include <stdio.h>
#include <stdlib.h>
typedef struct coordinate{
	float longitudine;
	float latitudine;
}COORDINATE;
typedef struct nodo{
	COORDINATE c;
	struct nodo*next;
}NODO;
void visualizzaCoordinate(COORDINATE* c);
void visualizzaNodo(NODO*head);
NODO*eliminaTesta(NODO*head);
void leggiCoordinate(COORDINATE*c);
NODO*inserisciCoda(NODO*head);
int main(){
	NODO*head=NULL;
	int richiesta=-1;
	while(richiesta!=0){
		printf("caro utente sono un programma che gestisce delle coordinate\n");
	printf("come posso aiutarti\n");
	printf("1->inserimento in coda alla lista\n");
	printf("2->cancellazione in testa \n");
	printf("3->visualizza lista\n");
	printf("0->esci dal programma\n");
	scanf("%d",&richiesta);
	if (richiesta==1)
		head=inserisciCoda(head);
		else if(richiesta==2){
		head=eliminaTesta(head);}
			else if(richiesta==3){
			visualizzaNodo(head);}
				else if(richiesta!=0){
				printf("prova di nuovo\n");}
					else{
					printf("bella per te\n");}
	}
}
void leggiCoordinate(COORDINATE*c){
	printf("inserisci le coordinate che vuoi aggiungere\n");
	printf("inserisci latitudine\t");
	scanf("%f",&c->latitudine);
	printf("inserisci longitudine\t");
	scanf("%f",&c->longitudine);
}
NODO*inserisciCoda(NODO*head){
	NODO* nuovonodo=malloc(sizeof(NODO));
	leggiCoordinate(&(nuovonodo->c));
	nuovonodo->next=NULL;
	if (head==NULL)
		//*inserimento in testa
		head=nuovonodo;
		else{
			//*inserimento non in testa
			NODO*nodo=head;
			while(nodo->next!=NULL){
				nodo=nodo->next;
			}
			nodo->next=nuovonodo;//*alla fine collega il novo nodo
		}
		return head;
}
NODO*eliminaTesta(NODO*head){
	if (head==NULL)
		printf("nulla da cancellare\n");
		else{
			NODO*temp;
	temp=head;
	head=head->next;
	free(temp);
		}
	return head;
}
void visualizzaCoordinate(COORDINATE* c){
	printf("ecco le tue coordinate\n");
	printf("latitudine%f:\t\n",c->latitudine);
	printf("longitudine%f:\t\n",c->longitudine);
}
void visualizzaNodo(NODO*head){
	if(head==NULL)
		printf("la lista %c vuota nulla si puo stampare\n",138);
		else{
			while(head!=NULL){
				visualizzaCoordinate(&(head->c));
				head=head->next;
			}
		}
}