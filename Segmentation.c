#include<stdio.h>
#include<stdlib.h>
void main()
{
 int Nosegemnts,segmentno,offset,i,phyaddr;
 int segmentTable[10][10],flag=1;
printf("Enter the no. of segments : ");
 scanf("%d",&Nosegemnts);
 printf("Enter the segement table (Base value and Limit value) : \n");
 for(i=0;i<Nosegemnts;i++)
 scanf("%d%d",&segmentTable[i][0],&segmentTable[i][1]);
 printf("Segement Table : \n");
 printf("-------------------------\n");
 printf("| segement no | Base | Limit |\n");
 for(i=0;i<Nosegemnts;i++)
 printf("| %d | %d | %d |\n",i,segmentTable[i][0],segmentTable[i][1]);
 while(flag==1)
 {
 printf("Taking the Logical address :\n");
 printf("Enter the segment no and offset :\n");
 scanf("%d%d",&segmentno,&offset);
 if(offset>segmentTable[segmentno][1])
 {
 printf("trap: offset illegal");
 exit(0);
 }
 phyaddr=segmentTable[segmentno][0]+offset;
 printf("\nThe Physical Address is -- %d\n", phyaddr);
 printf("Continue : yes=1, no=0 \n");
 scanf("%d",&flag);
 }
}
