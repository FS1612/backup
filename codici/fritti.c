#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef  struct fritto{
	char nome[20];
	float prezzo;
	char tipo;
}FRITTO;
typedef struct nodo{
	FRITTO f;
	struct nodo*next;
}NODO;
void scambia(NODO*nodo1,NODO*nodo2);
void ordina(NODO*head);
void  visualizzaFritto(FRITTO*f);
 void visualizzaMenu(NODO*head);
NODO*inserisciCoda(NODO*head);
void leggiFritto(FRITTO*f);
int main(){
	NODO* head=malloc(sizeof(NODO));//*nodo fittizio
	head->next=NULL;
	int richiesta;
	richiesta =-1;
while(richiesta!=0){
		printf("ciao sono un programma che gestisce una lista di persone\n");
		printf("come posso aiutarti?\n");
		printf("1->visualizza menu\n");
		printf("2->inserisci fritto in coda \n");
		printf("3->ordina lista\n");
		scanf("%d%*c", &richiesta);//*scansione di un intero e scansione a vuoto per liberare buffer(%*c) input
		if(richiesta==1)
			visualizzaMenu(head);
			else  if(richiesta==2)
			head=inserisciCoda( head);
			else  if(richiesta==3){
			ordina(head);}
			else  if(richiesta!=0)
			printf("prova di nuovo\n");
		else {
			printf("alla prossima!\n");
		}
		
	}
}
void leggiFritto(FRITTO*f){
	printf("inserisci dettagli fritto\n");
	printf("inserisci nome del fritto\t");
	fgets(f->nome,20,stdin);
	printf("inserisci costo\t");
	scanf("%f%*c",&f->prezzo);
	printf("inserisci f se il fritto e' fresco o s se e' surgelato");
	scanf("%c",&f->tipo);
}
NODO*inserisciCoda(NODO*head){
	NODO*nuovonodo=malloc(sizeof(NODO));
	nuovonodo->next=NULL;
	leggiFritto(&(nuovonodo->f));
	if(head==NULL){
		head=nuovonodo;
	}
	else{
		NODO*nodo=head;
		while(nodo!=NULL){ 
			nodo=nodo->next;
		}
			nodo->next=nuovonodo;
	}
	return head;
}
void visualizzaFritto(FRITTO*f){
	printf("ecco i dettagli del tuo fritto\n");
	printf("il nome del fritto e': %s",f->nome);
	printf("il costo del fritto e': %f",f->prezzo);
	printf("il fritto e': %c",f->tipo);
	printf("s->surgelato");
	printf("f->fresco");
}
void visualizzaMenu(NODO*head){
	NODO*primo=malloc(sizeof(NODO));
	primo=head->next;
	if(primo==NULL)
		printf("lista vuota\n");
		else{
			while(primo!=NULL){
				visualizzaFritto(&(primo->f));
				primo=primo->next;
			}
		}
}
void scambia(NODO*nodo1,NODO*nodo2){
	FRITTO temp;
	temp=nodo1->f;
	nodo1->f=nodo2->f;
	nodo2->f=temp;
}
void ordina(NODO*head){
	NODO* corrente;
	NODO* successivo;
	NODO* minimo;
	corrente=head->next;
	if(corrente==NULL)
		printf("lista vuota\n");
		else{
			while(corrente->next!=NULL){
				for(successivo=corrente->next;successivo!=NULL;successivo=successivo->next)
					if((corrente->f.prezzo)>(successivo->f.prezzo)){
						minimo=successivo;
						scambia(minimo,corrente);
						corrente=corrente->next;
					}
			}
			printf("eccola ordinata\n");
			visualizzaMenu(head);
		}
}