/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:48:21 by chourri           #+#    #+#             */
/*   Updated: 2024/04/20 22:24:44 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	is_empty(ac, av);
	args = all_args(av);
	if (check_args(number_of_args(args), args))
		clean_and_exit(&stack_a, args, true);
	initialize_stack_a(args, &stack_a);
	if (check_dup(&stack_a))
		clean_and_exit(&stack_a, args, true);
	select_sort_algorithm(args, &stack_a, &stack_b);
	clean_and_exit(&stack_a, args, false);
	return (0);
}
