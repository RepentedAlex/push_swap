/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:57:02 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/30 18:39:35 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "parsing.h"
#include "stacks.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>

void push_swap(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}

static void dump_node(int val)
{
	ft_printf("val %d\n", val);
}

void debug_stacks(t_stack *a, t_stack *b)
{
	ft_printf("Stack a:\n");
	ft_lstiter(a, dump_node);
	ft_printf("Stack b:\n");
	ft_lstiter(b, dump_node);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	// if (valid_command(argc - 1, argv) == false)
	// 	exit_handler(1);
	// stack_a = init_stack_a(argc - 1, argv);
	stack_a = ft_lstnew(1);
	stack_a->next = ft_lstnew(2);
	stack_a->next->next = ft_lstnew(3);
	stack_a->next->next->next = ft_lstnew(4);
	stack_b = ft_lstnew(1 + 4);
	stack_b->next = ft_lstnew(2 + 4);
	stack_b->next->next = ft_lstnew(3 + 4);
	stack_b->next->next->next = ft_lstnew(4 + 4);
	debug_stacks(stack_a, stack_b);
	// ft_printf("\033[0;93mSWAPS\033[0;39m\n");
	// swap(stack_a, stack_b, sa);
	// debug_stacks(stack_a, stack_b);
	// swap(stack_a, stack_b, sb);
	// debug_stacks(stack_a, stack_b);
	// swap(stack_a, stack_b, ss);
	// debug_stacks(stack_a, stack_b);
	// ft_printf("\n");
	// ft_printf("\033[0;93mROTATIONS\033[0;39m\n");
	// rotate(&stack_a, &stack_b, ra);
	// debug_stacks(stack_a, stack_b);
	// rotate(&stack_a, &stack_b, rb);
	// debug_stacks(stack_a, stack_b);
	// rotate(&stack_a, &stack_b, rr);
	// debug_stacks(stack_a, stack_b);
	ft_printf("\033[0;93mREVERSE ROTATIONS\033[0;39m\n");
	reverse_rotate(&stack_a, &stack_b, rra);
	debug_stacks(stack_a, stack_b);
	reverse_rotate(&stack_a, &stack_b, rrb);
	debug_stacks(stack_a, stack_b);
	reverse_rotate(&stack_a, &stack_b, rrr);
	debug_stacks(stack_a, stack_b);

	(void)argc;
	(void)argv;
	ft_stclear(&stack_a);
	ft_stclear(&stack_b);
	
	// (void)argv; // plus tard
	// if (argc == 1)
	// 	exit(EXIT_FAILURE);
	// while (stack_a)
	// {
	// 	ft_printf("%d", stack_a->value);
	// 	stack_a = stack_a->next;
	// }
	// push_swap(stack_a, stack_b);
	// (void)stack_a;
	// (void)stack_b;
	return (0);
}
