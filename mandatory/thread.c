/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:50:25 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/29 14:28:08 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if(pthread_create(&data->philos[i].thread, NULL,
				&ft_routine, &data->philos[i]))
			print_message("Error in creating philo threads");
		usleep(1000);
		i++;
	}
	if(pthread_create(&data->doc, NULL, &ft_doc_watch, data))
		print_message("Error in creating doc thread");
}

int	ft_thread_join(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_join(data->doc, NULL))
		error_message('j');
	while (i < data->num_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			error_message('j');
		usleep(100);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		mutex_destroy(&data->forks[i]);
		mutex_destroy(&data->philos[i].arceus);
		i++;
	}
	mutex_destroy(&data->print);
	mutex_destroy(&data->mutex);
	return (0);
}

long long	get_time()
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	return ((long long)(tv.tv_sec) * 1000 + (long long)(tv.tv_usec) / 1000);
}
/* struct timeval tv is used to store the time information. */
