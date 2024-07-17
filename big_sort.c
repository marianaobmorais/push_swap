/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:27:30 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/03 20:23:54 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_to_a(t_stack **s_a, t_stack **s_b)
{
	while ((*s_b)->size > 0)
	{
		assign_index(s_a);
		assign_index(s_b);
		rassign_target(&(*s_b)->head, &(*s_a)->head);
		if ((*s_b)->head->target->above_mid == true)
			while ((*s_b)->head->target->data != (*s_a)->head->data)
				rot(&(*s_a)->head, 'a');
		else
			while ((*s_b)->head->target->data != (*s_a)->head->data)
				rrot(&(*s_a)->head, 'a');
		push(s_b, s_a, 'a');
	}
}

static void	organize_a(t_stack **s_a)
{
	if (highest_node(&(*s_a)->head)->above_mid == true)
	{
		while (highest_node(&(*s_a)->head)->next != NULL)
			rot(&(*s_a)->head, 'a');
	}
	if (highest_node(&(*s_a)->head)->above_mid == false)
	{
		while (highest_node(&(*s_a)->head)->next != NULL)
			rrot(&(*s_a)->head, 'a');
	}
}

void	big_sort(t_stack **s_a)
{
	t_stack	*s_b;

	s_b = (t_stack *)malloc(sizeof(t_stack));
	if (s_b == NULL)
		return ;
	init_stack(s_b, 'b');
	push(s_a, &s_b, 'b');
	if ((*s_a)-> size > 3)
		push(s_a, &s_b, 'b');
	while ((*s_a)->size > 3)
	{
		assign_index(s_a);
		assign_index(&s_b);
		assign_target(&(*s_a)->head, &s_b->head);
		move_cheapest(s_a, &s_b);
	}
	small_sort(&(*s_a)->head, 'a');
	send_to_a(s_a, &s_b);
	organize_a(s_a);
	free_stack(&s_b);
}
