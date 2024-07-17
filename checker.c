/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:59:20 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/04 20:08:41 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	execute_command(char *line, t_stack **s_a, t_stack **s_b)
{
	if (ft_strcmp(line, "sa\n") == 0 && (*s_a)->head != NULL)
		swap(&(*s_a)->head, 0);
	else if (ft_strcmp(line, "sb\n") == 0 && (*s_b)->head != NULL)
		swap(&(*s_b)->head, 0);
	else if (ft_strcmp(line, "ss\n") == 0
		&& ((*s_a)->head != NULL && (*s_b)->head != NULL))
		ss(&(*s_a)->head, &(*s_b)->head, 0);
	else if (ft_strcmp(line, "pa\n") == 0 && (*s_b)->head != NULL)
		push(&(*s_b), &(*s_a), 0);
	else if (ft_strcmp(line, "pb\n") == 0 && (*s_a)->head != NULL)
		push(&(*s_a), &(*s_b), 0);
	else if (ft_strcmp(line, "ra\n") == 0 && (*s_a)->head != NULL)
		rot(&(*s_a)->head, 0);
	else if (ft_strcmp(line, "rb\n") == 0 && (*s_b)->head != NULL)
		rot(&(*s_b)->head, 0);
	else if (ft_strcmp(line, "rr\n") == 0
		&& ((*s_a)->head != NULL && (*s_b)->head != NULL))
		rr(&(*s_a)->head, &(*s_b)->head, 0);
	else if (ft_strcmp(line, "rra\n") == 0 && (*s_a)->head != NULL)
		rrot(&(*s_a)->head, 0);
	else if (ft_strcmp(line, "rrb\n") == 0 && (*s_b)->head != NULL)
		rrot(&(*s_b)->head, 0);
	else if (ft_strcmp(line, "rrr\n") == 0
		&& ((*s_a)->head != NULL && (*s_b)->head != NULL))
		rrr(&(*s_a)->head, &(*s_b)->head, 0);
}

int	accepted_command(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
		|| ft_strcmp(line, "ss\n") == 0 || ft_strcmp(line, "pa\n") == 0
		|| ft_strcmp(line, "pb\n") == 0 || ft_strcmp(line, "ra\n") == 0
		|| ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rr\n") == 0
		|| ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0
		|| ft_strcmp(line, "rrr\n") == 0)
		return (1);
	else
		return (0);
}

void	process_instructions(t_stack **s_a, t_stack **s_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!accepted_command(line))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(s_a);
			free_stack(s_b);
			free(line);
			exit(EXIT_FAILURE);
		}
		execute_command(line, s_a, s_b);
		free(line);
		line = get_next_line(0);
	}
	if ((*s_a)->size > 0 && sorted(&(*s_a)->head) && (*s_b)->size == 0)
		ft_printf("OK");
	else
		ft_printf("KO");
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*s_a;
	t_stack	*s_b;

	if (ac < 2)
		return (0);
	if (!check_args(av))
		return (1);
	s_a = (t_stack *)malloc(sizeof(t_stack));
	if (s_a == NULL)
		return (1);
	s_b = (t_stack *)malloc(sizeof(t_stack));
	if (s_b == NULL)
		return (1);
	init_stack(s_a, 'a');
	init_stack(s_b, 'b');
	i = 1;
	while (i < ac)
		add_to_back(&s_a, ft_atoi(av[i++]));
	process_instructions(&s_a, &s_b);
	free_stack(&s_a);
	free_stack(&s_b);
	return (0);
}
