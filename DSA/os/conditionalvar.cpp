#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int ready = 0;

void* waiter(void* arg) {
    pthread_mutex_lock(&mutex);
    while (!ready) {
        printf("Thread A: Waiting for signal...\n");
        pthread_cond_wait(&cond, &mutex);  // Sleep + Unlock mutex
    }
    printf("Thread A: Got signal! Proceeding...\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* signaler(void* arg) {
    sleep(2); // Simulate some work
    pthread_mutex_lock(&mutex);
    ready = 1;
    printf("Thread B: Sending signal!\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, waiter, NULL);
    pthread_create(&t2, NULL, signaler, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
