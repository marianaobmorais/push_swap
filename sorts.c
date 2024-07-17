/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:33:51 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/02 20:29:16 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	small_sort(t_node **head, char c)
{
	if ((*head)->data > (*head)->next->data
		&& (*head)->data > (*head)->next->next->data)
		rot(head, c);
	if ((*head)->data < (*head)->next->data
		&& (*head)->next->data > (*head)->next->next->data)
		rrot(head, c);
	if ((*head)->data > (*head)->next->data)
		swap(head, c);
}
