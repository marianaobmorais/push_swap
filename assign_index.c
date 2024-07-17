/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:21:45 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/02 19:22:27 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack **s)
{
	t_node	*tmp;
	int		index;

	tmp = (*s)->head;
	index = 0;
	while (tmp != NULL)
	{
		tmp->i = index;
		tmp->above_mid = ((*s)->size / 2 > index) || ((*s)->size == 1);
		tmp = tmp->next;
		index++;
	}
}
