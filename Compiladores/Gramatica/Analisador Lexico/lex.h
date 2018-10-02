#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
void tabela(token *token);
void adcionar_token(char *nome_token, char *regex);
typedef struct token{
	char *name_token;
	char *regex;
}token;

void tabela(token *token){
	size_t linha, coluna;
	printf("TOKEN\t\tLEXEMA\t\tPosiÃ§Ã£o\n");	
}

void verifica(char *caminho){	
	regex_t reg;

	if(regcomp(&reg, token.regex, REG_EXTENDED|REG_NOSUB)!=0){
		fprintf(stderr,"erro regcomp\n");
		exit(1);
	}
	if((regexec(&reg, texto, 0, (regmatch_t *)NULL,0)==0))
		printf("%s\t\t%s\t\t%i\n", regex, texto,0);
	else
		printf("Erro LEXEMA %i:%i\n", 0,0);
}
