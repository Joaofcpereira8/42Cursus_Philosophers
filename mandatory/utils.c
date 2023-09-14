/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:38:33 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/13 10:52:47 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char c)
{
	if (c == 'i')
		ft_putstr_fd("Error initiating mutex!", 2);
	if (c == 'd')
		ft_putstr_fd("Error destroying mutex!", 2);
	if (c == 'l')
		ft_putstr_fd("Error locking mutex!", 2);
	if (c == 'u')
		ft_putstr_fd("Error unlocking mutex!", 2);
	return(-1);
}
