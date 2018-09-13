#include <stdio.h>
#include <stdlib.h>
int menu();
int inserir();
// void ordenar();

int main(){
	menu();
	return 0;
			
}
int menu(){
		unsigned char select;
		printf("\n1: Inserir Nomes");
		printf("\n2: Ordenar Lista");
		printf("\nQ: Sair\n");
		printf("> ");
		scanf("%c",&select);
		//if(select == '\n')
		//	continue;
		//fflush(stdin);
    		//__fpurge(stdin);
		
		switch(select){
			case '1':
				inserir();
				break;
			case '2':
				//ordenar();
				break;
			case 'Q':
				return 0;
		}
}
int inserir(){
	FILE *entrada;
	char *nome;
		
	if((entrada=fopen("arquivo1.txt","a"))==NULL){
		printf("\n\a\aNão foi possivel criar o arquivo");
		return 0;
	} 
		printf("Nome: ");

		scanf(" %[^\n]", nome);
		printf("aa");
	 	//fflush(stdin);
    		//__fpurge(stdin);
		fprintf(entrada, "%s\n", nome);
		fclose(entrada);
	menu();
}
