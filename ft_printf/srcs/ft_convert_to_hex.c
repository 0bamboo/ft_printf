/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:37:21 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:35:22 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void				ft_converttohex(char **addr, unsigned int nbr, int c)
{
	char			*base[2];
	char			tab[100];
	int				i;
	int				j;

	base[0] = "0123456789abcdef";
	base[1] = "0123456789ABCDEF";
	i = 0;
	j = 0;
	if (!nbr)
		addr[0][j++] = '0';
	else
	{
		while (nbr)
		{
			tab[i++] = base[c][nbr % 16];
			nbr /= 16;
		}
		while (--i >= 0)
			addr[0][j++] = tab[i];
	}
	addr[0][j] = '\0';
}

char				*ft_fix_precision_4x(t_var *index, char *s)
{
	char				*addr;
	int					i;

	i = 0;
	if (!(addr = (char*)malloc(index->precision_val + 1)))
		return (NULL);
	while (i < index->precision_val - ft_strlen(s))
		addr[i++] = 48;
	while (*s)
		addr[i++] = *s++;
	addr[i] = '\0';
	return (addr);
}

char				*ft_fixandconvert_to_hex(t_var *index, int c)
{
	unsigned int			nbr;
	char					*addr;
	char					*tmp;

	nbr = *((unsigned int*)index->ptr);
	if (!(addr = (char*)malloc(20)))
		return (NULL);
	if (!nbr && index->precision_sym && !index->precision_val)
		*addr = '\0';
	else
		ft_converttohex(&addr, nbr, c);
	if (index->precision_val > ft_strlen(addr))
	{
		tmp = addr;
		addr = ft_fix_precision_4x(index, addr);
		free(tmp);
	}
	return (addr);
}
