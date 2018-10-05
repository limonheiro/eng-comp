#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
	unsigned char caracter;
	struct No *next;
}No;

typedef struct fila{
	No *first;
	No *last;
}fila;

void inicializa(fila *nozinho);
int add(fila *nozinho, unsigned char texto);
int show(fila *nozinho);
void inicializa(fila *nozinho){
	nozinho->first=nozinho->last=NULL;
}
	
int add(fila *nozinho,unsigned char texto){

	No *newNo = (No*)malloc(sizeof(No));
	if(newNo==NULL) return 1;

	newNo->caracter=texto;
	
	if(nozinho->first==NULL){
		nozinho->first=newNo;
		nozinho->last=newNo;
	}else{
		nozinho->last->next=newNo;
		nozinho->last=newNo;
	}
	return 0;
}

int show(fila *nozinho){
	for(No *aux=nozinho->first;aux!=NULL; aux=aux->next){
		printf("%c", aux->caracter);	
	}
}

int size(char *file,size_t *linhaM, size_t *total){
	size_t sizel=0, sizelm=0, size=0;
	FILE *fp=fopen(file,"r");
	char c;
	
	if(fp!=NULL){
		while(fread(&c, sizeof(char),1,fp)){
			if(c=='\n')
				sizel++;
			if(sizel>sizelm)
				sizelm=sizel;
			size++;
		
		}
	}
	fflush(fp);
	fclose(fp);
	*linhaM=sizelm;
	*total=size;
}
int main(){
	fila noz;
	inicializa(&noz);
	size_t linhaM=0, total=0;
	size("fatorial.isa", &linhaM, &total);
	unsigned char textoC[total];
	unsigned char texto[linhaM];
	FILE *fp=fopen("fatorial.isa", "r");
	if(fp==NULL)
		printf("ERRO: Não possivel abrir o arquivo\n\a");
	else{
		while(fgets(texto,linhaM,fp)){
			strcat(textoC,texto);
		}
	}

	fclose(fp);
	for(size_t i=0;i<=total;i++)
		add(&noz,textoC[i]);
	
	show(&noz);
}
