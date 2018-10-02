#ifndef LEX_H_
#define LEX_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "fila.h"
typedef struct rNo{
	char *name_token;
	char *regex;
	struct rNo *next;
}rNo;

int adcionar_token(rNo *reg,char *nome_token, char *regex);
int verifica(rNo *reg, tNo *tabela, char *file);

int verifica(rNo *reg, tNo *tabela,char *file){	
	regex_t regex;
	char *texto;
	size_t pos_x, pos_y;
	rNo *aux=reg;
	while(aux!=NULL){
	if(regcomp(&regex, aux->name_token, REG_EXTENDED|REG_NOSUB)!=0){
		fprintf(stderr,"erro regcomp\n");
		return 1;
	}
	if((regexec(&regex, texto, 0, (regmatch_t *)NULL,0)==0)){
		adcionar(tabela, aux->name_token, texto, pos_x, pos_y); 
	}
	else
			printf("Erro LEXEMA %li:%li\n", pos_x, pos_y);

	}
	aux=aux->next;
}

int adcionar_token(rNo *reg, char *nome_token, char *regex){
	rNo *newNo = (rNo*)malloc(sizeof(rNo));
	if(newNo==NULL) return 1;
	
	newNo->name_token = nome_token;
	newNo->regex = regex;
	newNo->next=reg->next;
	reg->next=newNo;	
			
	return 0;
}
#endif /*LEX_H_*/
