#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j=1,m,s=0;char x;
int myatoi(char x){
	char p[2]={x,0};
	return atoi(p);
}
void Backdoor(void){
	char x[8];
	scanf("%s",&x);
	system(x);
	return;
}
void f(void){
	int i=0;
	printf("Right!\n");
	char cipher[]={0x9,0x1,0xb,0xfc,0x16,0x63,0xfc,0xf8,0xf9,0x5b,0xef,0xf9,0x5b,0xef,0xf1,0xef,0xf6,0xf1,0xf3,0xed,0xef,0xf6,0xf4,0xf1,0xf7,0xb1,0xb,0x5f,0xf5,0xf5,0x5f,0x5e,0xef,0x12,0x5f,0xf3,0xed,0x5a,0xb1,0x65,0x0};
	for(i=0;i<strlen(cipher);++i)
		cipher[i]=((cipher[i]+0x56)^0x34)-0x12;
	puts(cipher);
}
int main(){
	puts("--------Welcome to 2024YQCTF --------");
	puts("---Input x to start your PWN Game!---");
	char arr[13];unsigned short int ptr=0x6789;
	scanf("%c",&x);
	if(x!='x'){
		puts("Attention,please!"); 
		return 0;
	}
	printf("Input the ISBN:\n");
	scanf("%s",&arr);
	if(!(11<strlen(arr)<14)){
		puts("String length error!"); 
		return 0;
	}
	for(i=0;i<12;++i){
		if('0'<=arr[i]<='9'){
			s+=myatoi(arr[i])*j;
			++j;
		}
		else
			if(arr[i]!='-'){
				puts("Input error!");
				return 0;
			}
	}
	m=s%11;
	if(m==myatoi(arr[12])|| (m==10 && arr[12]=='X'))
		f();
	else{
		printf("Wrong!\n");
		for(i=0;i<12;++i)
			printf("%c",arr[i]);
		if(m==10){
			printf("X\n");
			if(!((ptr-(ptr&0xff00))>>7))
				Backdoor();
		}
		else
			printf("%d\n",m);
	}
	return 0;
}
