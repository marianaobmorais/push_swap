/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:05:48 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/04 20:08:36 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	int				i;
	bool			above_mid;
	int				cost;
	struct s_node	*target;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}	t_stack;

int		check_args(char **av);
void	free_stack(t_stack **stack);
void	add_to_back(t_stack **stack_a, int nbr);
void	init_stack(t_stack *s, char c);
void	init_node(t_node *new_node, int nbr);
void	swap(t_node **head, char c);
void	ss(t_node **head_a, t_node **head_b, char c);
void	rot(t_node **head, char c);
void	rr(t_node **head_a, t_node **head_b, char c);
void	rrot(t_node **head, char c);
void	rrr(t_node **head_a, t_node **head_b, char c);
void	push(t_stack **sender, t_stack **getter, char c);
int		sorted(t_node **head);
void	small_sort(t_node **head, char c);
void	big_sort(t_stack **stack_a);
t_node	*highest_node(t_node **head);
t_node	*lowest_node(t_node **head);
int		highest_nbr(int nbr, t_node **head);
int		lowest_nbr(int nbr, t_node **head);
void	assign_index(t_stack **stack_a);
void	assign_target(t_node **head_a, t_node **head_b);
void	rassign_target(t_node **head_b, t_node **head_a);
void	move_cheapest(t_stack **s_a, t_stack **s_b);
t_node	*cheapest_node(t_stack **s_a, t_stack **s_b);

#endif