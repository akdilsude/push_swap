/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:18:53 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/08 19:03:47 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_count(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	find_target_for_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target_a;
	long	closest_larger;

	while (b)
	{
		closest_larger = 2147483647;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
				&& current_a->number < closest_larger)
			{
				closest_larger = current_a->number;
				target_a = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_larger == 2147483647)
			b->target_node = find_min(a);
		else
			b->target_node = target_a;
		b = b->next;
	}
}

void	ready_nodes_b(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	find_target_for_b(a, b);
}

t_list	*cheap_node(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
