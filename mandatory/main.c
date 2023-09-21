/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:34:58 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/21 18:27:27 by jofilipe         ###   ########.fr       */
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
		if(structs_init(data, argc, argv))
			return (-1);
		ft_thread(data);
		/* dar join das threads */
		/* no final, dar free a tudo */
	}
	else
		printf("Check args");
	return (0);
}
