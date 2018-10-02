#ifndef FILA_H_
#define FILA_H_
#include <stdlib.h>
#include <stdio.h>
typedef struct tNo{
	char *token;
	char *lexema;
	int pos_x;//coluna
	int pos_y;//linha
	struct tNo *next;

}tNo;

int adcionar(tNo *fila, char *token, char *lexema, int pos_x, int pos_y);

int tabela(tNo *fila);

int adcionar(tNo *fila, char *token, char *lexema, int pos_x, int pos_y){
	tNo *newNo = (tNo*) malloc(sizeof(tNo));
	if(newNo==NULL)return 1;

	newNo->token=token;	
	newNo->lexema=lexema;
	newNo->pos_x=pos_x;
	newNo->pos_y=pos_y;
	newNo=fila;
	newNo->next=NULL;

	return 0;
}
int tabela(tNo *fila){
	tNo *aux=fila;
	printf("LEXEMA\t\tTOKEN\t\tPOSIÇÂO\n");
	while(aux!=NULL){
		printf("%s\t\t%s\t\t%i:%i\n",aux->token, aux->lexema, aux->pos_y,aux->pos_x);
		aux = aux->next;	
	}
	return 0;
}
#endif /*FILA_H_*/
