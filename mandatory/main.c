/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:34:58 by jofilipe          #+#    #+#             */
/*   Updated: 2023/10/20 11:29:24 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (check_num(argv))
			return (-1);
		if (structs_init(&data, argc, argv))
			return (-1);
		ft_thread(&data);
		ft_thread_join(&data);
		free(data.forks);
		free(data.philos);
	}
	else
		printf("Check args\n");
	return (0);
}
