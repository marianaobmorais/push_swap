/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:32:35 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/03 20:25:43 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **sender, t_stack **getter, char c)
{
	t_node	*node_sender;

	if ((*sender)->head == NULL)
		return ;
	node_sender = (*sender)->head;
	(*sender)->head = node_sender->next;
	node_sender->next = (*getter)->head;
	(*getter)->head = node_sender;
	if (*sender != NULL)
		(*sender)->size--;
	(*getter)->size++;
	if (c == 'a' || c == 'b')
		ft_printf("p%c\n", c);
	return ;
}
