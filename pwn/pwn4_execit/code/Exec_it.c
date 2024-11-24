#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char arr[32];
	memset(arr,0,sizeof(arr));
	gets(arr);
	execve(arr,0,0);
	return 0;
}