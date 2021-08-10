#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
 int fd,ftr;
 int n;
 char data[]={"111111######222222******333333"},buf[6];
 fd=open("test.txt",O_RDWR);
 if(fd==-1)
 {
 printf("not able to creat/open a file\n");
 return -1;
 }
 write(fd,data,sizeof(data));
 read(fd,buf,12);
 write(1,buf,12);
 ftr=lseek(fd,10,SEEK_SET);
 printf("\nPointer is at %d position\n" , ftr);
 read(fd,buf,6);
 write(1,buf,6);
 printf("\n");
 ftr=lseek(fd,1,SEEK_SET);
 printf("Pointer is at %d position\n" , ftr);
 read(fd,buf,6);
 write(1,buf,6);
 printf("\n");
 ftr=lseek(fd,6,SEEK_CUR);
 printf("Pointer is at %d position\n" , ftr);
read(fd,buf,6);
 write(1,buf,6);
}
