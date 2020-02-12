/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:36:52 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:35:03 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					*ft_convert_to_hex(unsigned long long ull)
{
	char			*base;
	char			tab[100];
	int				j;

	j = 0;
	base = "0123456789abcdef";
	ft_putchar_plus('0', 1);
	ft_putchar_plus('x', 1);
	if (!ull)
		ft_putchar_plus('0', 1);
	else
	{
		while (ull)
		{
			tab[j++] = base[ull % 16];
			ull /= 16;
		}
		while (--j >= 0)
			ft_putchar_plus(tab[j], 1);
	}
	return (0);
}

void				ft_print_addr(t_var *index)
{
	unsigned long long			ull;
	int							i;

	i = 2;
	ull = (unsigned long long)index->ptr;
	if (!ull)
		i++;
	while (ull)
	{
		ull /= 16;
		i++;
	}
	if (index->flags[0])
	{
		ft_convert_to_hex((unsigned long long)index->ptr);
		while (i++ < index->min_field_width)
			ft_putchar_plus(32, 1);
	}
	else
	{
		while (i++ < index->min_field_width)
			ft_putchar_plus(32, 1);
		ft_convert_to_hex((unsigned long long)index->ptr);
	}
}
