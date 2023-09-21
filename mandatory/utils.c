/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:33 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/21 15:02:38 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char c)
{
	if (c == 'i')
		ft_putstr_fd("Error initiating mutex!", 2);
	else if (c == 'd')
		ft_putstr_fd("Error destroying mutex!", 2);
	else if (c == 'l')
		ft_putstr_fd("Error locking mutex!", 2);
	else if (c == 'u')
		ft_putstr_fd("Error unlocking mutex!", 2);
	else if (c == 'c')
		ft_putstr_fd("Error creating thread!", 2);
	else if (c == 'j')
		ft_putstr_fd("Error joining thread!", 2);
	else if (c == 'n')
		ft_putstr_fd("Error! There's a characther that's not a number!", 2);
	return(-1);
}

int	verifs(t_data *data)
{
	if (data->num_philos == 0 || data->times_to_eat == 0)
	{
		ft_putstr_fd("Num of philosophers or times to eat must be more than 0", 2);
		return (-1);
	}
	if (data->time_to_die < 0 || data->time_to_eat < 0 || data->time_to_sleep < 0)
	{
		ft_putstr_fd("Arguments for time must be more than 0", 2);
		return (-1);
	}
	return (0);
}

int	verifs2(t_data *data)
{
	if (!data->philos)
	{
		free (data->philos);
		return (-1);
	}
	if (!data->forks)
	{
		free (data->forks);
		return (-1);
	}
	return (0);
}
