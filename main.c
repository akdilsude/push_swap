/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:58:09 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/08 18:49:19 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split_argv)
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

static void	continue_main(t_list *a, t_list *b)
{
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**original_argv;
	bool	x;

	x = false;
	a = NULL;
	b = NULL;
	original_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		x = true;
		original_argv = ft_split(argv[1], ' ');
		argv = original_argv;
	}
	if (x == true)
		build_stack_a(&a, argv, true);
	else
		build_stack_a(&a, argv + 1, false);
	continue_main(a, b);
	if (x == true)
		free_split(original_argv);
	return (0);
}
