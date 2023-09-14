# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

pthread_mutex_t	mutex[2];
pthread_t	verif;
pthread_t	carros[4];
int	value[2] = {100, 100};
int	arr[4] = {0, 1, 2 ,3};

void	create_mutex(int value)
{
	int i = 0;
	while (i < value)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
}

void	destroy_mutex(int value)
{
	int	i = 0;
	while (i < value)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
}

void	*hmgota(void *arg)
{
	int i = *(int *)arg;
	printf("Carro[%d], ficou sem gota\n", i);
	exit(1);
}

void	*deposito(void *arg)
{
	int	i = *(int*)arg;
	if((i == 0 || i == 2) && value[0] > 0)
	{
		pthread_mutex_lock(&mutex[0]);
		value[0] -= 10;
		printf("value: %d\n", value[0]);
		printf("Carro %d ja gastou 10L\n", arr[i]);
		pthread_mutex_unlock(&mutex[0]);
	}
	else if((i == 1 || i == 3) && value[1] > 0)
	{
		pthread_mutex_lock(&mutex[1]);
		value[1] -= 20;
		printf("value: %d\n", value[1]);
		printf("Carro %d ja gastou 20L\n", arr[i]);
		pthread_mutex_unlock(&mutex[1]);
	}
	if (value[0] == 0 || value[1] == 0)
	{
		if (pthread_create(&verif, NULL, &hmgota, &arr[i]) != 0)
		{
			perror("Error\n");
		}
	}
	//printf("value: %d\n", value[i]);
	return(0);
}



int main()
{
	int j = 0;
	int c = 0;
	create_mutex(2);
	while (value[j] >= 0)
	{
		c = 0;
		while (c < 4)
		{
			if(pthread_create(&carros[c], NULL, &deposito, &arr[c]) != 0)
			{
				perror("Error\n");
			}
			if (pthread_join(carros[c], NULL) != 0)
			{
				perror("Error\n");
			}
			//printf("value[i] = %d\n", value[i]);
			c++;
		}
		j++;
	}
	destroy_mutex(2);

/* 	i = 0;
	while (i < 4)
	{
		if (pthread_join(carros[i], NULL) != 0)
		{
			perror("Error\n");
		}
		i++;
	} */
}
