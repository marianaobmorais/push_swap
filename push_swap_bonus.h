/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:05:48 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/04 18:48:45 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"

void	execute_command(char *line, t_stack **s_a, t_stack **s_b);
void	process_instructions(t_stack **s_a, t_stack **s_b);
int		accepted_command(char *line);

#endif