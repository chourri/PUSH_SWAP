/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:53:03 by chourri           #+#    #+#             */
/*   Updated: 2024/04/21 14:33:35 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*start;
	t_node	*last;

	start = *head;
	last = last_node_in_stack(head);
	if (start->next == NULL)
		return ;
	*head = start->next;
	start->next = NULL;
	start->previous = last;
	last->next = start;
}

void	ra(t_node **a)
{
	rotate(a);
	write (1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write (1, "rb\n", 3);
}
