/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnctns2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:01:09 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/20 12:07:27 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time()
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	return ((long long)(tv.tv_sec) * 1000 + (long long)(tv.tv_usec) / 1000);
}
/* struct timeval tv is used to store the time information. */
