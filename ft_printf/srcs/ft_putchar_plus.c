/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:36:57 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/19 04:13:43 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putchar_plus(int c, int cc)
{
	static int		si;

	if (cc == 1)
	{
		write(1, &c, 1);
		si++;
	}
	else if (cc == -1)
		si = 0;
	return (si);
}