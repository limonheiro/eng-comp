#ifndef LEX_H_
#define LEX_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
typedef struct rNo{
	char *name_token;
	char *regex;
	struct rNo *next;
}rNo;
typedef struct rfila{
	rNo *first;
	rNo *last;
}rfila;
rfila regexfila;
regexfila.first=NULL;
regexfila.last=NULL;

int adcionar_token(rfila *fila,char *nome_token, char *regex);
void verifica(rfila *fila, char *file);

void verifica(rfila *fila,char *file){	
	regex_t reg;
	char *texto;
	size_t pos_x, pos_y;

	if(regcomp(&reg, fila->regex, REG_EXTENDED|REG_NOSUB)!=0){
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}
	if((regexec(&reg, texto, 0, (regmatch_t *)NULL,0)==0)){
		adcionar(fila, fila->name_token, texto, pos_x, pos_y); 
	}
	else
		printf("Erro LEXEMA %i:%i\n", pos_x, pos_y);
}

int adcionar_token(rfila *fila, char *nome_token, char *regex){
	rNo *newNo = (rNo*)malloc(sizeof(rNo));
	if(newNo==NULL) return 1;
	newNo->name_token = nome_token;
	newNo->regex = regex;
	
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
#endif /*LEX_H_*/
