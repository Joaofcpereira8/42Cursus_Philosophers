/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:41:07 by jofilipe          #+#    #+#             */
/*   Updated: 2023/10/18 18:38:37 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	if (philos->data->num_philos == 1)
	{
		mutex_lock(philos->l_fork);
		print_msg("has taken a fork\n", philos);
		mutex_unlock(philos->l_fork);
		return (NULL);
	}
	if (philos->id % 2 == 0)
		usleep(2000);
	while (philos->data->died == 0)
	{
		if (grab_forks(philos))
			return (NULL);
		if (eating(philos))
			return (NULL);
		if (sleeping(philos))
			return (NULL);
		if (thinking(philos))
			return (NULL);
	}
	return (NULL);
}

int	grab_forks(t_philos *phi)
{
	mutex_lock(&phi->data->mutex);
	if (phi->data->died >= 1 || phi->data->all_ate == phi->data->num_philos)
	{
		mutex_unlock(&phi->data->mutex);
		return (1);
	}
	mutex_unlock(&phi->data->mutex);
	if (phi->id % 2 == 0)
	{
		mutex_lock(phi->r_fork);
		print_msg("has taken a fork\n", phi);
		mutex_lock(phi->l_fork);
		print_msg("has taken a fork\n", phi);
	}
	else
	{
		mutex_lock(phi->l_fork);
		print_msg("has taken a fork\n", phi);
		mutex_lock(phi->r_fork);
		print_msg("has taken a fork\n", phi);
	}
	return (0);
}

int	eating(t_philos *phi)
{
	mutex_lock(&phi->data->mutex);
	if (phi->data->died >= 1 || phi->data->all_ate == phi->data->num_philos)
	{
		mutex_unlock(&phi->data->mutex);
		mutex_unlock(phi->l_fork);
		mutex_unlock(phi->r_fork);
		return (1);
	}
	mutex_unlock(&phi->data->mutex);
	mutex_lock(&phi->arceus);
	phi->last_meal = get_time();
	print_msg("is eating\n", phi);
	mutex_lock(&phi->data->mutex);
	phi->times_eaten++;
	if (phi->times_eaten != -1)
	{
		if (phi->times_eaten == phi->data->times_to_eat)
			phi->data->all_ate++;
	}
	mutex_unlock(&phi->data->mutex);
	mutex_unlock(&phi->arceus);
	usleep(phi->data->time_to_eat * 1000);
	mutex_unlock(phi->l_fork);
	mutex_unlock(phi->r_fork);
	return (0);
}

int	sleeping(t_philos *phi)
{
	mutex_lock(&phi->data->mutex);
	if (phi->data->died >= 1 || phi->data->all_ate == phi->data->num_philos)
	{
		mutex_unlock(&phi->data->mutex);
		return (1);
	}
	mutex_unlock(&phi->data->mutex);
	print_msg("is sleeping\n", phi);
	usleep(phi->data->time_start * 1000);
	return (0);
}

int	thinking(t_philos *phi)
{
	mutex_lock(&phi->data->mutex);
	if (phi->data->died >= 1 || phi->data->all_ate == phi->data->num_philos)
	{
		mutex_unlock(&phi->data->mutex);
		return (1);
	}
	mutex_unlock(&phi->data->mutex);
	print_msg("is thinking\n", phi);
	return (0);
}


