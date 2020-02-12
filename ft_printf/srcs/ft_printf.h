/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 03:37:06 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:34:28 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef	struct		s_var
{
	int				flags[2];
	int				min_field_width;
	int				precision_val;
	int				precision_sym;
	void			*ptr;
}					t_var;

int					ft_putchar_plus(int c, int cc);
void				ft_print_int(t_var *index);
void				ft_print_char(t_var *index);
void				ft_print_hex(t_var *index, int c);
void				ft_print_u_int(t_var *index);
void				ft_print_addr(t_var *index);
void				ft_print_string(t_var *index);
void				ft_print_percent(t_var *index);
int					ft_atoi(const char *str);
int					ft_strlen(char *str);
char				*ft_fixandconvert_to_hex(t_var *index, int c);

#endif
