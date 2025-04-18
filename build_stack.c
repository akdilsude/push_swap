/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:19:23 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/15 12:28:46 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	continue_add_node(t_list **stack, t_list *node)
{
	t_list	*last_node;

	if ((*stack) == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = last_in_list(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

static void	add_node(t_list **stack, int n, char **argv, bool split_used)
{
	t_list	*node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		free_errors(stack, argv, split_used);
	node->number = n;
	node->index = 0;
	node->move_cost = 0;
	node->above_median = false;
	node->cheapest = false;
	node->split_used = split_used;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
	continue_add_node(stack, node);
}

static void	exit_error(t_list **a, char **argv, bool split_used)
{
	if (split_used)
		free_errors(a, argv, split_used);
	else
		free_errors(a, NULL, split_used);
}

void	build_stack_a(t_list **a, char **argv, bool split_used)
{
	long	n;
	int		i;
	t_atoi	atoii;

	i = 0;
	while (argv[i])
	{
		if (is_valid_number(argv[i]))
			exit_error(a, argv, split_used);
		n = ft_atoi(argv[i], &atoii);
		if (atoii.err || check_repeated(*a, (int)n))
			exit_error(a, argv, split_used);
		add_node(a, (int)n, argv, split_used);
		i++;
	}
}

void	move_to_top(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else if (!top_node->above_median)
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else if (!top_node->above_median)
				rrb(stack, true);
		}
	}
}
