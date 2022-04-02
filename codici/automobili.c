#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Auto {
	char marca[20];
	char modello[20];
	int quanti;
	float prezzo;
}AUTO;
typedef struct nodo{
	AUTO a;
	struct nodo*next;
}NODO;
NODO*aquisizione();
void salvataggio(NODO*head);
void stampaAuto(AUTO*a);
void visualizzaLista(NODO*head);
void leggiAuto(AUTO*a);
NODO*inserisciCoda(NODO*head);
int main(){
	NODO*head=aquisizione();
	int richiesta;
	richiesta =-1;
	while(richiesta!=0){
		printf("ciao sono un programma che gestisce un autosalone\n");
		printf("come posso aiutarti\n");
		printf("1->inserisci nuova auto in coda alla lista\n");
		printf("2->stampa il catalogo auto\n");
		printf("3->vendi auto\n");
		printf("0->salva listino ed esci\n");
		scanf("%d%*c",&richiesta);
		if(richiesta==1){
			head=inserisciCoda(head);
		}
		else if(richiesta==2){
			visualizzaLista(head);
		}
		/*else if(richiesta==3){
			head=vendiAuto(head);
		}*/
		else if (richiesta!=0){
			printf("fuma di meno\n");
		}
		else{
			printf("bella per te allora\n");
			salvataggio(head);
		}
	}
}
void leggiAuto(AUTO*a){
	printf("inserisci dettagli auto\n");
	printf("inserisci modello\t");
	fgets(a->modello,20,stdin);
	a->modello[strlen(a->modello)-1]='\0';
	printf("inserisci marca\t");
	fgets(a->marca,20,stdin);
	a->marca[strlen(a->marca)-1]='\0';
	printf("inserisci modelli disponibili\t");
	scanf("%d",&a->quanti);
	printf("inserisci costo\t");
	scanf("%f",&a->prezzo);
}
NODO*inserisciCoda(NODO*head){
	NODO*nuovonodo=malloc(sizeof(NODO));
	leggiAuto(&(nuovonodo->a));
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
	void stampaAuto(AUTO*a){
		printf("ecco la tua auto\n");
		printf("marca :\t%s\n",a->marca);
		printf("modello :\t%s\n",a->modello);
		printf("quantita disponibile :\t%d\n",a->quanti);
		printf("costo:\t%f\n",a->prezzo);
	}
	void visualizzaLista(NODO*head){
		if(head==NULL)
			printf("listino vuoto, nulla da stampare\n");
			else{
				while(head!=NULL){
					stampaAuto(&(head->a));
					head=head->next;
				}
			}
	}
	void salvataggio(NODO*head){
		FILE*fp=fopen("auto.dat","wb");
		if(fp!=NULL){
			while(head!=NULL){
				fwrite(&(head->a),sizeof(AUTO),1,fp);
				head=head->next;
			}
			printf("salvataggio riuscito\n");
		}
		else
			printf("salvataggio non riuscito\n");
	}
	NODO*aquisizione(){
		FILE*fp=fopen("auto.dat","rb");
		NODO*prec;
		NODO*suc;
		AUTO a;
		int letto;
		NODO*head=NULL;
		if(fp!=NULL){
			letto=fread(&a,sizeof(AUTO),1,fp);
			if(letto){
				head=malloc(sizeof(NODO));
				head->a=a;
				prec=head;
			do{
				letto=fread(&a,sizeof(AUTO),1,fp);
				if(letto){
					suc=malloc(sizeof(NODO));
					suc->a=a;
					prec->next=suc;
					prec=suc;
				}
				else
					prec->next=NULL;//*file terminato ultimo puntatore =null
			}
			while(letto);
		}
	}
else
printf("lettura non possibile\n");
return head;   
	}