/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mntrng.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:00:44 by jofilipe          #+#    #+#             */
/*   Updated: 2023/10/17 17:27:33 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_doc_watch(void *arg)
{
	t_data	*data;

	data = (t_data*)arg;
	while (1)
	{
		if (check_philo_dead(data))
			return (NULL);
		if (check_philo_ate(data))
			return (NULL);
	}
	return (NULL);
}

int	check_philo_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		mutex_lock(&data->philos[i].arceus);
		if ((get_time() - data->philos[i].last_meal) > data->time_to_die)
		{
			print_msg("died\n", &data->philos[i]);
			mutex_lock(&data->mutex);
			data->died = 1;
			mutex_unlock(&data->mutex);
			mutex_unlock(&data->philos[i].arceus);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_philo_ate(t_data *data)
{
	if (data->times_to_eat == -1)
		return (0);
	mutex_lock(&data->mutex);
	if (data->all_ate == data->num_philos)
	{
		mutex_unlock(&data->mutex);
		return(-1);
	}
	mutex_unlock(&data->mutex);
	return (0);
}
