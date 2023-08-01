/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uiptox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:32:59 by jucalder          #+#    #+#             */
/*   Updated: 2023/06/23 19:33:01 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_convert_uiptox(uintptr_t n, char *s)
{
	int	len;

	len = ft_hexlen(n);
	s[len + 2] = '\0';
	while (n != 0)
	{
		s[len + 1] = "0123456789abcdef"[n % 16];
		n /= 16;
		len--;
	}
}

char	*ft_uiptox(void *ptr)
{
	uintptr_t	n;
	char		*s;

	n = (uintptr_t)ptr;
	s = (char *)malloc(sizeof(char) * (ft_hexlen(n) + 3));
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = 'x';
	ft_convert_uiptox(n, s);
	return (s);
}
