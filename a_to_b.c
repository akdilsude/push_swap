/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:18:57 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/08 18:56:14 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target_for_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*target_b;
	long	closest_smaller;

	while (a)
	{
		closest_smaller = -2147483648;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number
				&& current_b->number > closest_smaller)
			{
				closest_smaller = current_b->number;
				target_b = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smaller == -2147483648)
			a->target_node = find_max(b);
		else
			a->target_node = target_b;
		a = a->next;
	}
}

static void	calculate_cost_a(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_count(a);
	len_b = stack_count(b);
	while (a)
	{
		a->move_cost = a->index;
		if (!(a->above_median))
			a->move_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->move_cost += a->target_node->index;
		else
			a->move_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	find_cheapest(t_list *stack)
{
	long	lowest_value;
	t_list	*lowest_node;

	if (stack == NULL)
		return ;
	lowest_value = 2147483647;
	while (stack)
	{
		if (stack->move_cost < lowest_value)
		{
			lowest_value = stack->move_cost;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	lowest_node->cheapest = true;
}

void	ready_nodes_a(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	find_target_for_a(a, b);
	calculate_cost_a(a, b);
	find_cheapest(a);
}
