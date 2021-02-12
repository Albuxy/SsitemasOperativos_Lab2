#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 10                 // number of threads to be created
pthread_t tids[N];
pthread_mutex_t lock;

int a= 0;

void* myThreadCode(void* arg) {
    
    pthread_mutex_lock(&lock);
    a = a+1;
    pthread_mutex_unlock(&lock);
    
    sleep (2);
    
    pthread_mutex_lock(&lock);
    a = a-1;
    pthread_mutex_unlock(&lock);
    
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    int i;
    for(i=0;i<N;i++) {
		
        pthread_create(&tids[i],NULL,myThreadCode,NULL); /* create the thread */
               
    }

    for(i=0;i<N;i++) pthread_join(tids[i],NULL);          /* wait for the thread to exit */   
    
    printf ("%d\n", a);
    if (a == 0) exit(0);
    exit(1); 
}

