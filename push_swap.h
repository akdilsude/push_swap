/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:02:33 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/15 12:32:05 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	int				number;
	int				index;
	int				move_cost;
	bool			above_median;
	bool			cheapest;
	bool			split_used;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct for_atoi
{
	int		i;
	int		err;
	long	res;
	int		sign;
	size_t	digit_count;
}				t_atoi;

t_list	*last_in_list(t_list *stack);
bool	is_stack_sorted(t_list *stack);
int		stack_count(t_list *stack);
t_list	*cheap_node(t_list *stack);
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);
void	free_errors(t_list **n, char **split_argv, bool split_used);
void	free_stack(t_list **stack);
int		is_valid_number(char *num_str);
int		check_repeated(t_list *a, int n);
char	**ft_split(char const *s, char c);
void	sa(t_list	**a, bool output);
void	sort_three(t_list **a);
void	ra(t_list **a, bool output);
void	rb(t_list **b, bool output);
void	rr(t_list **a, t_list **b, bool output);
void	rra(t_list **a, bool output);
void	rrb(t_list **b, bool output);
void	rrr(t_list **a, t_list **b, bool output);
void	current_index(t_list *stack);
void	find_cheapest(t_list *stack);
void	ready_nodes_a(t_list *a, t_list *b);
void	ready_nodes_b(t_list *a, t_list *b);
void	pa(t_list **a, t_list **b, bool output);
void	pb(t_list **b, t_list **a, bool output);
void	place_min_top(t_list **a);
void	build_stack_a(t_list **a, char **argv, bool split_used);
void	move_to_top(t_list **stack, t_list *top_node, char stack_name);
void	sort_stacks(t_list **a, t_list **b);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_split(char **split_argv);
long	ft_atoi(const char *str, t_atoi *atoii);
void	atoi_start(t_atoi *atoii, const char *str);
int		is_all_spaces(const char *str);

#endif