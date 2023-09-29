/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:34:58 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/29 12:42:58 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (!check_num(argv))
			return (0);
		if(!structs_init(&data, argc, argv))
			return (0);
		ft_thread(&data);
		ft_thread_join(&data);
		free(data.forks);
		free(data.philos);
	}
	else
		printf("Check args");
	return (0);
}
