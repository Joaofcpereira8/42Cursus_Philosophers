/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:50:25 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/21 18:27:05 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if(pthread_create(&data->philos[i], NULL, &ft_routine, &data->philos[i]))
			return(error_message('c'));
		usleep(1000);
		i++;
	}
	if(pthread_create(&data->doc, NULL, &ft_doc_watch, data))
		return (error_message('c'));
}
