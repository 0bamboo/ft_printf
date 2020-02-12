/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:36:38 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:36:12 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_count_digits_4i(int nbr, t_var *index)
{
	int				k;

	k = 0;
	if (!nbr && index->precision_sym && !index->precision_val)
		return (0);
	else if (!nbr)
		return (1);
	if (nbr < 0)
	{
		k++;
		nbr *= -1;
	}
	while (nbr)
	{
		k++;
		nbr /= 10;
	}
	return (k);
}

void				ft_fix_precision_4i(t_var *index, int nbr)
{
	unsigned int	ui;
	int				j;
	int				tab[100];

	j = 0;
	ui = nbr;
	if (nbr < 0)
		ui = nbr * -1;
	if (index->precision_val > ft_count_digits_4i(ui, index))
		while (j++ < index->precision_val - ft_count_digits_4i(ui, index))
			ft_putchar_plus(48, 1);
	if (!ui && (!index->precision_sym ||
	(index->precision_sym && index->precision_val)))
		ft_putchar_plus(48, 1);
	else
	{
		j = 0;
		while (ui)
		{
			tab[j++] = ui % 10;
			ui /= 10;
		}
		while (--j >= 0)
			ft_putchar_plus(tab[j] + 48, 1);
	}
}

void				ft_fix_flag_0(t_var *index, int nbr, int t_num)
{
	int				i;

	i = 0;
	if (index->precision_sym)
	{
		while (i++ < index->min_field_width - t_num)
			ft_putchar_plus(32, 1);
		if (nbr < 0)
			ft_putchar_plus(45, 1);
	}
	else
	{
		if (nbr < 0)
			ft_putchar_plus(45, 1);
		while (i++ < index->min_field_width - t_num)
			ft_putchar_plus(48, 1);
	}
}

void				ft_right_align_4i(t_var *index, int nbr, int t_num)
{
	int				i;

	i = 0;
	if (!index->flags[1])
	{
		while (i++ < (index->min_field_width - t_num))
			ft_putchar_plus(32, 1);
		if (nbr < 0)
			ft_putchar_plus(45, 1);
		ft_fix_precision_4i(index, nbr);
	}
	else
	{
		ft_fix_flag_0(index, nbr, t_num);
		ft_fix_precision_4i(index, nbr);
	}
}

void				ft_print_int(t_var *index)
{
	int					nbr;
	int					t_num;
	int					i;

	i = 0;
	nbr = *((int*)index->ptr);
	if (index->precision_val > ft_count_digits_4i(nbr, index))
	{
		t_num = index->precision_val;
		if (nbr < 0)
			t_num++;
	}
	else
		t_num = ft_count_digits_4i(nbr, index);
	if (index->flags[0])
	{
		if (nbr < 0)
			ft_putchar_plus(45, 1);
		ft_fix_precision_4i(index, nbr);
		while (i++ < index->min_field_width - t_num)
			ft_putchar_plus(32, 1);
	}
	else
		ft_right_align_4i(index, nbr, t_num);
}
