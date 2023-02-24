/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:40 by douglas           #+#    #+#             */
/*   Updated: 2023/02/24 18:52:16 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	mprint(t_info_philo philo_id, int i)
{
	pthread_mutex_lock(&philo_id.for_all->printf);
	if ((check_died(*philo_id.for_all) == 0))
	{
		if (i == 1)
			printf("%lld %d IS THINKING\n", time_return(philo_id.first_time),
				philo_id.id_philo + 1);
		else if (i == 2)
			printf("%lld %d PICKING UP A FORK\n", \
			time_return(philo_id.first_time),
				philo_id.id_philo + 1);
		else if (i == 3)
			printf("%lld %d IS EATING\n", time_return(philo_id.first_time), \
				philo_id.id_philo + 1);
		else if (i == 4)
			printf("%lld %d IS SLEEPING\n", time_return(philo_id.first_time), \
				philo_id.id_philo + 1);
	}
	pthread_mutex_unlock(&philo_id.for_all->printf);
}

void	msleep(t_info_philo *phitime, unsigned int time)
{
	phitime->time = time_return(phitime->first_time);
	while (time_return(phitime->first_time) - phitime->time < time)
	{
		usleep(100);
		if (check_died(*phitime->for_all) == 1)
			return ;
	}
}

static void	while_rotine(t_info_philo *philo_id)
{
	while (check_died(*philo_id->for_all) == 0)
	{
		if (philo_id->status == 42 && check_died(*philo_id->for_all) == 0)
		{
			mprint(*philo_id, 1);
			philo_id->status = 43;
		}
		if (philo_id->status == 43 && check_died(*philo_id->for_all) == 0)
		{
			get_forks(philo_id);
		}
		if (philo_id->status == 44 && check_died(*philo_id->for_all) == 0)
		{
			mprint(*philo_id, 4);
			msleep(philo_id, philo_id->for_all->time_to_sleep);
			philo_id->status = 42;
		}
	}
}

void	*routine(void *id)
{
	t_info_philo	*philo_id;

	philo_id = (t_info_philo *)id;
	if (philo_id->id_philo % 2 == 1)
	{
		if (philo_id->for_all->time_to_die < philo_id->for_all->time_to_eat)
			usleep(philo_id->for_all->time_to_die);
		else
			usleep(philo_id->for_all->time_to_eat);
	}
	while_rotine(philo_id);
	return (NULL);
}
