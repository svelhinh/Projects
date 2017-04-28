#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int c,char**v){c=0;
int i = 5;
char a[99];char*b="#include <stdio.h>%1$c#include <string.h>%1$c#include <stdlib.h>%1$cint main(int c,char**v){c=0;%1$cint i = %2$d;%1$cchar a[99];char*b=%3$c%4$s%3$c;FILE *f;!strcmp(v[c],%3$c./Sully%3$c)?0:i--;sprintf(a,%3$cSully_%%d.c%3$c,i);f=fopen(a,%3$cw%3$c);fprintf(f,b,10,i,34,b);fclose(f);i?sprintf(a,%3$cgcc -o Sully_%%d Sully_%%d.c;./Sully_%%d%3$c,i,i,i):sprintf(a,%3$cgcc -o Sully_%%d Sully_%%d.c%3$c,i,i);system(a);}";FILE *f;!strcmp(v[c],"./Sully")?0:i--;sprintf(a,"Sully_%d.c",i);f=fopen(a,"w");fprintf(f,b,10,i,34,b);fclose(f);i?sprintf(a,"gcc -o Sully_%d Sully_%d.c;./Sully_%d",i,i,i):sprintf(a,"gcc -o Sully_%d Sully_%d.c",i,i);system(a);}