/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 02:12:35 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:36:38 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_var
{
	int			flags[2];
	int			min_field_width;
	int			precision_val;
	int			precision_sym;
	void		*ptr;
}				t_var;

void			ft_print_int(t_var *index);
void			ft_print_char(t_var *index);
void			ft_print_hex(t_var *index, int c);
void			ft_print_u_int(t_var *index);
void			ft_print_addr(t_var *index);
void			ft_print_string(t_var *index);
void			ft_print_percent(t_var *index);
int				ft_putchar_plus(int c, int cc);
int				ft_check_conversions(t_var *index, int	ch);
int				ft_check_flags_width(const char *format,
				t_var *index, va_list args);
int				ft_check_precision(const char *format,
				t_var *index, va_list args);
int				ft_printf_2_(const char *format, va_list args);
int				ft_printf(const char *format, ...);
int				ft_atoi(const char *str);
char			*ft_fixandconvert_to_hex(t_var *index, int c);

#endif
