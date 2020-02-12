/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 02:39:46 by abdait-m          #+#    #+#             */
/*   Updated: 2020/01/24 15:36:48 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_conversions(t_var *index, int ch)
{
	if (index->min_field_width < 0)
	{
		index->min_field_width *= -1;
		index->flags[0] = 1;
	}
	if (ch == 'd' || ch == 'i' || ch == 'c' || ch == 'x' ||
	ch == 'X' || ch == 'u' || ch == 'p' || ch == 's' || ch == '%')
	{
		if (ch == 'd' || ch == 'i')
			ft_print_int(index);
		if (ch == 'c' || ch == '%')
			ft_print_char(index);
		if (ch == 'x')
			ft_print_hex(index, 0);
		if (ch == 'X')
			ft_print_hex(index, 1);
		if (ch == 'u')
			ft_print_u_int(index);
		if (ch == 'p')
			ft_print_addr(index);
		if (ch == 's')
			ft_print_string(index);
		return (1);
	}
	return (0);
}

int		ft_check_flags_width(const char *format, t_var *index, va_list args)
{
	const char		*tmp;

	tmp = format;
	index->flags[0] = 0;
	index->flags[1] = 0;
	index->min_field_width = 0;
	while (*format < 49 && *format != 46 && *format != 42)
	{
		if (*format == '-')
			index->flags[0] = 1;
		if (*format == '0')
			index->flags[1] = 1;
		format++;
	}
	if (*format == '*' || (*format >= 49 && *format <= 57))
	{
		if (*format == '*')
			index->min_field_width = va_arg(args, int);
		else
			index->min_field_width = ft_atoi(format);
		while (*format == '*' || (*format >= 48 && *format <= 57))
			format++;
	}
	return (format - tmp);
}

int		ft_check_precision(const char *format, t_var *index, va_list args)
{
	const char		*tmp;

	tmp = format;
	index->precision_val = 0;
	index->precision_sym = 0;
	if (*format == '.')
	{
		index->precision_sym = 1;
		format++;
		if (*format == '*')
			index->precision_val = va_arg(args, int);
		else if (*format >= 48 && *format <= 57)
			index->precision_val = ft_atoi(format);
		while (*format == '*' || (*format >= 48 && *format <= 57))
			format++;
	}
	if (index->precision_val < 0)
	{
		index->precision_val = 0;
		index->precision_sym = 0;
	}
	return (format - tmp);
}

int		ft_printf_2_(const char *format, va_list args)
{
	int					i_nt;
	unsigned int		u_int;
	t_var				index;
	const char			*tmp;

	tmp = format;
	format += ft_check_flags_width(format, &index, args);
	format += ft_check_precision(format, &index, args);
	if (*format == 'd' || *format == 'i' || *format == 'c' || *format == '%')
	{
		if (*format == '%')
			i_nt = 37;
		else
			i_nt = va_arg(args, int);
		index.ptr = &i_nt;
	}
	if (*format == 'u' || *format == 'x' || *format == 'X')
	{
		u_int = va_arg(args, unsigned long);
		index.ptr = &u_int;
	}
	if (*format == 'p' || *format == 's')
		index.ptr = va_arg(args, void*);
	format += ft_check_conversions(&index, *format);
	return (format - tmp);
}

int		ft_printf(const char *format, ...)
{
	va_list			args;

	va_start(args, format);
	ft_putchar_plus(0, -1);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format) == '%')
				ft_putchar_plus(*format++, 1);
			else
				format += ft_printf_2_(format, args);
		}
		else
			ft_putchar_plus(*format++, 1);
	}
	va_end(args);
	return (ft_putchar_plus(0, 0));
}
