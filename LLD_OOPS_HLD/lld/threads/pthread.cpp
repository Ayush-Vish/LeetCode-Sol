#include<stdio.h>
#include<pthread.h>


pthread_mutex_t mutex;
int count=0;


void *fun(void *arg){
    for(int i=0;i<1000000;i++){
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&t1,NULL,fun,NULL);
    pthread_create(&t2,NULL,fun,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Count: %d\n", count);
    pthread_mutex_destroy(&mutex);
    return 0;
}
