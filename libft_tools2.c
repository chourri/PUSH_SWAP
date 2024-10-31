/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:57:02 by chourri           #+#    #+#             */
/*   Updated: 2024/04/21 14:36:11 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		j;

	i = -1;
	if (!s1)
		return (ft_strdup(s2));
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!new_s)
		exit(1);
	while (s1[++i])
		new_s[i] = s1[i];
	new_s[i++] = ' ';
	j = 0;
	while (s2[j])
		new_s[i++] = s2[j++];
	new_s[i] = '\0';
	if (s1)
		free((char *)s1);
	return (new_s);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char )c)
			return ((char *)(str + i));
		i++;
	}
	if ((char )c == '\0')
		return (str + i);
	return (NULL);
}

char	*ft_strtrim(char *s1, char *set)
{
	char		*start;
	char		*end;
	char		*buffer;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *(end - 1)))
		end--;
	buffer = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, start, end - start + 1);
	return (buffer);
}
