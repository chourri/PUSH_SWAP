/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:19:39 by chourri           #+#    #+#             */
/*   Updated: 2024/04/15 22:44:51 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*last_node_in_stack(t_node **head)
{
	t_node	*current;

	if (!(*head))
		return (NULL);
	current = *head;
	while (current->next)
		current = current->next;
	return (current);
}

int	stack_length(t_node **stack)
{
	t_node	*head;
	int		i;

	head = *stack;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_node	*max_node_number(t_node **head)
{
	t_node	*begin;
	t_node	*max;

	begin = *head;
	max = *head;
	while (begin)
	{
		if ((begin)->number > max->number)
			max = begin;
		(begin) = (begin)->next;
	}
	return (max);
}

t_node	*min_node_number(t_node **head)
{
	t_node	*begin;
	t_node	*min;

	begin = *head;
	min = *head;
	while (begin)
	{
		if ((begin)->number < min->number)
			min = begin;
		(begin) = (begin)->next;
	}
	return (min);
}
