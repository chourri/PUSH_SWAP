/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:33:56 by chourri           #+#    #+#             */
/*   Updated: 2024/04/21 15:30:15 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node **head)
{
	t_node	*begin;

	begin = *head;
	while (begin->next)
	{
		if (begin->number > begin->next->number)
			return (0);
		begin = begin->next;
	}
	return (1);
}

static void	sort_three_algorithm(t_node **head)
{
	t_node	*begin;
	t_node	*last;

	begin = *head;
	last = last_node_in_stack(head);
	if ((begin->number > begin->next->number) && (begin->number < last->number))
		sa(head);
	else if ((begin->number > begin->next->number)
		&& (begin->next->number > last->number))
	{
		sa(head);
		rra(head);
	}
	else if ((begin->number > last->number)
		&& (last->previous->number < last->number))
		ra(head);
	else if ((last->number > begin->number)
		&& (last->number < begin->next->number))
	{
		sa(head);
		ra(head);
	}
	else if (begin->number < begin->next->number
		&& last->number < begin->number)
		rra(head);
}

static void	sort_four_algorithm(t_node **a, t_node **b)
{
	if (((*a) == max_node_number(a) || (*a) == min_node_number(a)))
		pb(a, b);
	else
	{
		ra(a);
		sort_four_algorithm(a, b);
		return ;
	}
	sort_three_algorithm(a);
	pa(a, b);
	if ((*a)->next->number < (*a)->number)
		ra(a);
}

static void	sort_five_algorithm(t_node **a, t_node **b)
{
	if (((*a) == max_node_number(a) || (*a) == min_node_number(a)))
		pb(a, b);
	else
	{
		ra(a);
		sort_five_algorithm(a, b);
		return ;
	}
	sort_four_algorithm(a, b);
	pa(a, b);
	if ((*a)->next->number < (*a)->number)
		ra(a);
}

void	select_sort_algorithm(char **args, t_node **a, t_node **b)
{
	int	nbr_args;

	if (is_sorted(a))
		return ;
	nbr_args = number_of_args(args);
	if (nbr_args == 1)
		return ;
	else if (nbr_args == 2)
	{
		if (!is_sorted(a))
			sa (a);
	}
	else if (nbr_args == 3)
		sort_three_algorithm(a);
	else if (nbr_args == 4)
		sort_four_algorithm(a, b);
	else if (nbr_args == 5)
		sort_five_algorithm(a, b);
	else
		sort(a, b);
}
