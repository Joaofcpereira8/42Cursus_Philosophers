/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:50:25 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/14 12:40:17 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_init(pthread_t *thread)
{
	if (pthread_create(thread, NULL, &FUNCAO_PRINCIPAL, NULL))
		return(error_message('c'));
	return(0);
}

int	thread_join(pthread_t *thread)
{
	if (pthread_join(thread, NULL))
		return(error_message('j'));
	return(0);
}
