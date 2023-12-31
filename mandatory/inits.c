/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:50:38 by jofilipe          #+#    #+#             */
/*   Updated: 2023/10/23 17:16:57 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* philos[i].l_fork = &data->forks: Assign the left fork of the philosopher to
point to the same fork resource as the global data->forks.

if (data->num_philos != 1)
{ philos[i].r_fork = &data->forks[(i + 1) % data->num_philos]; }:
This conditional checks if there is more than one philosopher.
If there is more than one philosopher, it assigns the right fork of
the philosopher to point to the fork at (i + 1) % data->num_philos.
The modulo operation ensures that the rightmost philosopher's right fork
points to the leftmost philosopher's
fork, creating a circular arrangement of forks. */

int	structs_init(t_data *data, int argc, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_to_eat = ft_atoi(argv[5]);
	else
		data->times_to_eat = -1;
	data->all_ate = 0;
	data->died = 0;
	data->time_start = get_time();
	mutex_init(&data->print);
	mutex_init(&data->mutex);
	if (verifs(data) != 0)
		return (-1);
	if (verifs2(data) != 0)
		return (-1);
	return (0);
}

t_philos	*philo_init(t_data *data)
{
	t_philos	*philos;
	int			i;

	i = 0;
	philos = malloc(sizeof(t_philos) * data->num_philos);
	if (!philos)
		return (NULL);
	while (i < data->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].last_meal = get_time();
		philos[i].times_eaten = 0;
		philos[i].l_fork = &data->forks[i];
		if (data->num_philos != 1)
			philos[i].r_fork = &data->forks[(i + 1) % data->num_philos];
		philos[i].data = data;
		mutex_init(&philos[i].arceus);
		i++;
	}
	return (philos);
}

pthread_mutex_t	*forks_init(int num_philo)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * num_philo);
	if (!forks)
		return (NULL);
	while (i < num_philo)
	{
		mutex_init(&forks[i]);
		i++;
	}
	return (forks);
}
