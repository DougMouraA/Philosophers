/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:15:23 by douglas           #+#    #+#             */
/*   Updated: 2023/02/25 11:49:49 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	creat_mutex(t_pd *cmutex)
{
	unsigned int	i;

	i = 0;
	cmutex->cheack_eat = malloc(sizeof(pthread_mutex_t) * cmutex->num_philo);
	cmutex->cheack_time = malloc(sizeof(pthread_mutex_t) * cmutex->num_philo);
	cmutex->forks = malloc(sizeof(pthread_mutex_t) * cmutex->num_philo);
	while (i < cmutex->num_philo)
	{
		pthread_mutex_init(&cmutex->cheack_eat[i], NULL);
		pthread_mutex_init(&cmutex->cheack_time[i], NULL);
		pthread_mutex_init(&cmutex->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&cmutex->printf, NULL);
	pthread_mutex_init(&cmutex->cheack_died, NULL);
}

void	create_philos(int argc, char **argv, pthread_t *philo)
{
	int				i;
	t_pd			*philo_info;
	t_info_philo	*id_philo;
	pthread_t		killer_thread;

	i = 0;
	philo_info = init_philo(argc, argv);
	id_philo = init_info(philo_info);
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(&philo[i], NULL, &routine, &id_philo[i]);
		i++;
	}
	pthread_create(&killer_thread, NULL, &murder_philos, id_philo);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	pthread_join(killer_thread, NULL);
	destroy_mutex(philo_info);
}

void	destroy_mutex(t_pd *dmutex)
{
	unsigned int	i;

	i = 0;
	free(dmutex->cheack_eat);
	free(dmutex->cheack_time);
	free(dmutex->forks);
	while (i < dmutex->num_philo)
	{
		pthread_mutex_destroy(&dmutex->cheack_eat[i]);
		pthread_mutex_destroy(&dmutex->cheack_time[i]);
		pthread_mutex_destroy(&dmutex->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&dmutex->printf);
	pthread_mutex_destroy(&dmutex->cheack_died);
}
