#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

char ch[9],ch2[8];
int fd,bytes;
/*********************************************/
int main(int argc, char *argv[])
{
 char *a[34]={"NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI","DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","FS","GS","RS","US","SPACE","DEL"};
 char *p[3]={"EVEN","ODD"};
 if (argc > 2)
 {
  printf("too many arguments");
 }

 else if (argc == 2)
 {
  if (*argv[1]=='-')
   printf("no proper input");
  else
  {
   fd = open(argv[1],O_RDONLY);
  }
 }
 
 else
 {
  fd = 0;
 }
 
 printf("Original Ascii Decimal Parity\n");
 printf("-------- ----- ------- ------\n");
 while((bytes = read(fd,ch,9))>0)
 {
  int b;
  /*int u = 0;
  while (ch[u]!='\0')
  {
   strcpy(ch2[u],ch[u]);
   u++;
  }*/
  if (bytes<8)
  {
   for (b=bytes;b<8;b++)
   {
    ch[b]='0';
   }
  }
  if (*argv[1]!='-')
  {
   printf("%8s ",ch);
   if (decimal(ch)<=33||decimal(ch)==127)
   {
    if (decimal(ch)==127)
     printf("%4s ",a[33]);
    else
     printf("%4s ",a[decimal(ch)]);
   }
   else 
    printf("%4c ",decimal(ch));
   printf("%7d ",decimal(ch));
   printf("%7s\n",p[rity(ch)]);
  }
 }
 
}

int decimal(char *x)
{
 int j = 1;
 int d = 0;
 int i;
 for (i=7;i>0;i--)
 {
  d += j*(x[i]-'0');
  j*=2;
 }
 return d;
} 

int rity(char *p)
{
 int parity = 0;
 int i = 1;
 for (i=7;i>0;i--)
 {
  parity = parity^(p[i]-'0');
 }
 return parity;
}