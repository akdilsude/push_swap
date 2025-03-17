/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:11:58 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/17 16:59:23 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*last_in_list(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	is_stack_sorted(t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_count(t_list *stack)
{
	int	count;

	count = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_list	*find_min(t_list *stack)
{
	long	min;
	t_list	*min_node;

	min = LONG_MAX;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_list	*find_max(t_list *stack)
{
	long	max;
	t_list	*max_node;

	max = LONG_MIN;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
