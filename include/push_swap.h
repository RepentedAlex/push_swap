/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:27 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/15 10:40:33 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_op
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_op;

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_mq
{
	int	len;
	int	med;
	int	q1;
	int	q3;
}		t_mq;

int		add_to_list(t_stack **stack, int num);
void	free_everything(t_stack **stack_a, t_stack **stack_b, t_mq **mq);
void	free_stack(t_stack **stack);
int		get_stack_len(t_stack *stack);
t_stack	*new_node(int num);

#endif