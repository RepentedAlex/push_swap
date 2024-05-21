/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:44:26 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/21 14:49:35 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_FUNCS_H
# define STACK_FUNCS_H

#include "push_swap_types.h"

int		add_to_list(t_stack **stack, int num);
void	debug_stacks(t_stack *a, t_stack *b);
void	free_stack(t_stack **stack);
int		get_best_move(t_stack **stack_a, t_stack **stack_b);
int		get_index(t_stack **stack, int elem);
int		get_max(t_stack **stack);
int		get_min(t_stack **stack);
int		get_pos_to_place(t_stack **stack, int elem);
int		get_stack_len(t_stack **stack);
int		init_stack(t_stack **stack_a, char **split, t_stack **stack_b);
void	insertion_sort(t_stack **stack_a, t_stack **stack_b, int best_move);
t_stack	*new_node(int num);

#endif