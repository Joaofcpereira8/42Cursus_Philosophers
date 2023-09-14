/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:06:43 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/13 11:07:19 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(pthread_mutex_t *mutex)
{
	if(pthread_mutex_init(mutex, NULL) != 0)
		return(error_message('i'));
	return(0);
}

int	mutex_destroy(pthread_mutex_t *mutex)
{
	if(pthread_mutex_destroy(mutex) != 0)
		error_message('d');
	return(0);
}

int	mutex_lock(pthread_mutex_t *mutex)
{
	if(pthread_mutex_lock(mutex) != 0)
		error_message('l');
	return(0);
}

int	mutex_unlock(pthread_mutex_t *mutex)
{
	if(pthread_mutex_unlock(mutex) != 0)
		error_message('u');
	return(0);
}
