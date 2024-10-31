/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:51:55 by chourri           #+#    #+#             */
/*   Updated: 2024/04/20 22:13:35 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*node_to_push;

	if (! *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	node_to_push->previous = NULL;
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		(*dst)->previous = node_to_push;
		*dst = node_to_push;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	write (1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	write (1, "pb\n", 3);
}
