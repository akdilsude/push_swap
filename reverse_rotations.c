/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:44:35 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/17 22:50:03 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_list **stack)
{
	t_list	*second_last;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_in_list(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_list **a, bool output)
{
	rev_rotate(a);
	if (output == true)
		write (1, "rra\n", 4);
}

void	rrb(t_list **b, bool output)
{
	rev_rotate(b);
	if (output == true)
		write (1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, bool output)
{
	rev_rotate(a);
	rev_rotate(b);
	if (output == true)
		write (1, "rrr\n", 4);
}
