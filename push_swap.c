/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:05:57 by chourri           #+#    #+#             */
/*   Updated: 2024/04/20 22:16:05 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int nbr_args, char **args)
{
	int	i;

	i = 0;
	while (i < nbr_args)
	{
		if (!is_valid_number(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int	number_of_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	clean_and_exit(t_node **stack_a, char **args, bool error)
{
	free_stack(stack_a);
	free_word_array(args);
	if (error)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

char	**all_args(char **av)
{
	char	**ret;
	char	*all;
	int		i;

	all = NULL;
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		all = ft_strjoin(all, av[i++]);
	}
	ret = ft_split(all);
	free(all);
	return (ret);
}

void	is_empty(int ac, char **av)
{
	int		i;
	char	*trimmed;

	i = 0;
	trimmed = NULL;
	while (++i < ac)
	{
		trimmed = ft_strtrim(av[i], " ");
		if (trimmed == NULL || *trimmed == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		av[i] = trimmed;
	}
}
