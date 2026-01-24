#include<stdio.h>
int main() {
FILE *f1,*f2;
char file1[100],file2[100],ch;

printf("Enter the source file name : ");
scanf("%s",file1);	
printf("Enter the target file name : ");
scanf("%s",file2);

f1=fopen(file1,"r");

if(f1==NULL) {
printf("Cannot open source file");
return 1;
}

f2=fopen(file2,"w");

if(f2==NULL) {
printf("Cannot open target file");
fclose(f1);
return 1;
}

while((ch=fgetc(f1))!=EOF)
	fputc(ch,f2);
	
printf("\nFile copied successfully!");

fclose(f1);
fclose(f2);

return 0;

}
