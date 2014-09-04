#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

char ch[9];
int fd,bytes;
/*********************************************/
int main(int argc, char *argv[])
{
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
 
 bytes = read(fd,ch,8);
 printf("Original Ascii Decimal Parity\n");
 printf("-------- ----- ------- ------\n");
 if (*argv[1]!='-')
 {
  printf("%8s ",ch);
  //printf("%5c ",
  printf("%7d ",decimal(ch));
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

int getAscii(char *a)
{
 int n = decimal(a);
 //if (n<33 || n == 127)
 return n;
}

/*char par(char *p)
{
 int parity = 0;
 int i = 1;
 char r[1]={"EVEN","ODD"};
 for (i=8;i>0;i--)
 {
  parity = parity^(p[i]-'0');
 }
 if (parity==0)
  r[1] = "EVEN";
 else 
  r[1] = "ODD";
 return r;
}*/