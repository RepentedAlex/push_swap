/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:05:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/30 18:32:24 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <unistd.h>
# include "push_swap.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

int		ft_lstsize(t_stack *stack);
t_stack	*init_stack_a(int argc, char *argv[]);
t_stack	*init_stack_b(int argc);
void	swap(t_stack *stack_a, t_stack *stack_b, t_operations operations);
void	push(t_stack *stack_a, t_stack *stack_b, t_operations operations);
void	rotate(t_stack **stack_a, t_stack **stack_b, t_operations operations);
void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, t_operations operations);
void	push_swap(t_stack *a, t_stack *b);

void	ft_lstiter(t_stack *lst, void (*f)(int));
t_stack	*ft_lstnew(int content);
void	ft_stclear(t_stack **lst);
t_stack	*ft_lstlast(t_stack *lst);

#endif