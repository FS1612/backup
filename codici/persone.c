#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data{
	int giorno;
	int mese;
	int anno;
}DATA;
typedef struct persona{
	char nome[20];
	char cognome[20];
	DATA d;
} PERSONA;
typedef struct nodo {
	PERSONA p;
	struct nodo*next;
}NODO;
void scambia(NODO*nodo1,NODO*nodo2);
NODO*inserisciTesta(NODO*head);
NODO*inserisciCoda(NODO*head);
void ordina(NODO*head);

NODO*cancellaValore(NODO*head);
NODO*cancellaTesta(NODO*head);
NODO*cancellaCoda(NODO*head);
void stampaValore(NODO*head);
void visualizzaLista(NODO*head);
void visualizzaPersona(PERSONA*p);
void visualizzaData(DATA*d);
void inserisciPersona(PERSONA*p);
void inserisciData(DATA*d);
int main(){
	NODO*head=NULL;
	int richiesta;
	richiesta=-1;
	while(richiesta!=0){
		printf("ciao sono un programma che gestisce una lista di persone\n");
		printf("come posso aiutarti\n");
		printf("1->inserisci persona in testa\n");
		printf("2->inserisci persona in coda\n");
		printf("3->stampa lista\n");
		printf("4->stampa una persona sapendo nome e cognome\n");
		printf("5->cancella persona in testa alla lista\n");
		printf("6->cancella persona in coda alla lista\n");
		printf("7-> cancella persona di nome e cognome\n");
		printf("8->ordina la lista\n");
		scanf("%d%*c",&richiesta);
		if(richiesta==1){
			head= inserisciTesta(head);
		}
		else if(richiesta==2){
			head=inserisciCoda(head);
		}
		else if(richiesta==3){
			visualizzaLista(head);
		}
		/*else if(richiesta==4){
		 * stampaValore(head);
		}*/
		else if(richiesta==5){
		  head=cancellaTesta(head);
		  }
		 else if(richiesta==6){
		   head=cancellaCoda(head);
		   }
		  else if(richiesta==7){
		    head=cancellaValore(head);
		    }
		   else if(richiesta==8){
		     ordina(head);
			 }
			else if(richiesta!=0){
				printf("drogati meno\n");
			}
			else{
				printf("bella per te\n");
			}
}
}
void inserisciData(DATA*d){
	printf("inserisci data di nascita della nuova persona\n");
	printf("inserisci giorno\t");
	scanf("%d",&d->giorno);
	printf("inserisci mese:\t");
	scanf("%d",&d->mese);
	printf("inserisci anno:\t");
	scanf("%d",&d->anno);
}
void inserisciPersona(PERSONA*p){
	printf("inserisci dettagli persona\n");
	printf("inserisci nome:\t");
	fgets(p->nome,20,stdin);
	printf("inserisci cognome:\t");
	fgets(p->cognome,20,stdin);
	p->nome[strlen(p->nome)-1]='\0';
	p->cognome[strlen(p->cognome)-1]='\0';
	inserisciData(&(p->d));
}
NODO*inserisciTesta(NODO*head){
	NODO*nuovonodo=malloc(sizeof(NODO));
	inserisciPersona(&(nuovonodo->p));
	nuovonodo->next=head;
	return nuovonodo;
}
NODO*inserisciCoda(NODO*head){
	NODO*nuovonodo=malloc(sizeof(NODO));
	inserisciPersona(&(nuovonodo->p));
	if(head==NULL)
		head=nuovonodo;
		else{
			NODO*nodo;
			nodo=head;
			while(nodo->next!=NULL){
				nodo=nodo->next;
			}
			nodo->next=nuovonodo;
		}
		return head;
}
void visualizzaData(DATA*d){
	printf("la sua data di nascita %c:",138);
	printf("GIORNO /MESE/ANNO\n");
	printf("%d          %d         %d\n",d->giorno,d->mese,d->anno);
}
void visualizzaPersona(PERSONA*p){
	printf("ecco i dettagli anagrafici della persona \n");
	printf("si chiama di nome:\t%s",p->nome);
	printf("\n");
	printf(" di cognome:\t%s",p->cognome);
	printf("\n");
	visualizzaData(&(p->d));
}
void visualizzaLista(NODO*head){
	if(head==NULL)
		printf("lista vuota, nulla da  stampare\n");
		else{
			while(head!=NULL){
				visualizzaPersona(&(head->p));
				head=head->next;
			}
		}
}

NODO*cancellaTesta(NODO*head){
	NODO*temp;
	temp=head;
	head=head->next;
	free(temp);
	return head;
}
NODO*cancellaCoda(NODO*head){
	if(head==NULL)
		printf("lista vuota\n");
		else{
			if(head->next==NULL){
				free(head);
				head=NULL;
				printf("adesso la lista %c vuota\n",138);
			}
			else{
				NODO*corrente;
				NODO*successivo;
				corrente=head;
				successivo=head->next;
				while(successivo->next!=NULL){
					corrente=successivo;
					successivo=successivo->next;
				}
				free(successivo);
				corrente->next=NULL;
			}
		}
		return head;
}

NODO*cancellaValore(NODO*head){
	char nome[20];
	char cognome[20];
	printf("inserisci nome della persona da eliminare dalla lista\n");
	fgets(nome,20,stdin);
	printf("inserisci cognome della persona da cancellare\n");
	fgets(cognome,20,stdin);
	nome[strlen(nome)-1]='0';
	cognome[strlen(cognome)-1]='0';
	int nome1=strcmp(head->p.nome,nome);
	int cognome1=strcmp(head->p.cognome,cognome);
	if(head==NULL)
		printf("lista vuota,nulla da cancellare\n");
		else{
			if((nome1==0)&&(cognome1==0)){
				NODO*temp;
				temp=head;
				head=head->next;
				free(temp);
			}
			else{
				int cancellato=0;
				NODO*prec;
				NODO*suc;
				prec=head;
				suc=head->next;
				while(suc->next!=NULL&&!cancellato){
					if((nome1==0)&&(cognome1==0)){
						free(suc);
				prec->next=suc->next;
				cancellato=1;
					}
					else{
						prec=suc;
						suc=suc->next;
					}
				}
				if(!cancellato)
					printf("valore inesistente\n");
			}
		}
		return head;
}
void scambia(NODO*nodo1,NODO*nodo2){
	PERSONA temp;
	temp=nodo1->p;
	nodo1->p=nodo2->p;
	nodo2->p=temp;
}
void ordina(NODO*head){
	NODO* prec;
	NODO*suc; 
	NODO*minimo;
	prec=head;
	if(prec==NULL)
		printf("lista vuota\n");
		else{
			while(prec->next!=NULL){
				minimo=prec;
				for(suc=prec->next;suc!=NULL;suc=suc->next)
					if((suc->p.d.anno)<(minimo->p.d.anno))
						minimo =suc;
						scambia(minimo,suc);
						prec=prec->next;
			}
			printf("ecco la lista ordinata\n");
			 visualizzaLista(head);
		}
}