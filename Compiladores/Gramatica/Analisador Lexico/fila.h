typedef struct No{
	char *token;
	char *lexema;
	int pos;
	struct No *next;

}No;
typedef struct tfila{
	No *first;
}tfila;
fila.first=NULL;

int adcionar(tfila *fila, char *token, char *lexema, int pos);
int tabela(tfila *fila);

int adcionar(tfila *fila){
	No *newNo = (No*) malloc(sizeof(No));
	if(newNo==NULL)return 1;

	newNo->token=token;	
	newNo->lexema=lexema;
	newNo->pos=pos;
	
	if(fila.first==NULL)
		fila.firt=newNo;

	return 0;
}
int tabela(tfila *fila){
	No *aux=tfila->first;
	printf("LEXEMA\t\tTOKEN\t\tPOSIÃ‡Ã‚O\n");
	while(aux!=NULL){
		printf("%s\t\t%s\t\t%i\n",aux->token, aux->lexema, aux->pos);
		aux = aux->next;	
	}
}
