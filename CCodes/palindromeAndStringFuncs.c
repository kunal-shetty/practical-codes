#include<stdio.h>
#include<string.h>
void main(){
char str[100];
printf("Enter your string\n");
fgets(str,sizeof(str),stdin);
str[strcspn(str,"\n")]='\0';
int i,len=strlen(str);
char str2[len+1];
for(i=0;i<len;i++){
str2[i]=str[len-1-i];
}
str2[len]='\0';
if(strcmp(str,str2))
printf("Not a palindrome");
else
printf("Palindrome");
}
