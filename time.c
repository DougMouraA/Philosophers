/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:53:28 by douglas           #+#    #+#             */
/*   Updated: 2023/02/24 14:53:50 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	get_first_time(void)
{
	struct timeval	first;

	gettimeofday(&first, NULL);
	return ((first.tv_sec) * 1000 + (first.tv_usec) * 0.001);
}

long long	time_return(long long first_time)
{
	struct timeval	first;
	long long		actual_time;

	gettimeofday(&first, NULL);
	actual_time = (first.tv_sec) * 1000 + (first.tv_usec) * 0.001;
	return (actual_time - first_time);
}
