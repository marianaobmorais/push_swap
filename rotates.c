/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:10:32 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/04 20:12:38 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot(t_node **head, char c)
{
	t_node	*first;
	t_node	*second;
	t_node	*iter;

	first = *head;
	second = first->next;
	iter = *head;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = first;
	first->next = NULL;
	*head = second;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
	return ;
}

void	rr(t_node **head_a, t_node **head_b, char c)
{
	rot(head_a, 0);
	rot(head_b, 0);
	if (c != 0)
		ft_printf("rr\n");
}

void	rrot(t_node **head, char c)
{
	t_node	*first;
	t_node	*last;
	t_node	*iter;

	first = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	iter = *head;
	while (iter->next != last)
		iter = iter->next;
	iter->next = NULL;
	*head = last;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
	return ;
}

void	rrr(t_node **head_a, t_node **head_b, char c)
{
	rrot(head_a, 0);
	rrot(head_b, 0);
	if (c != 0)
		ft_printf("rrr\n");
	return ;
}
