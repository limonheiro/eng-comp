#include <stdio.h>
#include <string.h>
//int verificar()
int lerArquivo(char *fita, char *arquivo, char *log);
//int M(char*fita,char *estados, char *alfabeto, char *funcao, char *incial, char *finais);
int lerArquivo(char *fita, char *arquivo, char *log){
	int i;
	const char prefix='{';
	const char posfix='}';
	char estados[3000];
	char alfabeto[3000];
	char funcao[3000];
	char inicial[3000];
	char finais[3000];
        char texto[3000];
        char buffer[300];
        FILE *file=fopen(arquivo,"r");
        if(file==NULL)
                printf("ERRO\n");
        else{
                while(fgets(buffer,300,file)){
                        strcat(texto,buffer);
                }
		strcat(texto,'\0');
                //printf("%s\n",texto);
                fclose(file);
        }
	for(i=0;texto[i]!='\0';i++){
		if(texto[i]=='Q'&&texto[i+1]=='{'){
			int pos;
			int a=0;
			//for(pos=i;(texto[pos]!='}')||(texto[pos]!='E');pos++, a++)
			//	estados[a] = texto[pos];
			//printf("%s",estados);
		}
		/*
		if(texto[i]=='E'&&texto[i+1]=='{'){
			int pos;
			int a=0;
			for(pos=i; texto[pos]!='}'||texto[pos]!='G';pos++, a++)
				alfabeto[a] = texto[pos];		
		}*/
	}	
	return -1;
}
