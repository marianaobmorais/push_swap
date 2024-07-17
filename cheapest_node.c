/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:46:58 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/02 15:53:14 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*cheapest_node(t_stack **s_a, t_stack **s_b)
{
	t_node	*tmp;
	t_node	*cheapest;

	tmp = (*s_a)->head;
	while (tmp != NULL)
	{
		if (tmp->above_mid == true && tmp->target->above_mid == true)
			tmp->cost = tmp->i + tmp->target->i;
		else if (tmp->above_mid == false && tmp->target->above_mid == false)
			tmp->cost = (*s_a)->size - tmp->i + (*s_b)->size - tmp->target->i;
		else if (tmp->above_mid == true && tmp->target->above_mid == false)
			tmp->cost = tmp->i + (*s_b)->size - tmp->target->i;
		else if (tmp->above_mid == false && tmp->target->above_mid == true)
			tmp->cost = (*s_a)->size - tmp->i + tmp->target->i;
		tmp = tmp->next;
	}
	cheapest = (*s_a)->head;
	tmp = (*s_a)->head;
	while (tmp != NULL)
	{
		if (cheapest->cost > tmp->cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}
