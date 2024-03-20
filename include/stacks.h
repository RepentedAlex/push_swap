/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:42:19 by apetitco          #+#    #+#             */
/*   Updated: 2024/03/20 21:06:58 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int					number;
	struct s_stack		*next;
}				t_stack;

t_stack	**init_a_stack(t_stack *a_stack, int *values, int argc);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);

#endif