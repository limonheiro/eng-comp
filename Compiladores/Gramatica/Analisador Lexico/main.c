#include <string.h>
#include "lex.h"
#include "fila.h"
int main(int argc, char **argv){
	FILE *file=fopen("tokens","r");
	char *nome_token;
	char *regex_texto;
	char texto[100];
	rNo regex;
	tNo tabel;
	if(file==NULL)
		printf("Erro:Não foi possivel abrir o arquivo.\n\n\a");
	else{
		while(fgets(texto, 100, file)){
			nome_token=strtok(texto, "=");
			regex_texto=strtok(NULL,"\0");
			adcionar_token(&regex, nome_token, regex_texto);
		}	
	}
	if(argv[1]==NULL)
		verifica(&regex, &tabel, argv[0]);
	else
		verifica(&regex, &tabel, argv[1]);

	if((strcmp(argv[0],"-lt")==0))
			tabela(&tabel);
	else
		printf("ERRO: %s não identificado", argv[0]);
	return 0;
}
