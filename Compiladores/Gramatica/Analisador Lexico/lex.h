#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

typedef struct token{
        char *name_token;
        char *regex;
}token;

void tabela(token *token);

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
