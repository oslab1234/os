#include<stdio.h>
#include<stdlib.h>
void main()
{
 int memsize,framesize,Noframes,Remframes,Nopages,pageno,offset,i,phyaddr;
 int pageTable[10],flag=1;
 printf("Enter the total memory size : ");
scanf("%d",&memsize);
 printf("Enter the frame size : ");
 scanf("%d",&framesize);
 Noframes=memsize/framesize;
 printf("The Total no. of frames availble in memory are : %d\n",Noframes);
 Remframes=Noframes;
 printf("Enter the no. of pages required : ");
 scanf("%d",&Nopages);
 if(Nopages>Noframes)
 {
 printf("Memory is full!!");
 exit(0);
 }
 Remframes-=Nopages;
 printf("Enter the page table : \n");
 for(i=0;i<Nopages;i++)
 scanf("%d",&pageTable[i]);
 printf("Page Table : \n");
 printf("-------------\n");
 printf("| page no | frame no |\n");
 for(i=0;i<Nopages;i++)
 printf("| %d | %d |\n",i,pageTable[i]);
 while(flag==1)
 {
 printf("Enter the page no and offset :\n");
 scanf("%d%d",&pageno,&offset);
 if(pageno>=Nopages||offset>=framesize)
 {
 printf("trap: Page Number or offset illegal");
 exit(0);
 }
 phyaddr=(pageTable[pageno]*framesize)+offset;
 printf("Fsize=%d,offset=%d\nframe no=%d",framesize,offset,pageTable[pageno]);
 printf("\nThe Physical Address is -- %d\n", phyaddr);
 printf("Continue : yes=1, no=0 \n");
 scanf("%d",&flag);
 }
}
