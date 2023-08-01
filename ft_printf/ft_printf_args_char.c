/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:26:58 by jucalder          #+#    #+#             */
/*   Updated: 2023/06/23 19:27:12 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_args_char(va_list args, int *count)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	(*count)++;
	return (0);
}
