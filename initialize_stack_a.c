/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:12:32 by chourri           #+#    #+#             */
/*   Updated: 2024/04/21 15:26:22 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*element;

	element = (t_node *)malloc(sizeof(t_node));
	if (!element)
		return (NULL);
	element->number = content;
	element->next = NULL;
	element->previous = NULL;
	element->index = 0;
	return (element);
}

static void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*p;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	new->previous = p;
}

void	initialize_stack_a(char **args, t_node **stack_a)
{
	int		i;

	i = 0;
	while (args[i])
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(args[i++])));
}
