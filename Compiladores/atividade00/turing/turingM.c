#include <stdio.h>

void q0(char *fita, int pos);
void q1(char *fita, int pos);
void q2(char *fita, int pos);
void q3(char *fita, int pos);
void q4(char *fita, int pos);

int main(){
	char fita[]="aabb0\0";
	printf("%s\n", fita);
	q0(fita, 0);
	return 0;
}
void q0(char *fita, int pos){
	if(fita[pos]=='a'){
		fita[pos]='A';
		pos++;
		q1(fita,pos);
	}
	if(fita[pos]=='B'){
                pos++;
                q3(fita,pos);
        }
	if(fita[pos]=='0'){
                pos++;
                q4(fita,pos);
        }
}
void q1(char *fita, int pos){
	if(fita[pos]=='a'){
		pos++;
		q1(fita, pos);
	}
	if(fita[pos]=='b'){
		fita[pos]='B';
		pos--;
		q2(fita,pos);
	}
	if(fita[pos]=='B'){
		pos++;
		q1(fita,pos);
	}
}
void q2(char *fita, int pos){
	if(fita[pos]=='a'){
		pos--;
		q2(fita,pos);
	}
	if(fita[pos]=='A'){
		pos++;
		q0(fita,pos);
	}
	if(fita[pos]=='B'){
		pos--;
		q2(fita,pos);
	}
}
void q3(char *fita, int pos){
	if(fita[pos]=='B'){
		pos++;
		q3(fita, pos);
	}
	if(fita[pos]=='0'){
		pos--;
		q4(fita,pos);
	}
}
void q4(char *fita, int pos){
	printf("%s\n",fita);
}
