#include <string.h>
#include "lex.h"
#include "fila.h"
int main(int argc, char *argv){
	FILE *file=fopen("tokens","r");
	char *nome_token;
	char *regex;
	char texto[100];

	if(file==NULL)
		printf("Erro:Não foi possivel abrir o arquivo.\n\n\a");
	else{
		while(fgets(texto, 100, file)){
			nome_token=strtok(texto, "=");
			regex=strtok(NULL,"\0");
			adcionar_token(&regexfila, nome_token, regex);
		}	
	}
	if(argv[1]==NULL)
		verifica(&regexfila,argv[0]);
	else
		verfica(&regexfila,argv[1]);
	else
	if((strcmp(argv[0],"-lt")==0)
			tabela(&tabelafila);
	else
		printf("ERRO: %s não identificado", argv[0]);
	return 0;
}
