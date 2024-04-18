/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:05:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/18 19:40:25 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

t_stack	*init_stack_a(int argc, char *argv[]);
t_stack	*init_stack_b(int argc);

#endif