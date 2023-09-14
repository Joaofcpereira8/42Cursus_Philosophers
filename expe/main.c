#include "philo.h"

pthread_t			*philoso;
pthread_mutex_t		*mutex;
int					times_eaten;
int					num_philo;
int					id;
int					c = 0;
int					l1 = 0;
int					r1 = 0;
int					tempo = 1000;
int					ok = 0;

void	mutex_create(int num)
{
	int i = 0;
	while (i < num)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
}

void	mutex_destroy(int num)
{
	int i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
}
int	mutex_lock(int num)
{
	if(pthread_mutex_lock(&mutex[num]))
		return (1);
	else
		return (0);
}

int	mutex_unlock(int num)
{
	if(pthread_mutex_unlock(&mutex[num]))
		return (1);
	else
		return (0);
}

void	*routine(void *args)
{
	int i = *(int *)args;
	ok = 0;
	int l = i;
	int r = (i + 1) % 5;
	i = i + 1;
	if (i % 2 == 0)
		usleep(2000);
	if(i % 2 == 0)
	{
		mutex_lock(r);
		printf("%d Has taken a right fork!", i);
		mutex_lock(l);
		printf("%d Has taken a left fork!", i);
		ok = 1;
	}
	else
	{
		mutex_lock(l);
		printf("%d Has taken a left fork!", i);
		mutex_lock(r);
		printf("%d Has taken a right fork!", i);
		ok = 1;
	}
	if(ok == 1)
	{
		if(i % 2 == 0)
			tempo -= 10;
		else
			tempo -= 5;
	}
}

int main(int argc, char **argv)
{
	int num = atoi(argv[1]);
	mutex = malloc(sizeof(pthread_mutex_t) * num);
	philoso = malloc(sizeof(pthread_t) * num);
	int *p = malloc(sizeof(int) * num);
	pthread_mutex_init(&*mutex, NULL);
	int i = 0;
	while(i < num)
	{
		p[i] = i;
		i++;
	}
	i = 0;
	mutex_create(num);
	while (i < num)
	{
		if(pthread_create(&philoso[i], NULL, &routine, &p[i]) != 0)
		{
			printf("Error");
			return(-1);
		}
		i++;
	}
	i = 0;
	while (i < num)
	{
		if(pthread_join(philoso[i], NULL) != 0)
		{
			printf("Error!");
			return(-1);
		}
		i++;
	}
}
