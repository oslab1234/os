#include<stdio.h>
#include<unistd.h>
int main()
{
 int fd[2],Return,pid;
 Return=pipe(fd);
 if(Return==-1)
 {
 printf("Error occurred while creating the pipe!!\n");
 return 1;
 }
 pid=fork();
 if(pid==0)
 {
 char readmsg[20];
 read(fd[0],readmsg,sizeof(readmsg));
 printf("Msg-1 read from parent process : %s\n",readmsg);
 read(fd[0],readmsg,sizeof(readmsg));
printf("Msg-2 read from parent process : %s\n",readmsg);
 }
 else
 {
 char writemsg[2][10]={"Hi","Welcome"};
 printf("writing Msg-1 to child process : %s\n",writemsg[0]);
 write(fd[1],writemsg[0],sizeof(writemsg[0]));
 printf("writing Msg-2 to child process : %s\n",writemsg[1]);
 write(fd[1],writemsg[1],sizeof(writemsg[1]));
 }
}
