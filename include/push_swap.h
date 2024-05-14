/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:37:28 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 17:43:01 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long long		value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef enum e_operations
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
}				t_operations;

typedef struct s_quartiles
{
	int			q1;
	int			med;
	int			q3;
	int			len;
}				t_quartiles;

int		add_to_list(t_stack **stack, int num);
int		atoi_check(const char *ptr, int *error);
void	fill_med_qua(t_quartiles **quartiles, int len, int array[]);
void	free_everything(t_stack **stack_a, t_stack **stack_b, \
t_quartiles **quartiles);
void	get_med_qua(char **split, t_quartiles **quartiles, int *error);
int		init_stack(t_stack **stack_a, char **split);
int		is_sorted(t_stack *stack);
void	launch_algo(t_stack *stack_a, t_stack *stack_b, t_quartiles *quartiles);
void	ft_lstiter(t_stack *lst, void (*f)(int));
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *stack);
int		new_node(int num, t_stack **node);
void	push_stack(t_stack **stack_a, t_stack **stack_b, \
t_operations operation);
void	quick_sort(int array[], int low, int high);
void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, \
t_operations operation);
void	rotate(t_stack **stack_a, t_stack **stack_b, t_operations operation);
void	sort_three(t_stack **stack_a, t_stack **stack_b);
void	ft_stack_clear(t_stack **stack);
void	swap(t_stack *stack_a, t_stack *stack_b, t_operations operation);
void	swap_el(int *a, int *b);

//! DEBUG !//
void	debug_stacks(t_stack *a, t_stack *b);

#endif