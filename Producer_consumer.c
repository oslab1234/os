#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
int buffer[10],front,rear;
sem_t mutex,full,empty;
void *producer(void *arg)
{
 int i;for(i=0;i<10;i++)
 {
 sem_wait(&empty);
 sem_wait(&mutex);
 printf("Produced element : %d \n",i);
 buffer[(++rear)%10]=i;
 sleep(1);
 sem_post(&mutex);
 sem_post(&full);
 }
}
void *consumer(void *arg)
{
 int ele,i;
 for(i=0;i<10;i++)
 {
 sem_wait(&full);
 sem_wait(&mutex);
 ele=buffer[(++front)%10];
 printf("Consumed element : %d \n",ele);
 sleep(1);
 sem_post(&mutex);
 sem_post(&empty);
 }
}
void main()
{
 pthread_t t1,t2;
 sem_init(&mutex,0,1);
 sem_init(&full,0,0);
 sem_init(&empty,0,10);
 pthread_create(&t1,NULL,producer,NULL);
 pthread_create(&t2,NULL,consumer,NULL);
 pthread_join(t1,NULL);
 pthread_join(t2,NULL);
}
