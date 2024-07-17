/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:32:35 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/04 20:11:06 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head, char c)
{
	t_node	*first;
	t_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	return ;
}

void	ss(t_node **head_a, t_node **head_b, char c)
{
	swap(head_a, 0);
	swap(head_b, 0);
	if (c != 0)
		ft_printf("ss\n");
	return ;
}
