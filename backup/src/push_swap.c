/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:32:07 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 17:36:02 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	init_stack(t_stack **stack_a, char **split)
{
	int	i;
	int	j;

	i = 0;
	stack_a = NULL;
	if (!split)
		return (-1);
	while (split[i])
		i++;
	while (--i >= 0)
	{
		j = add_to_list(stack_a, ft_atoi(split[i]));
		if (j == -1)
			return (-1);
		free(split[i]);
	}
	free(split);
	return (1);
}

void	launch_algo(t_stack *stack_a, t_stack *stack_b, t_quartiles *quartiles)
{
	if (quartiles->len == 2 && stack_a->value > stack_a->next->value)
		write(1, "sa\n", 3);
	if (quartiles->len > 2 && !is_sorted(stack_a))
		optimize_b(stack_a, stack_b, quartiles);
	free_everything(&stack_a, &stack_b, &quartiles);
	exit(1);
}

static int	split_len(char **split)
{
	int	i;

	i = -1;
	if (!split)
		return (-1);
	while (split[++i])
		free(split[i]);
	free(split);
	return (i);
}

static char	**useless(int argc, char *argv[])
{
	char	**ret;
	int		i;

	if (argc > 2)
	{
		i = 0;
		ret = malloc(sizeof(char *) * argc);
		while (++i < argc)
		{
			if (split_len(ft_split(argv[i], ' ')) != 1 || !ret)
			{
				i++;
				while (--i != 0 || ret != NULL)
					free(ret[i]);
				free(ret);
				return (NULL);
			}
			ret[i - 1] = ft_strdup(argv[i]);
		}
		ret[argc - 1] = NULL;
		return (ret);
	}
	else if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int			error;
	t_quartiles	*quartiles;
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc == 1)
		exit(1);
	quartiles = malloc(sizeof(t_quartiles));
	if (!quartiles)
		return (1);
	error = 0;
	get_med_qua(useless(argc, argv), &quartiles, &error);
	if (error || quartiles->len == 0 || !quartiles)
	{
		write(2, "Error\n", 6);
		if (quartiles)
			free(quartiles);
		return (1);
	}
	if (init_stack(&stack_a, useless(argc, argv)) == 1)
		launch_algo(stack_a, stack_b, quartiles);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	free(quartiles);
	return (0);
}
