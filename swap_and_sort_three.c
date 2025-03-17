/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_sort_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:21 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/17 22:52:33 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	flip(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	*head = second;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
}

void	sa(t_list	**a, bool print)
{
	flip(a);
	if (print == true)
		write (1, "sa\n", 3);
}

void	sb(t_list **b, bool print)
{
	flip(b);
	if (print == true)
		write (1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, bool print)
{
	flip(a);
	flip(b);
	if (print == true)
		write (1, "ss\n", 3);
}

void	sort_three(t_list **a)
{
	t_list	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a, true);
	if ((*a)->number > (*a)->next->number)
		sa(a, true);
}
