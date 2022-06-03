#include <sys/fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex[6];
pthread_t tid[6];

void* run(void* argv)
{
    int i,id = *(int*)argv;
    for(i = 0;i < 6;i++)
    {
        printf("Person %d is thinking\n",id);
        if (id & 1)
        {
            pthread_mutex_lock(&mutex[id]);
            printf("Person %d picked the %d chop.\n", id, id);
            pthread_mutex_lock(&mutex[(id - 1 + 5) % 5]);
            printf("Person %d picked the %d chop.\n", id, (id - 1 + 5) % 5);
            printf("Person %d is eating\n",id);
            sleep(1);
            printf("Person %d put the %d chop back.\n", id, (id - 1 + 5) % 5);
            pthread_mutex_unlock(&mutex[(id - 1 + 5) % 5]);
            printf("Person %d put the %d chop back.\n", id, id);
            pthread_mutex_unlock(&mutex[id]);
        }
        else
        {
            pthread_mutex_lock(&mutex[(id - 1 + 5) % 5]);
            printf("Person %d picked the %d chop.\n", id, (id - 1 + 5) % 5);
            pthread_mutex_lock(&mutex[id]);
            printf("Person %d picked the %d chop.\n", id, id);
            printf("Person %d is eating\n",id);
            sleep(1);
            pthread_mutex_unlock(&mutex[id]);
            printf("Person %d put up the %d chop back.\n", id, id);
            pthread_mutex_unlock(&mutex[(id - 1 + 5) % 5]);
            printf("Person %d put up the %d chop back.\n", id, (id - 1 + 5) % 5);
        }
    }
}

int main()
{
    int person_id[6];
    for (int i = 0;i < 5;++i){
        pthread_mutex_init(&mutex[i],NULL);
        person_id[i] = i + 1;
        }
    for (int i = 0;i < 5;++i) {
        pthread_create(&tid[i],NULL,run,(void*)&person_id[i]);
    }
    for (int i = 0;i < 5;++i)
        pthread_join(tid[i],NULL);
    for (int i = 0;i < 5;++i)
        pthread_mutex_destroy(&mutex[i]);
    return 0;
}