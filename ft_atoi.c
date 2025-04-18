/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:26:09 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/12 18:56:33 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atoi_start(t_atoi *atoii, const char *str)
{
	atoii->i = 0;
	atoii->res = 0;
	atoii->sign = 1;
	atoii->digit_count = 0;
	atoii->err = 0;
	while ((str[atoii->i] >= 9 && str[atoii->i] <= 13) || str[atoii->i] == ' ')
		atoii->i++;
	if (str[atoii->i] == '-' || str[atoii->i] == '+')
	{
		if (str[atoii->i] == '-')
			atoii->sign *= -1;
		atoii->i++;
	}
}

long	ft_atoi(const char *str, t_atoi *atoii)
{
	atoi_start(atoii, str);
	while (str[atoii->i] == '0' && str[atoii->i + 1] != '\0')
		atoii->i++;
	while (str[atoii->i] >= '0' && str[atoii->i] <= '9')
	{
		atoii->digit_count++;
		if (atoii->digit_count > 10 || (atoii->sign == 1 && atoii->res
				> (2147483647 - (str[atoii->i] - '0')) / 10)
			|| (atoii->sign == -1 && atoii->res
				> (2147483648 - (str[atoii->i] - '0')) / 10))
		{
			atoii->err = 1;
			return (0);
		}
		atoii->res = atoii->res * 10 + (str[atoii->i] - '0');
		atoii->i++;
	}
	if (str[atoii->i] != '\0')
	{
		atoii->err = 1;
		return (0);
	}
	return (atoii->res * atoii->sign);
}

int	is_all_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
