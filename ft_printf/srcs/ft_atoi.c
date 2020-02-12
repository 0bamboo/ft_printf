/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:36:09 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/19 04:16:01 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_atoi(const char *s)
{
	int			i;
	int			sign;
	int			nbr;

	nbr = 0;
	i = 0;
	sign = 1;
	while (s[i] == '\t' || s[i] == '\f' || s[i] == '\n'
			|| s[i] == '\v' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
			break ;
		nbr = (nbr * 10) + s[i] - 48;
		i++;
	}
	return (nbr * sign);
}