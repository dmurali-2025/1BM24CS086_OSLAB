/*#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

#define N 8
int buf[N];
int in = 0, out = 0;

sem_t e, f;
pthread_mutex_t m;

int prod_item() {
    static int it = 1;
    return it++;
}

void cons_item(int it) {
    printf("Consumed: %d\n", it);
}

void* prod(void* a) {
    int it;
    while (1) {
        it = prod_item();
        sem_wait(&e);
        pthread_mutex_lock(&m);
        buf[in] = it;
        printf("Produced: %d at %d\n", it, in);
        in = (in + 1) % N;
        pthread_mutex_unlock(&m);
        sem_post(&f);
        sleep(1);
    }
}

void* cons(void* a) {
    int it;
    while (1) {
        sem_wait(&f);
        pthread_mutex_lock(&m);
        it = buf[out];
        printf("Consumed: %d from %d\n", it, out);
        out = (out + 1) % N;
        pthread_mutex_unlock(&m);
        sem_post(&e);
        cons_item(it);
        sleep(2);
    }
}

int main() {
    pthread_t p, c;
    sem_init(&e, 0, N);
    sem_init(&f, 0, 0);
    pthread_mutex_init(&m, NULL);
    pthread_create(&p, NULL, prod, NULL);
    pthread_create(&c, NULL, cons, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    sem_destroy(&e);
    sem_destroy(&f);
    pthread_mutex_destroy(&m);
    return 0;
}
*/
