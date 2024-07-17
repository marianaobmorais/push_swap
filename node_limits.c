/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_limits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:11:29 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/03 20:25:56 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*highest_node(t_node **head)
{
	t_node	*tmp;
	t_node	*highest;

	tmp = *head;
	highest = *head;
	while (tmp != NULL)
	{
		if (highest->data < tmp->data)
			highest = tmp;
		tmp = tmp->next;
	}
	return (highest);
}

t_node	*lowest_node(t_node **head)
{
	t_node	*tmp;
	t_node	*lowest;

	tmp = *head;
	lowest = *head;
	while (tmp != NULL)
	{
		if (lowest->data > tmp->data)
			lowest = tmp;
		tmp = tmp->next;
	}
	return (lowest);
}

int	highest_nbr(int nbr, t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (nbr < tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	lowest_nbr(int nbr, t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (nbr > tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
