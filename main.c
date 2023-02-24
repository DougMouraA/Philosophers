/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:12:33 by douglas           #+#    #+#             */
/*   Updated: 2023/02/24 15:44:11 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	pthread_t	*philothread;
	int			numphilo;

	if (argc != 5 && argc != 6)
	{
		printf("Too few arguments! Try again.");
		return (0);
	}
	if (check_param(argc, argv) == 0)
	{
		printf("Wrong paramenters, please try again!");
		return (0);
	}
	numphilo = ft_atoi(argv[1]);
	philothread = malloc(numphilo * sizeof(pthread_t));
	if (!philothread)
		return (0);
	create_philos(argc, argv, philothread);
}
