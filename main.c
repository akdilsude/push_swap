/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:58:09 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/23 15:59:21 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split_argv)
{
	int	i;

	i = 0;
	if (!split_argv)
		return ;
	i = 0;
	while (split_argv[i])
	{
		free(split_argv[i]);
		i++;
	}
	free(split_argv);
}

static void	sort_stack(t_list **a, t_list **b)
{
	if (!is_stack_sorted(*a))
	{
		if (stack_count(*a) == 2)
			sa(a, true);
		else if (stack_count(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	bool	x;

	x = false;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		x = true;
		argv = ft_split(argv[1], ' ');
	}
	if (x == true)
		build_stack_a(&a, argv);
	else
		build_stack_a(&a, argv + 1);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (x == true)
		free_split(argv);
	return (0);
}
