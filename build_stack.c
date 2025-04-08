/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:19:23 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/08 19:03:40 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

static void	add_node(t_list **stack, int n)
{
	t_list	*node;
	t_list	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->number = n;
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

static void	continue_build_a(long n, t_list **a, char **argv, bool split_used)
{
	if (n > 2147483647 || n < -2147483648)
	{
		if (split_used)
			free_errors(a, argv, split_used);
		else
			free_errors(a, NULL, split_used);
		return ;
	}
	if (check_repeated(*a, (int)n))
	{
		if (split_used)
			free_errors(a, argv, split_used);
		else
			free_errors(a, NULL, split_used);
		return ;
	}
}

void	build_stack_a(t_list **a, char **argv, bool split_used)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (is_valid_number(argv[i]))
		{
			if (split_used)
				free_errors(a, argv, split_used);
			else
				free_errors(a, NULL, split_used);
			return ;
		}
		n = ft_atoi(argv[i]);
		continue_build_a(n, a, argv, split_used);
		add_node(a, (int)n);
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
