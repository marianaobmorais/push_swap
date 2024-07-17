/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:50:05 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/02 20:24:04 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_target(t_node **head_a, t_node **head_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = *head_a;
	while (tmp_a != NULL)
	{
		tmp_b = *head_b;
		tmp_a->target = lowest_node(head_b);
		while (tmp_b != NULL)
		{
			if (lowest_nbr(tmp_a->data, head_b))
			{
				tmp_a->target = highest_node(head_b);
				break ;
			}
			else if (tmp_a->data > tmp_b->data
				&& (tmp_a->target == NULL
					|| tmp_b->data > tmp_a->target->data))
				tmp_a->target = tmp_b;
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
}

void	rassign_target(t_node **head_b, t_node **head_a)
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	tmp_b = *head_b;
	while (tmp_b != NULL)
	{
		tmp_a = *head_a;
		tmp_b->target = highest_node(head_a);
		while (tmp_a != NULL)
		{
			if (highest_nbr(tmp_b->data, head_a))
			{
				tmp_b->target = lowest_node(head_a);
				break ;
			}
			else if (tmp_b->data < tmp_a->data
				&& (tmp_b->target == NULL
					|| tmp_a->data < tmp_b->target->data))
				tmp_b->target = tmp_a;
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}
