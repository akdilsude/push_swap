/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:30:04 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/08 19:01:36 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_errors(t_list **n, char **split_argv, bool split_used)
{
	free_stack(n);
	if (split_used)
		free_split(split_argv);
	write (1, "Error\n", 6);
	exit(1);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*curr_node;

	if (stack == NULL)
		return ;
	curr_node = *stack;
	while (curr_node)
	{
		temp = curr_node->next;
		curr_node->number = 0;
		free(curr_node);
		curr_node = temp;
	}
	*stack = NULL;
}

int	is_valid_number(char *num_str)
{
	if (!(*num_str == '+' || *num_str == '-'
			|| (*num_str >= '0' && *num_str <= '9')))
		return (1);
	if ((*num_str == '+' || *num_str == '-') && !(num_str[1] >= '0'
			&& num_str[1] <= '9'))
		return (1);
	while (*++num_str)
	{
		if (!(*num_str >= '0' && *num_str <= '9'))
			return (1);
	}
	return (0);
}

int	check_repeated(t_list *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->number == n)
			return (1);
		a = a->next;
	}
	return (0);
}
