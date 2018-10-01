#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
void tabela(char *regex, char *texto){
	regex_t reg;
	if(regcomp(&reg, regex, REG_EXTENDED|REG_NOSUB)!=0){
		  	fprintf(stderr,"erro regcomp\n");
			exit(1);
	}
	if((regexec(&reg, texto, 0, (regmatch_t *)NULL,0)==0))
		printf("%s\t\t%s\t\t%i\n", regex, texto,0);
	else
		printf("Erro LEXEMA %i:%i\n", 0,0);

}
void verifica(char *caminho){
	typedef struct tokens{
	      char *nome_token;
	      char *regex;
	};
	size_t linha, coluna;
	//tokens
	//:{WS}*
		//parenteses
		char *a_parentese="\\(";
		char *f_parentese="\\)";
		//
		char *virgula=",";
		//
		////inicio e fim: se, senao, enquanto
		char *inicio="\\{";
		char *fim="\\}";
		////marcador de fim de comando
		char *fim_linha=";";
		////inteiro
		char *numero="(\\-|\\+)?([0-9])+";
		////String
		char *frase="\"[:word:]+\"";
		////Definindo inicio de programa
		char *programa ="programa";
		char *fimprograma="fimprograma";
		////definindo nome de comandos
		char *inteiro = "inteiro";
		char *leia = "leia";
		char *escreva ="escreva";
		//
		char *se ="se";
		char *senao ="senao";
		char *enquanto ="enquanto";
		//
		////Operadores logicos
		char *menor="<";
		char *maior=">";
		////Operador de 
		char *recebe="=";
		////Operadores matematicos 
		char *soma ="+";
		char *subtracao="-";
		char *multiplicacao="*";
		char *divisao="/";
		//id
		char *id= "[:alpha:]([:word:])+";
		printf("TOKEN\t\tLEXEMA\t\tPosiÃ§Ã£o\n");	
		tabela(a_parentese, "(");
		
}
int main(){
	verifica("a");
	return 0;
}
