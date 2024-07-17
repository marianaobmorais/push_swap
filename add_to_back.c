/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:12:59 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/02 19:50:28 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_back(t_stack **stack_a, int nbr)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	init_node(new_node, nbr);
	if ((*stack_a)->head == NULL)
	{
		(*stack_a)->head = new_node;
		return ;
	}
	temp = (*stack_a)->head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	(*stack_a)->size++;
	return ;
}
