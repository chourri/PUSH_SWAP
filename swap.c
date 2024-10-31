/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:52:27 by chourri           #+#    #+#             */
/*   Updated: 2024/04/21 14:33:57 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **head)
{
	int	temp;

	temp = (*head)->number;
	(*head)->number = (*head)->next->number;
	(*head)->next->number = temp;
}

void	sa(t_node **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write (1, "sb\n", 3);
}
