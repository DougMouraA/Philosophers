/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:05:55 by douglas           #+#    #+#             */
/*   Updated: 2023/02/24 18:43:41 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <time.h>

typedef struct philo_dinner
{
	unsigned int	num_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				num_max_eat;
	unsigned int	died;
	long long		first_time;
	pthread_mutex_t	cheack_died;
	pthread_mutex_t	*cheack_time;
	pthread_mutex_t	*cheack_eat;
	pthread_mutex_t	printf;
	pthread_mutex_t	*forks;
}					t_pd;

typedef struct info_philo
{
	int			id_philo;
	int			status;
	int			right;
	int			left;
	int			total_eat;
	long long	last_eat;
	long long	first_time;
	long long	time;
	t_pd		*for_all;
}				t_info_philo;

//Utils
long int		ft_atoi(const char *str);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);

//Checker
int				check_died(t_pd checker);
int				check_param(int argc, char **argv);
int				cheack_eat(t_info_philo *philo);

//Create
void			creat_mutex(t_pd *cmutex);
void			create_philos(int argc, char **argv, pthread_t *philo);
void			destroy_mutex(t_pd *dmutex);

//Initialize
t_pd			*init_philo(int argc, char **argv);
t_info_philo	*init_info(t_pd *philo_info);
void			get_forks(t_info_philo *philosopher);
void			eat_philo(t_info_philo *philo);

//Time
long long		get_first_time(void);
long long		time_return(long long first_time);

//Routine
void			mprint(t_info_philo philo_id, int i);
void			msleep(t_info_philo *phitime, unsigned int time);
void			*routine(void *id);
void			*murder_philos(void *id);

#endif