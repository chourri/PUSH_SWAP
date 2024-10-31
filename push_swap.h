/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourri <chourri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:15:31 by chourri           #+#    #+#             */
/*   Updated: 2024/04/21 15:38:22 by chourri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				number;
	struct s_node	*previous;
	struct s_node	*next;
	int				index;
}	t_node;

int		is_valid_number(char *str);
int		check_dup(t_node **stack_a);
void	free_stack(t_node **stack);
void	clean_and_exit(t_node **stack_a, char **args, bool error);
void	is_empty(int ac, char **av);

t_node	*ft_lstnew(int content);
void	initialize_stack_a(char **args, t_node **stack_a);
char	**all_args(char **av);
t_node	*last_node_in_stack(t_node **stack);
int		stack_length(t_node **stack);
t_node	*max_node_number(t_node **head);
t_node	*min_node_number(t_node **head);

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t dstsize);
int		check_separator(char c);
int		count_words(char *str);
char	*ft_word(char *str);
void	free_word_array(char **array);
char	**ft_split(char *str);
long	ft_atoi(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(char *str, int c);

int		number_of_args(char **args);
int		check_args(int ac, char **av);

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	sa(t_node	**a);
void	sb(t_node	**b);

void	ra(t_node **a);
void	rb(t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);

void	select_sort_algorithm(char **args, t_node **a, t_node **b);
void	sort(t_node **a, t_node **b);

#endif
