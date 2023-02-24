/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:13:37 by douglas           #+#    #+#             */
/*   Updated: 2023/02/24 18:54:24 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_died(t_pd checker)
{
	pthread_mutex_lock(&checker.cheack_died);
	if (checker.died == 0)
	{
		pthread_mutex_unlock(&checker.cheack_died);
		return (0);
	}
	pthread_mutex_unlock(&checker.cheack_died);
	return (1);
}

int	check_param(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		if ((ft_atoi(argv[i]) < 1))
			return (0);
		i++;
	}
	return (1);
}

int	cheack_eat(t_info_philo *philo)
{
	unsigned int	i;

	if (philo->for_all->num_max_eat < 0)
		return (0);
	i = 0;
	while (i < philo->for_all->num_philo)
	{
		pthread_mutex_lock(&philo->for_all->cheack_eat[i]);
		if (philo[i].total_eat < philo->for_all->num_max_eat)
		{
			pthread_mutex_unlock(&philo->for_all->cheack_eat[i]);
			return (0);
		}
		pthread_mutex_unlock(&philo->for_all->cheack_eat[i]);
		i++;
	}
	pthread_mutex_lock(&philo[0].for_all->cheack_died);
	philo[0].for_all->died = 1;
	printf("FINISHED\n");
	pthread_mutex_unlock(&philo[0].for_all->cheack_died);
	return (1);
}
