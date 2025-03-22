/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:04:44 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/22 15:22:48 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_ab(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, true);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_ab(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, true);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = cheap_node(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_ab(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_ab(a, b, cheapest_node);
	move_to_top(a, cheapest_node, 'a');
	move_to_top(b, cheapest_node->target_node, 'b');
	pb(b, a, true);
}

static void	move_b_to_a(t_list **a, t_list **b)
{
	move_to_top(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	sort_stacks(t_list **a, t_list **b)
{
	int	len_a;

	len_a = stack_count(*a);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, true);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, true);
	while (len_a-- > 3 && !is_stack_sorted(*a))
	{
		ready_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		ready_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	place_min_top(a);
}
