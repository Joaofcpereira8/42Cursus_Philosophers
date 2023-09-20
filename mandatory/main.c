/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:34:58 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/20 01:11:05 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data		*data;
	t_philos	*philos;
	
	if (argc == 5 || argc == 6)
	{
		if (check_num(argv))
			return (-1);
		philo_init(philos);
		data_init(data, argc, argv);
		/* fazer as threads e mutexes */
		/* dar join das threads */
		/* no final, dar free a tudo */
	}
	else
		printf("Check args");
	return (0);
}
