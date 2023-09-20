/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:33 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/20 01:03:43 by jofilipe         ###   ########.fr       */
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
