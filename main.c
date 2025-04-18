/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:58:09 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/12 16:27:48 by sakdil           ###   ########.fr       */
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

static void	handle_args(int argc, char ***argv, char ***original_argv, bool *x)
{
	if (argc == 2 && (!(*argv)[1][0] || is_all_spaces((*argv)[1])))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
	{
		*x = true;
		*original_argv = ft_split((*argv)[1], ' ');
		*argv = *original_argv;
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
	if (argc == 1)
		return (0);
	handle_args(argc, &argv, &original_argv, &x);
	if (x == true)
		build_stack_a(&a, argv, true);
	else
		build_stack_a(&a, argv + 1, false);
	continue_main(a, b);
	if (x == true)
		free_split(original_argv);
	return (0);
}
