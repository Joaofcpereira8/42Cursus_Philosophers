/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:33 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/14 12:38:35 by jofilipe         ###   ########.fr       */
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
	return(-1);
}
