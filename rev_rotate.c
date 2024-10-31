/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:53:38 by chourri           #+#    #+#             */
/*   Updated: 2024/04/21 14:33:30 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **head)
{
	t_node	*last;

	if ((*head)->next == NULL)
		return ;
	last = last_node_in_stack(head);
	last->next = *head;
	(*head)->previous = last;
	(*head) = last;
	(*head)->previous->next = NULL;
	(*head)->previous = NULL;
}

void	rra(t_node **a)
{
	rev_rotate(a);
	write (1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	write (1, "rrb\n", 4);
}
