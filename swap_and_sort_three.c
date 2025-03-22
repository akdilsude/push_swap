/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_sort_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:21 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/22 15:18:28 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	flip(t_list **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
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
