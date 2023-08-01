/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:29:39 by jucalder          #+#    #+#             */
/*   Updated: 2023/06/23 19:29:40 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_args_int(va_list args, int *count)
{
	int		i;
	char	*s;

	i = va_arg(args, int);
	s = ft_itoa(i);
	ft_write(s, count);
	free(s);
	return (0);
}
