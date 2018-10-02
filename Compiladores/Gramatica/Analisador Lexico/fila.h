#ifndef FILA_H_
#define FILA_H_
typedef struct tNo{
	char *token;
	char *lexema;
	int pos_x;//coluna
	int pos_y;//linha
	struct tNo *next;

}tNo;
typedef struct tfila{
	tNo *first;
	tNo *last;
}tfila;
tfila tabelafila;
tabelafila->first=NULL;

int adcionar(tfila *fila, char *token, char *lexema, int pos_x, int pos_y);
int tabela(tfila *fila);

int adcionar(tfila *fila, char *token, char *lexema, int pos_x, int pos_y){
	tNo *newNo = (tNo*) malloc(sizeof(tNo));
	if(newNo==NULL)return 1;

	newNo->token=token;	
	newNo->lexema=lexema;
	newNo->pos_x=pos_x;
	newNo->pos_y=pos_y;
	
	if(fila->first==NULL){
		fila->first=newNo;
		fila->last=newNo;
	}
	else{
		fila->last->next=newNo;
		fila->last=newNo;
	}

	return 0;
}
int tabela(tfila *fila){
	tNo *aux=fila->first;
	printf("LEXEMA\t\tTOKEN\t\tPOSIÇÂO\n");
	while(aux!=NULL){
		printf("%s\t\t%s\t\t%i:%i\n",aux->token, aux->lexema, aux->pos_y,aux->pos_x);
		aux = aux->next;	
	}
	return 0;
}
#endif /*FILA_H_*/
