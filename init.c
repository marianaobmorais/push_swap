/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:01:12 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/02 15:57:01 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s, char c)
{
	s->head = NULL;
	s->size = 0;
	if (c == 'a')
		s->size = 1;
}

void	init_node(t_node *new_node, int nbr)
{
	new_node->data = nbr;
	new_node->next = NULL;
	new_node->i = 0;
	new_node->above_mid = false;
	new_node->cost = 0;
	new_node->target = NULL;
}
