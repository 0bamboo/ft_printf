/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:36:16 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:34:44 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_print_char(t_var *index)
{
	int				i;

	i = 1;
	if (index->flags[0])
	{
		ft_putchar_plus(*(int*)index->ptr, 1);
		while (i++ < index->min_field_width)
			ft_putchar_plus(32, 1);
	}
	else
	{
		if (index->flags[1])
			while (i++ < index->min_field_width)
				ft_putchar_plus(48, 1);
		else
			while (i++ < index->min_field_width)
				ft_putchar_plus(32, 1);
		ft_putchar_plus(*(int*)index->ptr, 1);
	}
}
