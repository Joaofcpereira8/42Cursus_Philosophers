/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:50:38 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/14 11:50:32 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philos *philos)
{
	philos->id = 0;
	philos->times_eaten = 0;
	philos->last_meal = 0;
	mutex_init(&philos->r_fork);
	mutex_init(&philos->l_fork);
	mutex_init(&philos->arceus);

}

void	data_init(t_data *data, int argc, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->times_to_eat = ft_atoi(argv[5]);
	else
		data->times_to_eat = -1;
	data->all_ate = 0;
	data->died = 0;
	data->time_start = 0;
	mutex_init(&data->mutex);
	mutex_init(&data->error_print);
}
