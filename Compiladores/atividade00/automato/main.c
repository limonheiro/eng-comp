#include "automato.h"
int main(int *arg[],char *args[]){
	printf("fita: %s\n", args[1]);
	printf("arquivo: %s\n\n", args[2]);
	
	if(args[3]!=NULL)
		lerArquivo(args[1], args[2],args[3]);
	lerArquivo(args[1], args[2],NULL);
}


