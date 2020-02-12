/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 04:03:07 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:36:23 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_count_digits(t_var *index, unsigned int ui)
{
	int				i;

	i = 0;
	if (!ui && (!index->precision_sym ||
	(index->precision_sym && index->precision_val)))
		return (1);
	while (ui)
	{
		i++;
		ui /= 10;
	}
	return (i);
}

void				ft_fix_precision_4ui(unsigned int ui, t_var *index)
{
	int				i;
	int				tab[100];

	i = 0;
	if (index->precision_val > ft_count_digits(index, ui))
		while (i++ < index->precision_val - ft_count_digits(index, ui))
			ft_putchar_plus(48, 1);
	i = 0;
	if (!ui && (!index->precision_sym ||
	(index->precision_sym && index->precision_val)))
		ft_putchar_plus(48, 1);
	else
	{
		while (ui)
		{
			tab[i++] = ui % 10;
			ui /= 10;
		}
		while (--i >= 0)
			ft_putchar_plus(tab[i] + 48, 1);
	}
}

void				ft_print_u_int(t_var *index)
{
	int				i;
	int				nbr;

	i = 0;
	nbr = ft_count_digits(index, *((unsigned int *)index->ptr));
	if (index->precision_val > nbr)
		nbr = index->precision_val;
	if (index->flags[0])
	{
		ft_fix_precision_4ui(*((unsigned int *)index->ptr), index);
		while (i++ < index->min_field_width - nbr)
			ft_putchar_plus(32, 1);
	}
	else
	{
		if ((index->precision_val && index->flags[1])
		|| !index->flags[1])
			while (i++ < index->min_field_width - nbr)
				ft_putchar_plus(32, 1);
		else
			while (i++ < index->min_field_width - nbr)
				ft_putchar_plus(48, 1);
		ft_fix_precision_4ui(*((unsigned int *)index->ptr), index);
	}
}
