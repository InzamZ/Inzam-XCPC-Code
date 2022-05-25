#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

#define maxbuffer 30
int maker_pos = 0, customer_pos = 0;
char charbuffer[maxbuffer];

sem_t full, empty;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t make_tid[5], customer_tid[5];
int ids[5];

int fd;

void *maker(void *argv) {
    int n = *(int *)argv;
    char c;
    while (1) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        if (read(fd, &c, 1) == 0) {
            pthread_mutex_unlock(&mutex);
            sem_post(&full);
            break;
        }
        charbuffer[maker_pos] = c;
        printf("生产者线程 %d 已经生产 %c \n", n, c);
        maker_pos++;
        maker_pos %= maxbuffer;
        sem_post(&full);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *customer(void *argv) {
    int n = *(int *)argv;
    char c;
    while (1) {
        sem_wait(&full);
        // printf("这是消费者线程 %d\n", n);
        pthread_mutex_lock(&mutex);
        c = charbuffer[customer_pos];
        charbuffer[customer_pos] = '\0';
        customer_pos++;
        customer_pos %= maxbuffer;
        if (c == '\0') {
            pthread_mutex_unlock(&mutex);
            sem_post(&empty);
            break;
        }
        printf("消费者线程 %d 已经消费 %c \n", n, c);
        sem_post(&empty);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main() {
    fd = open("./input.txt", O_RDONLY);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, maxbuffer);
    for (int i = 1; i <= 3; ++i) {
        ids[i] = i;
        pthread_create(&make_tid[i], NULL, maker, &ids[i]);
    }
    for (int i = 1; i <= 4; ++i) {
        ids[i] = i;
        pthread_create(&customer_tid[i], NULL, customer, &ids[i]);
    }
    for (int i = 1; i <= 3; ++i)
        pthread_join(make_tid[i], NULL);
    sleep(1);
    return 0;
}