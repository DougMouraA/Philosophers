/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:02:10 by douglas           #+#    #+#             */
/*   Updated: 2023/02/24 18:14:25 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"



void	*murder_philos(void *id)
{
	t_info_philo	*philos;
	unsigned int	i;

	philos = (t_info_philo *)id;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philos[0].for_all->cheack_time[i]);
		if (time_return(philos[0].for_all->first_time) - philos[i].last_eat > philos[0].for_all->time_to_die)
		{
			pthread_mutex_unlock(&philos[0].for_all->cheack_time[i]);
			pthread_mutex_lock(&philos[0].for_all->cheack_died);
			philos[0].for_all->died = 1;
			//printf("%lld %d IS DEAD\n", time_return(philos[0].for_all->first_time), i + 1);
			mprint(*philos, 5);
			pthread_mutex_unlock(&philos[0].for_all->cheack_died);
			return (NULL);
		}
		pthread_mutex_unlock(&philos[0].for_all->cheack_time[i]);
		if (cheack_eat(philos) == 1)
		{
			pthread_mutex_lock(&philos[0].for_all->cheack_died);
			philos[0].for_all->died = 1;
			printf("Finished eating\n");
			pthread_mutex_unlock(&philos[0].for_all->cheack_died);
			return (NULL);
		}
		i++;
		i = i % philos[0].for_all->num_philo;
	}
	return (NULL);
}
