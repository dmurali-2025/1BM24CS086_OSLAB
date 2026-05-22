/*#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
sem_t mutex;
sem_t S[N];

int left(int i) { return (i + N - 1) % N; }
int right(int i) { return (i + 1) % N; }

void test(int i) {
    if (state[i] == HUNGRY && state[left(i)] != EATING && state[right(i)] != EATING) {
        state[i] = EATING;
        printf("Philosopher %d takes forks %d and %d and starts eating\n", i+1, left(i)+1, i+1);
        sem_post(&S[i]);
    }
}

void take_fork(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is hungry\n", i+1);
    test(i);
    sem_post(&mutex);
    sem_wait(&S[i]);
}

void put_fork(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d puts down forks %d and %d and starts thinking\n", i+1, left(i)+1, i+1);
    test(left(i));
    test(right(i));
    sem_post(&mutex);
}

void* philosopher(void* num) {
    int i = *(int*)num;
    while (1) {
        printf("Philosopher %d is thinking\n", i+1);
        sleep(1);
        take_fork(i);
        sleep(2);
        put_fork(i);
    }
}

int main() {
    pthread_t tid[N];
    int phil[N];
    sem_init(&mutex, 0, 1);
    for (int i = 0; i < N; i++) {
        sem_init(&S[i], 0, 0);
        state[i] = THINKING;
        phil[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &phil[i]);
    }
    for (int i = 0; i < N; i++) pthread_join(tid[i], NULL);
    return 0;
}
*/

