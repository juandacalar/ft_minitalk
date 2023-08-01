/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args_unint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:29:45 by jucalder          #+#    #+#             */
/*   Updated: 2023/06/23 19:29:47 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_args_unint(va_list args, int *count)
{
	unsigned int	i;
	char			*s;

	i = va_arg(args, unsigned int);
	s = ft_uitoa(i);
	ft_write(s, count);
	free(s);
	return (0);
}
