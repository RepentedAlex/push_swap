/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:27 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/20 15:17:13 by apetitco         ###   ########.fr       */
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
char	**args_support(int argc, char *argv[]);
int		atoi_check(const char *ptr, int *error);
void	debug_stacks(t_stack *a, t_stack *b);
void	fill_mq(t_mq **mq, int len, int array[]);
void	free_everything(t_stack **stack_a, t_stack **stack_b, t_mq **mq);
void	free_stack(t_stack **stack);
int		get_best_move(t_stack **stack_a, t_stack **stack_b);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
void	get_mq(char **split, t_mq **mq, int *error);
int		get_stack_len(t_stack *stack);
int		init_stack(t_stack **stack_a, char **split, t_stack **stack_b);
void	insertion_sort(t_stack **stack_a, t_stack **stack_b, t_mq **mq);
void	launch_algo(t_stack **stack_a, t_stack **stack_b, t_mq *mq);
t_stack	*new_node(int num);
void	optimize_a(t_stack **stack_a, t_stack **stack_b, t_mq *mq);
void	optimize_b(t_stack **stack_a, t_stack **stack_b, t_mq *mq);
void	push_stack(t_stack **stack_a, t_stack **stack_b, t_op op);
void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, t_op op);
void	rotate(t_stack **stack_a, t_stack **stack_b, t_op op);
void	swap(t_stack **stack_a, t_stack **stack_b, t_op op);

#endif
