/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:33 by jofilipe          #+#    #+#             */
/*   Updated: 2023/10/20 11:02:07 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char c)
{
	if (c == 'i')
		ft_putstr_fd("Error initiating mutex!\n", 2);
	else if (c == 'd')
		ft_putstr_fd("Error destroying mutex!\n", 2);
	else if (c == 'l')
		ft_putstr_fd("Error locking mutex!\n", 2);
	else if (c == 'u')
		ft_putstr_fd("Error unlocking mutex!\n", 2);
	else if (c == 'c')
		ft_putstr_fd("Error creating thread!\n", 2);
	else if (c == 'j')
		ft_putstr_fd("Error joining thread!\n", 2);
	else if (c == 'n')
		ft_putstr_fd("Error! There's a characther that's not a number!\n", 2);
	return (-1);
}

int	verifs(t_data *d)
{
	if (d->num_philos == 0 || d->times_to_eat == 0)
	{
		ft_putstr_fd("Num of philosophers or times to eat must be > 0\n", 2);
		return (-1);
	}
	if (d->time_to_die < 0 || d->time_to_eat < 0 || d->time_to_sleep < 0)
	{
		ft_putstr_fd("Arguments for time must be > 0\n", 2);
		return (-1);
	}
	return (0);
}

int	verifs2(t_data *d)
{
	d->forks = forks_init(d->num_philos);
	if (!d->forks)
	{
		free (d->forks);
		return (-1);
	}
	d->philos = philo_init(d);
	if (!d->philos)
	{
		free (d->philos);
		return (-1);
	}
	return (0);
}

void	print_msg(char *msg, t_philos *p)
{
	long long	time;

	mutex_lock(&p->data->mutex);
	if (p->data->died >= 1 || &p->data->all_ate == &p->data->num_philos)
	{
		mutex_unlock(&p->data->mutex);
		return ;
	}
	mutex_unlock(&p->data->mutex);
	time = get_time() - p->data->time_start;
	mutex_lock(&p->data->print);
	printf("%lld %d %s", time, p->id, msg);
	mutex_unlock(&p->data->print);
	return ;
}

void	print_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	return ;
}
