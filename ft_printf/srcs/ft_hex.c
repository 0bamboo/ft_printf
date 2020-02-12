/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:36:24 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:35:35 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_right_align_4x(t_var *index, char *s)
{
	int				i;

	i = 0;
	if (!index->flags[1] || index->precision_sym)
		while (i++ < index->min_field_width - ft_strlen(s))
			ft_putchar_plus(32, 1);
	else
		while (i++ < index->min_field_width - ft_strlen(s))
			ft_putchar_plus(48, 1);
	i = 0;
	while (s[i])
		ft_putchar_plus(s[i++], 1);
}

void				ft_print_hex(t_var *index, int c)
{
	char				*s;
	int					i;

	i = 0;
	s = ft_fixandconvert_to_hex(index, c);
	if (index->flags[0])
	{
		while (s[i])
			ft_putchar_plus(s[i++], 1);
		i = 0;
		while (i++ < index->min_field_width - ft_strlen(s))
			ft_putchar_plus(32, 1);
	}
	else
		ft_right_align_4x(index, s);
	free(s);
}
