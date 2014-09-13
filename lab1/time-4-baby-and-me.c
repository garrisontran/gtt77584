#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/times.h>
/*****************************************************/
int main()
{
 struct tms clk;
 time_t t;
 int pid,ppid,id,status;
 id = fork();
 printf("Start: %d\n",time(&t));
 if (id == 0)
 {
  pid = getpid();
  printf("PPID: %d PID: %d\n",getppid(),getpid());
 }
 else 
 {
  wait(&status);
  printf("PPID: %d PID: %d CPID: %d RETVAL: %d\n",getppid(),getpid(),pid,id);
 }
 times(&clk);
 printf("USER: %d SYS: %d\nCUSER: %d CSYS: %d\n",clk.tms_utime,clk.tms_stime,clk.tms_cutime,clk.tms_cstime);
 printf("Stop: %d\n",time(&t));
 return 0;
}