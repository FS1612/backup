#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct punto{
	char colore[20];
	int x;
	int y;
}PUNTO;
typedef struct nodo{
	PUNTO p;
	struct nodo* next;
}NODO;
NODO*acquisizione();
void salvataggio(NODO*head);
void visualizzaPunto(PUNTO*p);
void leggiPunto(PUNTO*p);
NODO*inserisciCoda(NODO*head);
void visualizzaLista(NODO*head);
NODO*inserisciTesta(NODO*head);
NODO*cancellaValore(NODO*head);
void visualizzaColore(NODO*head,char*s);
int main(){
	NODO* head=acquisizione();
	int richiesta;
	richiesta=-1;
	while(richiesta!=0){
		printf("ciao sono un programma che gestisce una lista di punti\n");
		printf("1->inserisci punto in testa alla lista\n");
		printf("2->cancella punti con coordinata y=0\n");
		printf("3->visualizza lista\n");
		printf("4->visualizza per colore\n");
		printf("5->inserisci coda\n");
		scanf("%d%*c",&richiesta);
		if(richiesta==1){
			head=inserisciTesta(head);
		}
		else if(richiesta==2){
			head=cancellaValore(head);
		}
		else if (richiesta==3){
			visualizzaLista(head);
		}
		else if(richiesta==4){
		char stringa[20];
			printf("inserisci colore da ricercare\n");
			fgets(stringa,20,stdin);
			stringa[strlen(stringa)-1]='\0';
			visualizzaColore(head,stringa);
		}
		else if(richiesta==5){
			head=inserisciCoda(head);
		}
		else if(richiesta!=0){
			printf("drogati di meno\n");
		}
		else
		printf("alla prossima\n");
		salvataggio(head);
	}
}
void leggiPunto(PUNTO*p){
	printf("inserisci dettagli punto\n");
	printf("inserisci colore punto:\t");
	fgets(p->colore,20,stdin);
	p->colore[strlen(p->colore)-1]='\0';
	printf("inserisci coordinata x del punto:\t");
	scanf("%d",&p->x);
	printf("inserisci coordinata y del punto:\t");
	scanf("%d",&p->y);
}
NODO*inserisciCoda(NODO*head){
	NODO*nuovonodo=malloc(sizeof(NODO));
	leggiPunto(&(nuovonodo->p));
	nuovonodo->next=NULL;
	if(head==NULL)
		head=nuovonodo;
		else{
			NODO*nodo=head;
			while(nodo->next!=NULL){
				nodo=nodo->next;
			}
			nodo->next=nuovonodo;
		}
		return head;
}
NODO*inserisciTesta(NODO*head){
	NODO*nuovonodo=malloc(sizeof(NODO));
	leggiPunto(&(nuovonodo->p));
	nuovonodo->next=head;
	return nuovonodo;
}
void visualizzaPunto(PUNTO*p){
	printf("ecco il tuo punto\n");
	printf("colore :\t %s\n",p->colore);
	printf("x:\t %d\n",p->x);
	printf("y:\t %d\n",p->y);
}
void visualizzaLista(NODO*head){
	if(head==NULL)
		printf("lista vuota,non si puo stampare nulla\n");
		else{
			while(head!=NULL){
				visualizzaPunto(&(head->p));
				head=head->next;
			}
		}
}
NODO*cancellaValore(NODO*head){
	int cancellato=0;
	if(head==NULL)
		printf("lista vuota,nullada cancellare\n");
		else{
			if(head->p.y==0){
				NODO*temp;
				temp=head;
				head=head->next;
				free(temp);
				printf("cancellazione effettuata in testa\n");
			}
			else{
				NODO*prec;
				NODO*suc;
				prec=head;
				suc=head->next;
				while(suc!=NULL&&!cancellato){
					if(suc->p.y==0){
						prec->next=suc->next;
						free(suc);
						cancellato=1;
					}
					else{
						prec=prec->next;
						suc=suc->next;
					}
				}
			}
		}
		return head;
}
void visualizzaColore(NODO*head,char*s){
	if(head==NULL)
		printf("nessun punto di quel colore, la lista e vuota\n");
		else{
			while(head!=NULL){
				if(strcmp(head->p.colore,s)==0)
					visualizzaPunto(&(head->p));
					head=head->next;
			}
		}
}
void salvataggio(NODO*head){
	FILE*fp=fopen("punti.dat","wb");
	if(fp==NULL)
		printf("niente file\n");
		else{
			if(fp!=NULL){
				while(head!=NULL){
					fwrite(&(head->p),sizeof(PUNTO),1,fp);
					head=head->next;
			}
			printf("salvato\n");
		}
		else
			printf("non salvato\n");
}
}
NODO*acquisizione(){
	int letto;
	FILE*fp=fopen("punti.dat","rb");
	PUNTO p;
	NODO*head=NULL;
	NODO*prec;
	struct nodo*suc;
	
			if(fp!=NULL){
				letto=fread(&p,sizeof(PUNTO),1,fp);
				if(letto){
					head=malloc(sizeof(NODO));
					head->p=p;
					prec=head;
				
				do{
					letto=fread(&p,sizeof(PUNTO),1,fp);
					if(letto){
						suc=malloc(sizeof(NODO));
						suc->p=p;
						prec->next=suc;
						prec=suc;
					}
					else
						prec->next=NULL;//* se mon leggi nulla
				}
				while(letto);
			}
			else
				printf("nulla da fare\n");
		}
		return head;
	}

