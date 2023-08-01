/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:30:21 by jucalder          #+#    #+#             */
/*   Updated: 2023/06/23 19:30:23 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_args(va_list args, char c, int *count)
{
	if (c == 'c')
		ft_printf_args_char(args, count);
	else if (c == 's')
		ft_printf_args_string(args, count);
	else if (c == 'd' || c == 'i')
		ft_printf_args_int(args, count);
	else if (c == 'u')
		ft_printf_args_unint(args, count);
	else if (c == 'x')
		ft_printf_args_x(args, 'x', count);
	else if (c == 'X')
		ft_printf_args_x(args, 'X', count);
	else if (c == 'p')
		ft_printf_args_pointer(args, count);
	else if (c == '%')
	{
		(*count)++;
		write(1, "%", 1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_args(args, str[i], &count);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
