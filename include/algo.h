/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:23:48 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 16:16:44 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

#include "push_swap.h"

int		check_for_opti(t_stack **stack_a, t_stack **stack_b, int pos_a, int pos_b);
int		count_moves(t_stack *stack_a, t_stack *stack_b, int best_move);
int		get_index(t_stack *stack, int element);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_pos_to_place(t_stack *stack_a, int element);
int		inner(t_stack *stack, int q1, int q3);
void	insertion_sort(t_stack **stack_a, t_stack **stack_b, int best_move);
int		get_best_move(t_stack *stack_a, t_stack *stack_b);
void	optimize_a(t_stack *stack_a, t_stack *stack_b, t_quartiles *quartiles);
void	optimize_b(t_stack *stack_a, t_stack *stack_b, t_quartiles *quartiles);
void	replace_pile(t_stack **stack);

#endif