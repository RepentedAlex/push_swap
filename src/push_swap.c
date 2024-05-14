/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:32:07 by apetitco          #+#    #+#             */
/*   Updated: 2024/05/14 16:25:44 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

/**
 * Normal
 * * Important
 * ! Deprecated
 * ? Interrogation
 * TODO: refactor
 * //Fait
 * @param myParam Parameter for this function
*/

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
	stack_b = NULL;
	if (init_stack(&stack_a, useless(argc, argv)) == 1)
		launch_algo(stack_a, stack_b, quartiles);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	free(quartiles);
	return (0);
}
