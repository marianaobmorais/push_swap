/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:07 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/04 20:13:03 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_case1(t_node *cheap, t_stack **s_a, t_stack **s_b)
{
	while (cheap->i > 0 && cheap->target->i > 0)
	{
		rr(&(*s_a)->head, &(*s_b)->head, 'r');
		cheap->i--;
		cheap->target->i--;
	}
	while (cheap->i > 0)
	{
		rot(&(*s_a)->head, 'a');
		cheap->i--;
	}
	while (cheap->target->i > 0)
	{
		rot(&(*s_b)->head, 'b');
		cheap->target->i--;
	}
}

static void	move_case2(t_node *cheap, t_stack **s_a, t_stack **s_b)
{
	while (cheap->i < (*s_a)->size && cheap->target->i < (*s_b)->size)
	{
		rrr(&(*s_a)->head, &(*s_b)->head, 'r');
		cheap->i++;
		cheap->target->i++;
	}
	while (cheap->i < (*s_a)->size)
	{
		rrot(&(*s_a)->head, 'a');
		cheap->i++;
	}
	while (cheap->target->i < (*s_b)->size)
	{
		rrot(&(*s_b)->head, 'b');
		cheap->target->i++;
	}
}

static void	move_case3(t_node *cheap, t_stack **s_a, t_stack **s_b)
{
	while (cheap->i < (*s_a)->size)
	{
		rrot(&(*s_a)->head, 'a');
		cheap->i++;
	}
	while (cheap->target->i > 0)
	{
		rot(&(*s_b)->head, 'b');
		cheap->target->i--;
	}
}

static void	move_case4(t_node *cheap, t_stack **s_a, t_stack **s_b)
{
	while (cheap->i > 0)
	{
		rot(&(*s_a)->head, 'a');
		cheap->i--;
	}
	while (cheap->target->i < (*s_b)->size)
	{
		rrot(&(*s_b)->head, 'b');
		cheap->target->i++;
	}
}

void	move_cheapest(t_stack **s_a, t_stack **s_b)
{
	t_node	*cheap;

	cheap = cheapest_node(s_a, s_b);
	if (cheap->above_mid == true && cheap->target->above_mid == true)
		move_case1(cheap, s_a, s_b);
	else if (cheap->above_mid == false && cheap->target->above_mid == false)
		move_case2(cheap, s_a, s_b);
	else if (cheap->above_mid == false && cheap->target->above_mid == true)
		move_case3(cheap, s_a, s_b);
	else if (cheap->above_mid == true && cheap->target->above_mid == false)
		move_case4(cheap, s_a, s_b);
	push(s_a, s_b, 'b');
}
