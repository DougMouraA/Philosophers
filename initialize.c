/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:45:24 by douglas           #+#    #+#             */
/*   Updated: 2023/02/24 15:27:30 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_pd	*init_philo(int argc, char **argv)
{
	t_pd	*philo_info;

	philo_info = malloc(sizeof(t_pd));
	philo_info->num_philo = ft_atoi(argv[1]);
	philo_info->first_time = get_first_time();
	philo_info->died = 0;
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_info->num_max_eat = ft_atoi(argv[5]);
	else
		philo_info->num_max_eat = -1;
	creat_mutex(philo_info);
	return (philo_info);
}

t_info_philo	*init_info(t_pd *philo_info)
{
	t_info_philo	*id_philo;
	unsigned int	i;

	i = 0;
	id_philo = malloc(sizeof(t_info_philo) * philo_info->num_philo);
	while (i < philo_info->num_philo)
	{
		id_philo[i].for_all = philo_info;
		id_philo[i].id_philo = i;
		id_philo[i].status = 42;
		id_philo[i].left = (id_philo->id_philo + 1) \
			% id_philo->for_all->num_philo;
		id_philo[i].right = id_philo->id_philo;
		id_philo[i].first_time = philo_info->first_time;
		id_philo[i].last_eat = 0;
		id_philo[i].total_eat = 0;
		i++;
	}
	return (id_philo);
}

void	eat_philo(t_info_philo *philo)
{
	mprint(*philo, 3);
	pthread_mutex_lock(&philo->for_all->cheack_eat[philo->id_philo]);
	philo->total_eat++;
	pthread_mutex_unlock(&philo->for_all->cheack_eat[philo->id_philo]);
	pthread_mutex_lock(&philo->for_all->cheack_time[philo->id_philo]);
	philo->last_eat = time_return(philo->first_time);
	pthread_mutex_unlock(&philo->for_all->cheack_time[philo->id_philo]);
	msleep(philo, philo->for_all->time_to_eat);
	pthread_mutex_unlock(&philo->for_all->forks[philo->left]);
	pthread_mutex_unlock(&philo->for_all->forks[philo->right]);
	philo->status = 44;
}

void	get_forks(t_info_philo *philo)
{
	pthread_mutex_lock(&philo->for_all->forks[philo->left]);
	mprint(*philo, 2);
	if (check_died(*philo->for_all) == 1)
	{
		pthread_mutex_unlock(&philo->for_all->forks[philo->left]);
		return ;
	}
	pthread_mutex_lock(&philo->for_all->forks[philo->right]);
	mprint(*philo, 2);
	if (check_died(*philo->for_all) == 1)
	{
		pthread_mutex_unlock(&philo->for_all->forks[philo->left]);
		pthread_mutex_unlock(&philo->for_all->forks[philo->right]);
		return ;
	}
	eat_philo(philo);
}
