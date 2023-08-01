/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:28:02 by jucalder          #+#    #+#             */
/*   Updated: 2023/06/23 19:28:11 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_args_pointer(va_list args, int *count)
{
	void	*p;
	char	*s;

	p = va_arg(args, void *);
	s = ft_uiptox(p);
	if (p == NULL)
	{
		ft_write("(nil)", count);
		free(s);
		return (0);
	}
	ft_write(s, count);
	free(s);
	return (0);
}
