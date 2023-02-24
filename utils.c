/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:55:04 by douglas           #+#    #+#             */
/*   Updated: 2023/02/24 14:55:05 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

long int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				signal;
	long int		output;

	signal = 1;
	i = 0;
	output = 0;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		i++;
		signal = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		output = (output * 10) + (str[i] - '0');
		if (output * signal > 2147483647 || output * signal < -2147483648)
			return (3333333333);
		i++;
	}
	return (output * signal);
}

int	ft_isdigit(int c)
{
	if (c < 0)
	{
		return (0);
	}
	else if (c < 48)
	{
		return (0);
	}
	else if (c > 57)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
