/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:35:39 by chourri           #+#    #+#             */
/*   Updated: 2024/04/20 14:44:51 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char *str)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * ((count_words(str) + 1)));
	while (*str)
	{
		while (*str && check_separator(*str))
			str++;
		if (*str)
		{
			array[i] = ft_word(str);
			if (!array[i])
				return (free_word_array(array), NULL);
			i++;
		}
		while (*str && !check_separator(*str))
			str++;
	}
	array[i] = NULL;
	return (array);
}
