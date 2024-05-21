/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:27 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/21 14:49:58 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_types.h"

void	fill_mq(t_mq **mq, int len, int array[]);

void	free_everything(t_stack **stack_a, t_stack **stack_b, t_mq **mq);
void	get_mq(char **split, t_mq **mq, int *error);
void	launch_algo(t_stack **stack_a, t_stack **stack_b, t_mq *mq);
void	optimize_a(t_stack **stack_a, t_stack **stack_b, t_mq *mq);
void	optimize_b(t_stack **stack_a, t_stack **stack_b, t_mq *mq);
void	push_stack(t_stack **stack_a, t_stack **stack_b, t_op op);
void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, t_op op);
void	rotate(t_stack **stack_a, t_stack **stack_b, t_op op);
void	swap(t_stack **stack_a, t_stack **stack_b, t_op op);

char	**args_support(int argc, char *argv[]);
int		atoi_check(const char *ptr, int *error);

#endif
