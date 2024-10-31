/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:19:32 by chourri           #+#    #+#             */
/*   Updated: 2024/04/21 13:39:04 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >= '0' && str[0] <= '9')))
		return (0);
	if ((str[0] == '-' || str[0] == '+') && !(str[1] >= '0' && str[1] <= '9'))
		return (0);
	i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(t_node **stack_a)
{
	t_node	*p1;
	t_node	*p2;
	int		count_dup;

	p1 = *stack_a;
	while (p1)
	{
		count_dup = 0;
		p2 = *stack_a;
		while (p2)
		{
			if (p1->number > p2->number)
				p1->index++;
			if (p1->number == p2->number)
				count_dup++;
			p2 = p2->next;
		}
		if (count_dup > 1)
			return (1);
		p1 = p1->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
