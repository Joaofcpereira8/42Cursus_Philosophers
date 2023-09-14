#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_FILOSOFOS 5

pthread_mutex_t garfos[NUM_FILOSOFOS];

void mutex_create()
{
    for (int i = 0; i < NUM_FILOSOFOS; i++)
    {
        pthread_mutex_init(&garfos[i], NULL);
    }
}

void mutex_destroy()
{
    for (int i = 0; i < NUM_FILOSOFOS; i++)
    {
        pthread_mutex_destroy(&garfos[i]);
    }
}

void *routine(void *args)
{
    int id = *(int *)args;
    int garfo_esquerda = id;
    int garfo_direita = (id + 1) % NUM_FILOSOFOS; // Garfo à direita é o próximo

    while (1)
    {
        // Pensar (realize atividades não relacionadas aos garfos)
        printf("%d está pensando.\n", id);

        // Pegar garfos
        pthread_mutex_lock(&garfos[garfo_esquerda]);
        printf("%d pegou o garfo esquerdo (%d).\n", id, garfo_esquerda);
        pthread_mutex_lock(&garfos[garfo_direita]);
        printf("%d pegou o garfo direito (%d).\n", id, garfo_direita);

        // Comer
        printf("%d está comendo.\n", id);

        // Liberar garfos
        pthread_mutex_unlock(&garfos[garfo_esquerda]);
        printf("%d largou o garfo esquerdo (%d).\n", id, garfo_esquerda);
        pthread_mutex_unlock(&garfos[garfo_direita]);
        printf("%d largou o garfo direito (%d).\n", id, garfo_direita);
    }
    return NULL;
}

int main()
{
    pthread_t filosofos[NUM_FILOSOFOS];
    int ids[NUM_FILOSOFOS];

    mutex_create();

    for (int i = 0; i < NUM_FILOSOFOS; i++)
    {
        ids[i] = i;
        pthread_create(&filosofos[i], NULL, routine, &ids[i]);
    }

    for (int i = 0; i < NUM_FILOSOFOS; i++)
    {
        pthread_join(filosofos[i], NULL);
    }

    mutex_destroy();

    return 0;
}
