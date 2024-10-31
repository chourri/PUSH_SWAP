/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:15:47 by chourri           #+#    #+#             */
/*   Updated: 2024/04/21 15:36:54 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack_b(t_node **a, t_node **b)
{
	int	i;
	int	range;

	if (stack_length(a) <= 100)
		range = 15;
	else
		range = 33;
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

static int	is_on_top(t_node **b)
{
	t_node	*head;
	int		count;

	head = *b;
	count = 0;
	while (head)
	{
		if (head->index == stack_length(b) - 1)
		{
			if (count < (stack_length(b) / 2))
				return (1);
			return (0);
		}
		count++;
		head = head->next;
	}
	return (0);
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	while (*b)
	{
		if ((*b)->index == (stack_length(b) - 1))
			pa(a, b);
		else
		{
			if (is_on_top(b))
				rb(b);
			else
				rrb(b);
		}
	}
}

void	sort(t_node **a, t_node **b)
{
	fill_stack_b(a, b);
	push_back_to_a(a, b);
}
