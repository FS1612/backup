#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Punto{
	float x;
	float y;
	char colore[20];
}PUNTO;
typedef struct nodo{
	PUNTO p;
	struct nodo*next;
}NODO;
void visualizzaColore(NODO*head);
NODO*cancellaValore(NODO*head);
void visualizzaPunto(PUNTO*p);
void visualizzaNodo(NODO*head);
void leggiPunto(PUNTO*p);
NODO*inserisciTesta(NODO*head);
int main(){
	NODO* head=NULL;
	int r;
	r=-1;
	while(r!=0){
		printf("ciao sono un programma che gestisce una lista di punti\n");
		printf("1->inserisci in testa un punto\n");
		printf("2->cancellazione punti con coordianata y=0\n");
		printf("3->stampa punti di minima distanza euclidea\n");
		printf("4->visualizza per colore\n");
		printf("5->stampa lista\n");
		printf("0->esci\n");
		printf("cosa desideri fare/t");
		scanf("%d",&r);
		if (r==1){
			head=inserisciTesta(head);
		}
			else if(r==2){
			head=cancellaValore(head);
			}
			else if(r==3){
				
			}
			else if(r==4){
			visualizzaColore(head);
			}
			else if(r==5){
			visualizzaNodo(head);
			}
			else if(r!=0){
			printf("riprova!\n");}
		else if(r!=0){
			printf("riprova!\n");
		}
	}
	 
void leggiPunto(PUNTO*p){
	char colore[20];
	printf("inserisci dettagli punto\n");
	printf("inserisci coordinata x:\t");
	scanf("%f",&p->x);
	printf("inserisci coordinata y:\t");
	scanf("%f",&p->y);
	printf("inserisci il colore del punto:\t");
	fgets(p->colore, 20,stdin);
	colore[strlen(colore)-1]='\0';
	printf("\n");
}
NODO*inserisciTesta(NODO*head){
	NODO*nuovonodo=malloc(sizeof(NODO));
	leggiPunto(&(nuovonodo->p));
	nuovonodo->next=head;
	return nuovonodo;
}
void visualizzaPunto(PUNTO*p){
	printf("ecco il tuo punto\n");
	printf("coordinata x:\t %f",p->x);
	printf("coordinata y:\t %f",p->y);
	printf("colore del punto:\t %s",p->colore);
}
void visualizzaNodo(NODO*head){
	if(head==NULL)
		printf("la lista sembra vuota\n");
		else{
			while(head->next!=NULL){
				visualizzaPunto(&(head->p));
				head=head->next;
			}
		}
}
NODO*cancellaValore(NODO*head){
	NODO*corrente;
	NODO* successivo; 
	float y;
	y=0;
	if(head==NULL)
		printf("la lista e' vuota, non posso cancellare nulla\n");
		else{
			if(head->p.y==y){
				//*cancella testa
				NODO* temp;
				temp=head;
				head=head->next;
				free(temp);
			}
			else{
				corrente=head;
				successivo=head->next;
				while(successivo!=NULL){
					if(successivo->p.y==y){
						corrente->next=successivo->next;
						free(successivo);
						printf("punto cancellato!\n");
					}
					else{
						corrente=successivo;
						successivo=successivo->next;
					}
				}
				else
					printf("non esiste un punto di colore %s\n",colore);
			}
		}
		return head;
}
void visualizzaColore(NODO*head){
	char colore [20];
	printf("inserisci colore del punto da cercare\n");
	fgets(colore,20,stdin);
	colore[strlen(colore)-1]='\0';
	if(head==NULL)
		printf("lista vuota\n");
		else{
			while(head!=NULL){
				if(strcmp(head->p.colore,colore)==0){
					printf("ecco il tuo punto\n");
					visualizzaPunto(&(head->p));
					head->head->next;
				}
			}
			
		}
}