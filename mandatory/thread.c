/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:50:25 by jofilipe          #+#    #+#             */
/*   Updated: 2023/10/17 18:12:21 by jofilipe         ###   ########.fr       */
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
			print_message("Error in creating philo threads\n");
		usleep(1000);
		i++;
	}
	if(pthread_create(&data->doc, NULL, &ft_doc_watch, data))
		print_message("Error in creating doc thread\n");
}

void	ft_thread_join(t_data *data)
{
	int	i;

	i = 0;
	if(pthread_join(data->doc, NULL))
		error_message('j');
	while (i < data->num_philos)
	{
		if(pthread_join(data->philos[i].thread, NULL))
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
}
