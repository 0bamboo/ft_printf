/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:37:12 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:35:53 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_fix_precision_4s(char **str, int *nbr, t_var *index)
{
	*str = index->ptr;
	if (index->precision_sym && !index->precision_val)
		*str = "";
	if (!*str)
		*str = "(null)";
	if (index->precision_val && index->precision_val < ft_strlen(*str))
		*nbr = index->precision_val;
	else
		*nbr = ft_strlen(*str);
}

void					ft_print_string(t_var *index)
{
	char			*str;
	int				i;
	int				nbr;

	i = 0;
	ft_fix_precision_4s(&str, &nbr, index);
	if (index->flags[0])
	{
		while (i < nbr)
			ft_putchar_plus(str[i++], 1);
		while (i++ < index->min_field_width)
			ft_putchar_plus(32, 1);
	}
	else
	{
		if (!index->flags[1])
			while (i++ < index->min_field_width - nbr)
				ft_putchar_plus(32, 1);
		else
			while (i++ < index->min_field_width - nbr)
				ft_putchar_plus(48, 1);
		i = 0;
		while (i < nbr)
			ft_putchar_plus(str[i++], 1);
	}
}
