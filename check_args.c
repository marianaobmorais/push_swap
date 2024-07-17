/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:54:26 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/02 15:50:43 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoilong(const char *nptr)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] == 32) || (nptr[i] > 8 && nptr[i] < 14))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		++i;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + nptr[i] - '0';
		++i;
	}
	return (res * sign);
}

static int	check_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] != NULL)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			return (0);
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_dup(char **av)
{
	int		i;
	int		j;
	int		nbri;
	int		nbrj;

	i = 1;
	while (av[i] != NULL)
	{
		nbri = ft_atoi(av[i]);
		j = i + 1;
		while (av[j] != NULL)
		{
			nbrj = ft_atoi(av[j]);
			if (nbri == nbrj)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_lim(char **av)
{
	int		i;

	i = 1;
	while (av[i] != NULL)
	{
		if (!(ft_atoilong(av[i]) >= INT_MIN && ft_atoilong(av[i]) <= INT_MAX))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **av)
{
	if (check_int(av) == 0 || check_lim(av) == 0 || check_dup(av) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
