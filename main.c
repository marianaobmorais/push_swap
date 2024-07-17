/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:04:42 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/04 19:09:11 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*s_a;

	if (ac < 2)
		return (0);
	if (!check_args(av))
		return (1);
	s_a = (t_stack *)malloc(sizeof(t_stack));
	if (s_a == NULL)
		return (1);
	init_stack(s_a, 'a');
	i = 1;
	while (i < ac)
		add_to_back(&s_a, ft_atoi(av[i++]));
	if (!sorted(&s_a->head))
	{
		if (ac == 3)
			swap (&s_a->head, 'a');
		else if (ac == 4)
			small_sort(&s_a->head, 'a');
		else
			big_sort(&s_a);
	}
	free_stack(&s_a);
	return (0);
}
