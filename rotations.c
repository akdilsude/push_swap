/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:32:31 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/17 22:51:38 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	last = last_in_list(*stack);
	*stack = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_list **a, bool output)
{
	rotate(a);
	if (output == true)
		write (1, "ra\n", 3);
}

void	rb(t_list **b, bool output)
{
	rotate(b);
	if (output == true)
		write (1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, bool output)
{
	rotate(a);
	rotate(b);
	if (output == true)
		write (1, "rr\n", 3);
}
